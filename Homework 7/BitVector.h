//
// Created by Miller Ridgeway on 2/19/2018.
//

#ifndef HOMEWORK3_BITVECTOR_H
#define HOMEWORK3_BITVECTOR_H


#include <cstdint>
#include "MyArray.h"

class BitVector{
public:
    int numBits;
    MyArray<uint8_t> *v;

    BitVector(int);
    ~BitVector();

    void fillBits();
    void clearBits();
    bool get(int bit);
    void set(int bit);
    void clear(int bit);
    int size();

private:
};

#endif //HOMEWORK3_BITVECTOR_H
