//
// Created by Miller Ridgeway on 3/5/2018.
//

#ifndef LAB16_CARROT_H
#define LAB16_CARROT_H

#include "ProduceItem.h"

class Carrot: public ProduceItem{
public:
    Carrot(double w, double p = 0.89);
    const double GetPrice();
    const char* GetDescription();
private:
    double price, weight;
    char* desc;
};

#endif //LAB16_CARROT_H
