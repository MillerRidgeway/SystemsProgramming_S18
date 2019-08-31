//
// Created by Miller Ridgeway on 3/5/2018.
//

#ifndef LAB16_PRODUCEITEM_H
#define LAB16_PRODUCEITEM_H

#include "GroceryItem.h"

class ProduceItem: public GroceryItem{
public:
    ProduceItem(double, double);
    virtual const double GetPrice() = 0;
    virtual const char* GetDescription() = 0;
private:
    double price, weight;
    char* desc;
};
#endif //LAB16_PRODUCEITEM_H
