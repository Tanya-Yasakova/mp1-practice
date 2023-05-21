#ifndef ITEM_H
#define ITEM_H

#include "Product.h"

class Item {
public:
    Product product;
    int quantity;
    double sum;

    Item(Product product = Product(), int quantity = 0) : product(product), quantity(quantity), sum(product.price* quantity) {}
};

#endif

