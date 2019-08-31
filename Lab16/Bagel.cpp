//
// Created by Miller Ridgeway on 3/5/2018.
//

#include "Bagel.h"

Bagel::Bagel() {
    this->price = 1.20;
    this->desc = "Bagel";
}

const double Bagel::GetPrice() {
    return this->price;
}

const char* Bagel::GetDescription() {
    return this->desc;
}