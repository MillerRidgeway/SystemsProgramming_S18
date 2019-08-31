//
// Created by Miller Ridgeway on 2/14/2018.
//

#include <clocale>
#include <iostream>
#include "math.h"
#include "VoxelModel.h"

VoxelModel allocateModel(int nx, int ny, int nz){
    VoxelModel model;

    model.x = nx;
    model.y = ny;
    model.z = nz;
    model.map = new uint8_t[(nx*ny*nz) / 8];

    return model;

}

void clearModel(VoxelModel &model){
    for(int i = 0; i < ((model.x * model.y*model.z)/8); i++){
        model.map[i] = 0;
    }
}

void fillModel(VoxelModel &model){
    for(int i = 0; i < ((model.x * model.y*model.z)/8); i++){
        model.map[i] = 0xFF;
    }
}

void deleteModel(VoxelModel &model){
    model.x = 0;
    model.y = 0;
    model.z = 0;
    delete [] model.map;
    model.map = NULL;
}

int getIndex(VoxelModel &model, int x, int y, int z){
    return z + y*model.z + x*model.y*model.z;
}

void getXYZ(const VoxelModel& model, int index, int &x, int &y, int &z){
    z = index % model.z;
    y = ((index - z) % model.y) / model.z;
    x = ((index - z) % model.z) / (model.z*model.y);
}

int getByteNumber(int index){
    return index/8;
}

uint8_t getBitNumber(int index){
    return index % 8;
}

//Return true if the bit for x, y, z is 1, and false if it's 0.
bool getBit(VoxelModel &model, int x, int y, int z){
    if(x < 0 || x >= model.x || y < 0 || y >= model.y || z < 0 || z >= model.z)
    {
        return false;
    }

    int index = getIndex(model,x, y, z);
    uint8_t mask =  (uint8_t) 1 <<  getBitNumber(index);
    return bool (mask & model.map[getByteNumber(index)]) != 0;
}

void setBit(VoxelModel &model, int x, int y, int z){
    int index = getIndex(model,x,y,z);
    uint8_t mask = (uint8_t) 1 <<  getBitNumber(index);
    model.map[getByteNumber(index)] = mask | model.map[getByteNumber(index)];
}

void clearBit(VoxelModel &model, int x, int y, int z){
    int index = getIndex(model,x,y,z);
    uint8_t temp = ~0;
    uint8_t mask = (uint8_t) 1 <<  getBitNumber(index);
    uint8_t result = mask ^ temp;
    model.map[getByteNumber(index)] = result & model.map[getByteNumber(index)];
}

void toggleBit(VoxelModel &model, int x, int y, int z){
    int index = getIndex(model,x,y,z);
    uint8_t mask = (uint8_t) 1 <<  getBitNumber(index);
    model.map[getByteNumber(index)] = mask ^ model.map[getByteNumber(index)];
}

void addSphere(VoxelModel &model, int cx, int cy, int cz, float r) {
    for (int x = 0; x < model.x; x++) {
        for (int y = 0; y < model.y; y++) {
            for (int z = 0; z < model.z; z++) {
                if(pow((x-cx),2) + pow((y-cy),2) + pow((z-cz),2) < pow(r,2)){
                    setBit(model, x,y,z);
                }
            }
        }
    }
}
void subtractSphere(VoxelModel &model, int cx, int cy, int cz, float r){
    for (int x = 0; x < model.x; x++) {
        for (int y = 0; y < model.y; y++) {
            for (int z = 0; z < model.z; z++) {
                if(pow((x-cx),2) + pow((y-cy),2) + pow((z-cz),2) < pow(r,2)){
                    clearBit(model, x,y,z);
                }
            }
        }
    }
}

void toggleSphere(VoxelModel &model, int cx, int cy, int cz, float r){
    for (int x = 0; x < model.x; x++) {
        for (int y = 0; y < model.y; y++) {
            for (int z = 0; z < model.z; z++) {
                if(pow((x-cx),2) + pow((y-cy),2) + pow((z-cz),2) < r^2){
                    toggleBit(model, x,y,z);
                }
            }
        }
    }
}