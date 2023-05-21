#ifndef CHECK_H
#define CHECK_H

#include <string>
#include "Item.h"

const int INITIAL_CAPACITY = 100;

class Check {
public:
    int number;
    std::string date;
    Item* items;
    int numItems;
    int capacity;

    Check(int number = 0, std::string date = "") : number(number), date(date), numItems(0), capacity(INITIAL_CAPACITY) {
        items = new Item[capacity];
    }

    ~Check() {
        delete[] items;
    }

    void addItem(Product product, int quantity);
    void removeItem(int index);
    void updateItem(int index, int quantity);
    Product findProduct(std::string code);
    double totalSum();
};

#endif

