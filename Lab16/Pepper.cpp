//
// Created by Miller Ridgeway on 3/5/2018.
//

#include "Pepper.h"

Pepper::Pepper(double w, double p): ProduceItem(w,p) {
    this->weight = w;
    this->price = p;
    this->desc = "Pepper";
}

const double Pepper::GetPrice() {
    return this->price * this->weight;
}

const char* Pepper::GetDescription() {
    return this->desc;
}