//
//  surfaceExtraction.cpp
//  Homework3
//
//  Created by Ben Jones on 1/6/17.
//  Copyright © 2017 Ben Jones. All rights reserved.
//

#include <iostream>
#include "surfaceExtraction.hpp"

void writeTriangle(FILE * f, Triangle t1){
    uint16_t tail = 0;

    fwrite(t1.normal, sizeof(float), 3, f);
    fwrite(t1.v1, sizeof(float), 3 , f);
    fwrite(t1.v2, sizeof(float), 3 , f);
    fwrite(t1.v3, sizeof(float), 3 , f);
    fwrite(&tail, sizeof(uint16_t), 1, f);
}

void writeSTL(uint64_t model, const char* fileName){
    std::cout << "Begin write" << std::endl;

    FILE * file = fopen(fileName, "wb");

    //Header (80 bytes of 0)
    uint8_t header[80] = {0};
    fwrite(&header,sizeof(uint8_t), 80, file);

    uint32_t triCount = 0;
    fwrite(&triCount, sizeof(uint32_t), 1, file);

    Triangle t1, t2;

    //Triangle Writing
    for(int x = 0; x < 4; x++){
        for(int y = 0; y < 4; y++) {
            for(int z = 0; z < 4; z++) {
                if (getBit(model, x, y, z)) {
                    if (!getBit(model, x - 1, y, z)) { //Negative X
                        extractFace(x, y, z, NX, t1, t2);

                        writeTriangle(file, t1);
                        writeTriangle(file, t2);

                        triCount += 2;
                        std::cout << "Writing Negative X" << std::endl;
                    }
                    if (!getBit(model, x + 1, y, z)) { //Positive X
                        extractFace(x, y, z, PX, t1, t2);

                        writeTriangle(file, t1);
                        writeTriangle(file, t2);

                        triCount += 2;
                        std::cout << "Writing Positive X" << std::endl;
                    }
                    if (!getBit(model, x, y - 1, z)) { //Negative Y
                        extractFace(x, y, z, NY, t1, t2);

                        writeTriangle(file, t1);
                        writeTriangle(file, t2);

                        triCount += 2;
                         std::cout << "Writing Negative Y" << std::endl;
                    }
                    if (!getBit(model, x, y + 1, z)) { //Positive Y
                        extractFace(x, y, z, PY, t1, t2);

                        writeTriangle(file, t1);
                        writeTriangle(file, t2);

                        triCount += 2;
                        std::cout << "Writing Positive Y" << std::endl;
                    }
                    if (!getBit(model, x, y, z - 1)) { //Negative Z
                        extractFace(x, y, z, NZ, t1, t2);

                        writeTriangle(file, t1);
                        writeTriangle(file, t2);

                        triCount += 2;
                        std::cout << "Writing Negative Z" << std::endl;
                    }
                    if (!getBit(model, x, y, z + 1)) { //Positive Z
                        extractFace(x, y, z, PZ, t1, t2);

                        writeTriangle(file, t1);
                        writeTriangle(file, t2);

                        triCount += 2;
                        std::cout << "Writing Positive Z" << std::endl;
                    }
                }
            }
        }
    }

    fseek(file, 80, SEEK_SET); //Seek to 80 bytes from the start
    fwrite(&triCount, sizeof(uint32_t), 1, file); //Write triCount

    fclose(file);

    std::cout << "End write, success!" << std::endl;
}

inline void fillPlane(int a1, int a2, int b1, int b2, int c, int cInd, Triangle& t1, Triangle& t2){
    t1.v1[cInd] = c;
    t2.v1[cInd] = c;
    t1.v2[cInd] = c;
    t2.v2[cInd] = c;
    t1.v3[cInd] = c;
    t2.v3[cInd] = c;
    int aInd = (cInd +1) % 3;
    int bInd = (cInd +2) % 3;

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

void extractFace(int x, int y, int z, FaceType face, Triangle& t1, Triangle& t2){
    for(int i= 0; i < 3; i++){
        t1.normal[i] = 0;
        t2.normal[i] = 0;
    }
    switch(face){
        case NX:
            t1.normal[0] = -1;
            t2.normal[0] = -1;
            fillPlane(y + 1, y, z, z+1, x, 0, t1, t2);
            break;
        case NY:
            t1.normal[1] = -1;
            t2.normal[1] = -1;
            fillPlane(z + 1, z, x, x+1, y, 1, t1, t2);
            break;
        case NZ:
            t1.normal[2] = -1;
            t2.normal[2] = -1;
            fillPlane(x + 1, x, y, y + 1, z, 2, t1, t2);
            break;
        case PX:
            t1.normal[0] = 1;
            t2.normal[0] = 1;
            fillPlane(y, y + 1, z, z +1, x + 1, 0, t1, t2);
            break;
        case PY:
            t1.normal[1] = 1;
            t2.normal[1] = 1;
            fillPlane(z, z + 1, x, x + 1, y + 1, 1, t1, t2);
            break;
        case PZ:
            t1.normal[2] = 1;
            t2.normal[2] = 1;
            fillPlane(x, x +1, y, y + 1, z + 1, 2, t1, t2);
            break;
    }
}
