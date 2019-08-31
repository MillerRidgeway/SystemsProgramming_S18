//
// Created by Miller Ridgeway on 3/5/2018.
//

#ifndef LAB16_BAGEL_H
#define LAB16_BAGEL_H

#include "GroceryItem.h"

class Bagel: public GroceryItem{
public:
    Bagel();
    const char* GetDescription();
    const double GetPrice();
private:
    double price;
    char * desc;
};

#endif //LAB16_BAGEL_H
