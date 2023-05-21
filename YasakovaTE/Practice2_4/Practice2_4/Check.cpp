#include "Check.h"

void Check::addItem(Product product, int quantity) {
    if (numItems == capacity) {
        capacity *= 2;
        Item* newItems = new Item[capacity];
        for (int i = 0; i < numItems; i++) {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
    }
    items[numItems] = Item(product, quantity);
    numItems++;
}

void Check::removeItem(int index) {
    if (index >= 0 && index < numItems) {
        for (int i = index; i < numItems - 1; i++) {
            items[i] = items[i + 1];
        }
        numItems--;
    }
}

void Check::updateItem(int index, int quantity) {
    if (index >= 0 && index < numItems) {
        items[index].quantity = quantity;
        items[index].sum = items[index].product.price * quantity;
    }
}

Product Check::findProduct(std::string code) {
    for (int i = 0; i < numItems; i++) {
        if (items[i].product.code == code) {
            return items[i].product;
        }
    }
    return Product();
}

double Check::totalSum() {
    double sum = 0;
    for (int i = 0; i < numItems; i++) {
        sum += items[i].sum;
    }
    return sum;
}