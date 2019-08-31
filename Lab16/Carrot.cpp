//
// Created by Miller Ridgeway on 3/5/2018.
//

#include "Carrot.h"

Carrot::Carrot(double w, double p): ProduceItem(w,p) {
    this->weight = w;
    this->price = p;
    this->desc = "Carrot";
}

const char* Carrot::GetDescription() {
    return this->desc;
}

const double Carrot::GetPrice() {
    return this->price * this->weight;
}