//Worked with James

#include <iostream>
#include <inttypes.h>
#include "VoxelShape.h"


int main(){
    //Testing
    int size = 500;
    VoxelShape model(size,size,size);

    model.clearModel();
    model.addSphere(size/2,size/2,size/2,10);

    writeSTL(model,"Tester.stl");

    return 0;
}