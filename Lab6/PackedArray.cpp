#include <iostream>

#include "PackedArray.h"

// Create the array; initialize memory
PackedArray CreateArray(int aSize)
{
    uint64_t * arr = new uint64_t [aSize];

    PackedArray p;
    p.rows = arr;
    p.numRows = aSize;

    return p;
}

// Frees memory for the array
void FreeArray(PackedArray &array)
{
    delete [] array.rows;
}

// Sets all entries in the array to value parameter
void FillArray(PackedArray &array, uint64_t value)
{
    if(value > 3){
        std::cout << "Value too large" << std::endl;
    }
    else{
        for(int i = 0; i < array.numRows; i++){
            for(int j = 0; j < 32; j++){
                SetEntry(array, i, j, value);
            }
        }
    }

}

// Clears all entries to 0 in the array
void ClearArray(PackedArray &array)
{
    for(int i = 0; i < array.numRows; i++){
        array.rows[i] = 0;
    }
}

// Get the value of the entry at the specified row and col.
// If row or col are outside of the range for this PackedArray,
// returns 0.
int GetEntry(const PackedArray &array, int row, int col)
{
    //Error checking
    if(col > 31 || col < 0 || row > array.numRows || row < 0){
        //std::cout << "GetEntry location error" << std::endl;
        return 0;
    }
    else{
        uint64_t entry = array.rows[row] >> (col * 2);
        return entry & 0x3;

    }
}

// Sets entry in the location row, col to the specified value.
// If row or col are outside of the range for this PackedArray,
// function has no effect.
void SetEntry(PackedArray &array, int row, int col, uint64_t value)
{
    if(col > 31 ||  col < 0  || row > array.numRows || row < 0){
        return;
    }
    else{
        //Toggle a mask to all 1's except for proper spot
        uint64_t flip = 0x3ull << (col * 2);
        uint64_t mask = (~0ull) ^ flip;
        //Clear proper spot to 0, then set
        array.rows[row] &= mask;
        array.rows[row] |= (value << (col*2));
    }
}

// Sum all the entries in the array
int SumEntries(const PackedArray &array)
{
    int sum = 0;
    for(int i = 0; i < array.numRows; i++){
        for(int j = 0; j < 32; j++){
            sum += GetEntry(array, i, j);
        }
    }
    return sum;
}