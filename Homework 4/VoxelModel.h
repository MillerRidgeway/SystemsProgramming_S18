//
// Created by Miller Ridgeway on 2/14/2018.
//

#ifndef HOMEWORK3_VOXELMODEL_H
#define HOMEWORK3_VOXELMODEL_H

#include <inttypes.h>

struct VoxelModel{
    int x, y , z;
    uint8_t *map;
};

VoxelModel allocateModel(int nx, int ny, int nz);
void deleteModel(VoxelModel &model);

void clearModel(VoxelModel &model);
void fillModel(VoxelModel &model);

int getIndex(VoxelModel &model ,int x, int y, int z);
void getXYZ(const VoxelModel& model, int index, int &x, int &y, int &z);
int getByteNumber(int index);
uint8_t getBitNumber(int index);

bool getBit(VoxelModel &model, int x, int y, int z);

void setBit(VoxelModel &model, int x, int y, int z);
void clearBit(VoxelModel &model, int x, int y, int z);
void toggleBit(VoxelModel &model, int x, int y, int z);

void addSphere(VoxelModel &model, int cx, int cy, int cz, float r);
void subtractSphere(VoxelModel &model, int cx, int cy, int cz, float r);
void toggleSphere(VoxelModel &model, int cx, int cy, int cz, float r);

#endif //HOMEWORK3_VOXELMODEL_H
