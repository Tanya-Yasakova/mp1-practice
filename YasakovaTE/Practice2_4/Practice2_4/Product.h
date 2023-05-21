#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    std::string code;
    std::string name;
    double price;

    Product(std::string code = "", std::string name = "", double price = 0) : code(code), name(name), price(price) {}
};

#endif
