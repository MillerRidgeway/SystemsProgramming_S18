//
// Created by Miller Ridgeway on 2/20/2018.
//

#include "VoxelShape.h"
#include "math.h"
#include <iostream>
#include "SharedQueue.h"
#include <mutex>

VoxelShape::VoxelShape(int x, int y, int z) {
    map = new BitVector(x * y * z);
    this->x = x;
    this->y = y;
    this->z = z;
}

VoxelShape::~VoxelShape() {
    delete map;
}

void VoxelShape::fillModel() {
    map->fillBits();
}

void VoxelShape::clearModel() {
    map->clearBits();
}

int VoxelShape::getIndex(int ix, int iy, int iz) {
    return iz + iy * z + ix * y * z;
}

bool VoxelShape::getVoxel(int ix, int iy, int iz) {
    if (ix < 0 || ix >= x || iy < 0 || iy >= y || iz < 0 || iz >= z) {
        return false;
    }

    return map->get(getIndex(ix, iy, iz));
}

void VoxelShape::setVoxel(int ix, int iy, int iz) {
    map->set(getIndex(ix, iy, iz));
}

void VoxelShape::clearVoxel(int ix, int iy, int iz) {
    map->clear(getIndex(ix, iy, iz));
}

void VoxelShape::addSphere(int cx, int cy, int cz, float r) {
    for (int x = 0; x < this->x; x++) {
        for (int y = 0; y < this->y; y++) {
            for (int z = 0; z < this->z; z++) {
                if (pow((x - cx), 2) + pow((y - cy), 2) + pow((z - cz), 2) < pow(r, 2)) {
                    map->set(getIndex(x, y, z));
                }
            }
        }
    }
}

void VoxelShape::toggleSphere(int cx, int cy, int cz, float r) {
    for (int x = 0; x < this->x; x++) {
        for (int y = 0; y < this->y; y++) {
            for (int z = 0; z < this->z; z++) {
                if (pow((x - cx), 2) + pow((y - cy), 2) + pow((z - cz), 2) < pow(r, 2)) {
                    if (map->get(getIndex(x, y, z))) {
                        map->clear(getIndex(x, y, z));
                    } else {
                        map->set(getIndex(x, y, z));
                    }
                }
            }
        }
    }
}

void VoxelShape::subSphere(int cx, int cy, int cz, float r) {
    for (int x = 0; x < this->x; x++) {
        for (int y = 0; y < this->y; y++) {
            for (int z = 0; z < this->z; z++) {
                if (pow((x - cx), 2) + pow((y - cy), 2) + pow((z - cz), 2) < pow(r, 2)) {
                    map->clear(getIndex(x, y, z));
                }
            }
        }
    }
}

//File Writing

enum FaceType {
    NX,
    NY,
    NZ,
    PX,
    PY,
    PZ
};

struct Triangle {
    float normal[3];
    float v1[3];
    float v2[3];
    float v3[3];
};

void writeTriangle(FILE *f, Triangle t1) {
    uint16_t tail = 0;

    fwrite(t1.normal, sizeof(float), 3, f);
    fwrite(t1.v1, sizeof(float), 3, f);
    fwrite(t1.v2, sizeof(float), 3, f);
    fwrite(t1.v3, sizeof(float), 3, f);
    fwrite(&tail, sizeof(uint16_t), 1, f);
}

inline void fillPlane(int a1, int a2, int b1, int b2, int c, int cInd, Triangle &t1, Triangle &t2) {
    t1.v1[cInd] = c;
    t2.v1[cInd] = c;
    t1.v2[cInd] = c;
    t2.v2[cInd] = c;
    t1.v3[cInd] = c;
    t2.v3[cInd] = c;
    int aInd = (cInd + 1) % 3;
    int bInd = (cInd + 2) % 3;

    t1.v1[aInd] = a1;
    t1.v2[aInd] = a2;
    t1.v3[aInd] = a2;

    t2.v1[aInd] = a1;
    t2.v2[aInd] = a2;
    t2.v3[aInd] = a1;

    t1.v1[bInd] = b1;
    t1.v2[bInd] = b1;
    t1.v3[bInd] = b2;

    t2.v1[bInd] = b1;
    t2.v2[bInd] = b2;
    t2.v3[bInd] = b2;

}

void extractFace(int x, int y, int z, FaceType face, Triangle &t1, Triangle &t2) {
    for (int i = 0; i < 3; i++) {
        t1.normal[i] = 0;
        t2.normal[i] = 0;
    }
    switch (face) {
        case NX:
            t1.normal[0] = -1;
            t2.normal[0] = -1;
            fillPlane(y + 1, y, z, z + 1, x, 0, t1, t2);
            break;
        case NY:
            t1.normal[1] = -1;
            t2.normal[1] = -1;
            fillPlane(z + 1, z, x, x + 1, y, 1, t1, t2);
            break;
        case NZ:
            t1.normal[2] = -1;
            t2.normal[2] = -1;
            fillPlane(x + 1, x, y, y + 1, z, 2, t1, t2);
            break;
        case PX:
            t1.normal[0] = 1;
            t2.normal[0] = 1;
            fillPlane(y, y + 1, z, z + 1, x + 1, 0, t1, t2);
            break;
        case PY:
            t1.normal[1] = 1;
            t2.normal[1] = 1;
            fillPlane(z, z + 1, x, x + 1, y + 1, 1, t1, t2);
            break;
        case PZ:
            t1.normal[2] = 1;
            t2.normal[2] = 1;
            fillPlane(x, x + 1, y, y + 1, z + 1, 2, t1, t2);
            break;
    }
}

struct Chunk {
    int x, y;
};

void writeHelp(VoxelShape &model, int x, int y, MyArray<Triangle> &content, std::mutex &m) {
    Triangle t1, t2;
    MyArray<Triangle> temp(20);

    for (int z = 0; z < model.z; z++) {
        if (model.getVoxel(x, y, z)) {
            if (!model.getVoxel(x - 1, y, z)) { //Negative X
                extractFace(x, y, z, NX, t1, t2);

                temp.PushBack(t1);
                temp.PushBack(t2);
            }
            if (!model.getVoxel(x + 1, y, z)) { //Positive X
                extractFace(x, y, z, PX, t1, t2);

                temp.PushBack(t1);
                temp.PushBack(t2);
            }
            if (!model.getVoxel(x, y - 1, z)) { //Negative Y
                extractFace(x, y, z, NY, t1, t2);

                temp.PushBack(t1);
                temp.PushBack(t2);
            }
            if (!model.getVoxel(x, y + 1, z)) { //Positive  Y
                extractFace(x, y, z, PY, t1, t2);

                temp.PushBack(t1);
                temp.PushBack(t2);
            }
            if (!model.getVoxel(x, y, z - 1)) { //Negative Z
                extractFace(x, y, z, NZ, t1, t2);

                temp.PushBack(t1);
                temp.PushBack(t2);
            }
            if (!model.getVoxel(x, y, z + 1)) { //Positive X
                extractFace(x, y, z, PZ, t1, t2);

                temp.PushBack(t1);
                temp.PushBack(t2);
            }
        }
    }

    m.lock();
    for(int i = 0; i < temp.getSize(); i++){
        content.PushBack(temp.get(i));
    }
    m.unlock();
}//writeHelp

void extractWork(VoxelShape &model, MyArray<Triangle> *content, SharedQueue<Chunk> *w, std::mutex &m) {
    Chunk c;
    while (true) {
        while (w->Remove(c) == false) {
            std::this_thread::yield();
        }

        if (c.x == -1 && c.y == -1)
            break;

        writeHelp(model,c.x,c.y,*content, m);
    }
}//extractWork

void writeSTL(VoxelShape &model, const char *fileName) {
    std::cout << "Begin write" << std::endl;

    SharedQueue<Chunk> work;
    std::mutex m1;

    //Thread declaring
    int numThreads = 1;
    std::thread **threads;
    threads = new std::thread *[numThreads];
    MyArray<Triangle> *tris = new MyArray<Triangle>(20);

    for (int i = 0; i < numThreads; i++) {
        threads[i] = new std::thread(extractWork, std::ref(model), tris, &work, std::ref(m1));
    }

    //Add work to SharedQueue
    for (int x = 0; x < model.x; x++) {
        for (int y = 0; y < model.y; y++) {
            work.Add({x, y});
        }
    }

    for(int i = 0; i < numThreads; i++){
        work.Add({-1,-1});
    }

    for (int i = 0; i < numThreads; i++) {
        threads[i]->join();
        delete threads[i];
    }

    delete[] threads;

    //Writing
    FILE *file = fopen(fileName, "wb");

    //Header (80 bytes of 0)
    uint8_t header[80] = {0};
    fwrite(&header, sizeof(uint8_t), 80, file);

    uint32_t triCount = 0;
    fwrite(&triCount, sizeof(uint32_t), 1, file);

    //Write all triangles
    for (int i = 0; i < triCount; i++) {
        uint16_t tail = 0;
        Triangle t1 = tris->PopBack();

        fwrite(t1.normal, sizeof(float), 3, file);
        fwrite(t1.v1, sizeof(float), 3, file);
        fwrite(t1.v2, sizeof(float), 3, file);
        fwrite(t1.v3, sizeof(float), 3, file);
        fwrite(&tail, sizeof(uint16_t), 1, file);
    }

    triCount = tris->getSize();

    fseek(file, 80, SEEK_SET); //Seek to 80 bytes from the start
    fwrite(&triCount, sizeof(uint32_t), 1, file); //Write triCount

    fclose(file);

    std::cout << "End write, success!" << std::endl;
}


