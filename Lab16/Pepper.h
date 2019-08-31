//
// Created by Miller Ridgeway on 3/5/2018.
//

#ifndef LAB16_PEPPER_H
#define LAB16_PEPPER_H

#include "ProduceItem.h"

class Pepper: public ProduceItem{
public:
    Pepper(double w, double  p = 1);
    const char* GetDescription();
    const double GetPrice();
private:
    double price, weight;
    char * desc;
};

#endif //LAB16_PEPPER_H
