//Worked with James

#include <iostream>
#include <inttypes.h>
#include "surfaceExtraction.hpp"

uint8_t getIndex(int x, int y, int z){
    uint8_t result;
    result = 16*x + 4*y + z;
    return result;
}

uint64_t getX(uint8_t index){
    if(index < 16)
    {
        return 0;
    }
    else if(index < 32){
        return 1;
    }
    else if (index < 48){
        return 2;
    }
    else{
        return 3;
    }
}

uint64_t getY(uint8_t index){
    if(index - getX(index)*16 < 4){
        return 0;
    }
    else if(index - getX(index)*16 < 8){
        return 1;
    }
    else if(index - getX(index)*16 < 11){
        return 2;
    }
    else{
        return 3;
    }
}

uint64_t getZ(uint8_t index){
    return index % 4;
}
//All 0's
uint64_t emptyModel(){
    return 0;
}

//All 1's
uint64_t fullModel(){
    return ~0;
}

//Return true if the bit for x, y, z is 1, and false if it's 0.
bool getBit(uint64_t model, int x, int y, int z){
    if(x < 0 || x > 3 || y < 0 || y > 3 || z < 0 || z > 3){
        return false;
    }
    uint64_t  mask = 1ULL << (uint64_t) getIndex(x,y,z);
    return bool (mask & model) != 0;
}

uint64_t setBit(uint64_t model, int x, int y, int z){
    uint64_t mask = 1ULL << (uint64_t) getIndex(x,y,z);
    return mask | model;
}

uint64_t clearBit(uint64_t model, int x, int y, int z){
    uint64_t temp = ~0;
    uint64_t mask = 1ULL << (uint64_t) getIndex(x,y,z);
    uint64_t result = mask ^ temp;
    return result & model;
}

uint64_t toggleBit(uint64_t model, int x, int y, int z){
    uint64_t mask =  1ULL << (uint64_t) getIndex(x,y,z);
    return mask ^ model;
}

int main(){
    //Voxel Testing
    uint64_t fullVoxel = fullModel();
    uint64_t emptyVoxel = emptyModel();
//
//    //Index Testing
//    for(int i = 0; i <= 63; i++){
//        printf("%" PRId64 "\n", getIndex(getX(i), getY(i), getZ(i)));
//    }
//
    //Get Bit
//    std::cout << "Get Bit (expected 1): " << std::boolalpha << getBit(fullVoxel,5,0,3) << std::endl;
//
//    //Set bit
//    emptyVoxel = setBit(emptyVoxel,0,1,1);
//    std::cout << "Set bit (expected 1): " << getBit(emptyVoxel,0,1,1) << std::endl;
//
//    //Clear Bit
//    emptyVoxel = clearBit(emptyVoxel,0,1,1);
//    std::cout << "Clear bit (expected 0): " << getBit(emptyVoxel,0,1,1) << std::endl;
//
//    //Toggle Bit
//    emptyVoxel = toggleBit(emptyVoxel,0,1,1);
//    std::cout << "Toggle bit (expected 1): " << getBit(emptyVoxel,0,1,1) << std::endl;
//
//    //Hex
//    std::cout <<  "Hex value of Voxel: " << std::hex << emptyVoxel << std::endl;

    //STL Output
    uint64_t tester = emptyModel();
    tester = setBit(tester, 1,0,0);
    tester = setBit(tester, 0,2,3);
    tester = setBit(tester, 0,0,0);
    tester = setBit(tester, 3,3,3);
    tester = setBit(tester, 1,2,3);
    tester = setBit(tester, 1,0,1);
    tester = setBit(tester, 2,0,0);
    tester = setBit(tester, 0,3,2);
    tester = setBit(tester, 1,1,1);


    writeSTL(tester, "Tester.stl");
}