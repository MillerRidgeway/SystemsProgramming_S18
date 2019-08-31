//
// Created by Miller Ridgeway on 2/19/2018.
//

#include "BitVector.h"
#include "MyArray.h"

BitVector::BitVector(int bits){
    numBits = bits;
    v = new MyArray<uint8_t>(bits / 8);
}

BitVector::~BitVector() {
    delete v;
}

void BitVector::clearBits() {
    for(int i = 0; i < numBits / 8; i++){
        v->set(0,i);
    }
}

void BitVector::fillBits() {
    for(int i = 0; i < numBits / 8; i++){
        v->set(0xFF, i);
    }
}

bool BitVector::get(int bit) {
    if(bit < 0 || bit > numBits){
        return false;
    }
    uint8_t mask =  (uint8_t) 1 << bit % 8;
    return bool (mask & v->get(bit / 8)) != 0;
}

void BitVector::set(int bit) {
    uint8_t mask = (uint8_t) 1 <<  bit % 8;
    v->set(mask | v->get(bit / 8), bit / 8);
}

void BitVector::clear(int bit){
    uint8_t temp = ~0;
    uint8_t mask = (uint8_t) 1 <<  bit % 8;
    uint8_t result = mask ^ temp;
    v->set(result & v->get(bit / 8), bit / 8);
}

int BitVector::size() {
    return numBits;
}

