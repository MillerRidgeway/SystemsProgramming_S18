#include <iostream>
#include <inttypes.h>
#include "VoxelShape.h"
#include "MyArray.h"
#include <chrono>
#include <ctime>


int main(){
    //Testing

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int size = 25;
    VoxelShape model(size,size,size);

    //model.fillModel();
    model.setVoxel(0,0,1);
    model.setVoxel(1,0,0);
    model.setVoxel(1,2,0);
    model.setVoxel(0,2,0);
    model.setVoxel(0,0,3);

    writeSTL(model,"Tester.stl");

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";

    return 0;
}