//
// Created by Miller Ridgeway on 2/19/2018.
//

#include "BitVector.h"

BitVector::BitVector(int bits){
    numBits = bits;
    v = new uint8_t[bits / 8];
}

BitVector::~BitVector() {
    delete [] v;
}

void BitVector::clearBits() {
    for(int i = 0; i < numBits / 8; i++){
        v[i] = 0;
    }
}

void BitVector::fillBits() {
    for(int i = 0; i < numBits / 8; i++){
        v[i] = 0xFF;
    }
}

bool BitVector::get(int bit) {
    if(bit < 0 || bit > numBits){
        return false;
    }
    uint8_t mask =  (uint8_t) 1 << bit % 8;
    return bool (mask & v[bit / 8]) != 0;
}

void BitVector::set(int bit) {
    uint8_t mask = (uint8_t) 1 <<  bit % 8;
    v[bit / 8] = mask | v[bit / 8];
}

void BitVector::clear(int bit){
    uint8_t temp = ~0;
    uint8_t mask = (uint8_t) 1 <<  bit % 8;
    uint8_t result = mask ^ temp;
    v[bit / 8] = result & v[bit / 8];
}

int BitVector::size() {
    return numBits;
}

