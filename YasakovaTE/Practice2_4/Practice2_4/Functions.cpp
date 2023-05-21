#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"

const int INITIAL_CAPACITY = 100;

Product* loadProducts(std::string filename, int& numProducts, int& capacity) {
    capacity = INITIAL_CAPACITY;
    Product* products = new Product[capacity];
    numProducts = 0;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            size_t pos1 = line.find(';');
            size_t pos2 = line.find(';', pos1 + 1);
            std::string code = line.substr(0, pos1);
            std::string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
            double price = std::stod(line.substr(pos2 + 1));
            if (numProducts == capacity) {
                capacity *= 2;
                Product* newProducts = new Product[capacity];
                for (int i = 0; i < numProducts; i++) {
                    newProducts[i] = products[i];
                }
                delete[] products;
                products = newProducts;
            }
            products[numProducts] = Product(code, name, price);
            numProducts++;
        }
        file.close();
    }
    return products;
}

void searchProducts(Product* products, int numProducts) {
    std::cout << "Enter search query: ";
    std::string query;
    getline(std::cin, query);

    std::cout << "Search results: " << std::endl;
    for (int i = 0; i < numProducts; i++) {
        if (products[i].name.find(query) != std::string::npos) {
            std::cout << products[i].name << " (" << products[i].code << "): " << products[i].price << std::endl;
        }
    }
}

void printProductsTable(Product* products, int numProducts) {
    std::cout << "Code       Name                 Price     " << std::endl;
    for (int i = 0; i < numProducts; i++) {
        std::cout << products[i].code;
        for (int j = products[i].code.length(); j < 10; j++) {
            std::cout << ' ';
        }
        std::cout << products[i].name;
        for (int j = products[i].name.length(); j < 20; j++) {
            std::cout << ' ';
        }
        std::cout << products[i].price << std::endl;
    }
}