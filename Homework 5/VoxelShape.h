//
// Created by Miller Ridgeway on 2/20/2018.
//

#ifndef HOMEWORK3_VOXELSHAPE_H
#define HOMEWORK3_VOXELSHAPE_H

#include "BitVector.h"

class VoxelShape{
public:
    int x, y ,z;
    BitVector *map;

    VoxelShape(int, int, int);
    ~VoxelShape();

    void fillModel();
    void clearModel();
    bool getVoxel(int, int, int);
    void setVoxel(int, int, int);
    void clearVoxel(int, int, int);
    void addSphere(int, int, int, float);
    void subSphere(int, int, int, float);
    void toggleSphere(int, int, int, float);

private:
    int getIndex(int, int, int);

};

void writeSTL(VoxelShape &model, const char* filename);

#endif //HOMEWORK3_VOXELSHAPE_H
