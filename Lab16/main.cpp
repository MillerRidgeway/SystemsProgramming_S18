#include <iostream>

#include "GroceryCart.h"
#include "Carrot.h"
#include "Bagel.h"
#include "Pepper.h"

int main(int argc, const char *argv[]) {
    GroceryCart c;
    c.AddItemToCart(new Carrot(2.0));
    c.AddItemToCart(new Pepper(2.0, 2.0));
    c.AddItemToCart(new Bagel());

    std::cout << c;
    return 0;
}
