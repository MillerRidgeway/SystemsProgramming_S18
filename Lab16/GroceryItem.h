//
// Created by Miller Ridgeway on 3/5/2018.
//

#ifndef LAB16_GROCERYITEM_H
#define LAB16_GROCERYITEM_H
class GroceryItem{
public:
    GroceryItem();
    virtual const double GetPrice() = 0;
    virtual const char* GetDescription() = 0;
private:
    double price, weight;
    char * desc;
};


#endif //LAB16_GROCERYITEM_H
