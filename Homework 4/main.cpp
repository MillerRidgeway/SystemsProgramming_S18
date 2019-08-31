//Worked with James

#include <iostream>
#include <inttypes.h>
#include "surfaceExtraction.hpp"
#include "VoxelModel.h"


int main(){
    //Testing
    int size = 200;
    VoxelModel tester = allocateModel(size,size,size);
    clearModel(tester);
    addSphere(tester, size/2, size/2, size/2, 10);
//    setBit(tester,10,10,10);
//    setBit(tester,75,60,1);
//    setBit(tester,90,80,70);
//    setBit(tester,50,50,50);
    writeSTL(tester, "Tester.stl");


//    for(int x = 0; x < size; x++){
//        for(int y = 0; y < size; y++){
//            for(int z = 0; z < size; z++){
//                std::cout << getBit(tester, x, y, z);
//            }
//        }
//    }

    deleteModel(tester);

    return 0;
}