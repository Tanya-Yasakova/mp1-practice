#include <iostream>
#include <fstream>
#include <string>
#include "Product.h"
#include "Check.h"
#include "Functions.h"
#include <ctime>


int main() {
    std::cout << "Enter the path to the file with product information: ";
    std::string filename;
    getline(std::cin, filename);
    int capacity;
    int numProducts;
    Product* products = loadProducts(filename, numProducts, capacity);

    std::time_t t = std::time(nullptr);
    std::tm now;
    localtime_s(&now, &t);
    char date[20];
    std::strftime(date, sizeof(date), "%d.%m.%Y %H:%M:%S", &now);
    Check check(1, date);

    bool done = false;
    while (!done) {
        std::cout << "Enter command (add/update/remove/total/search/print/quit): ";
        std::string command;
        getline(std::cin, command);
        if (command == "add") {
            std::cout << "Enter product name: ";
            std::string name;
            getline(std::cin, name);
            Product* product = nullptr;
            for (int i = 0; i < numProducts; i++) {
                if (products[i].name == name) {
                    product = &products[i];
                    break;
                }
            }
            if (product != nullptr) {
                std::cout << "Enter quantity: ";
                int quantity;
                std::cin >> quantity;
                check.addItem(*product, quantity);
                std::cin.ignore();
            }
            else {
                std::cout << "Product not found" << std::endl;
            }
        }
        else if (command == "update") {
            std::cout << "Enter product name: ";
            std::string name;
            getline(std::cin, name);
            int index = -1;
            for (int i = 0; i < check.numItems; i++) {
                if (check.items[i].product.name == name) {
                    index = i;
                    break;
                }
            }
            if (index != -1) {
                std::cout << "Enter new quantity: ";
                int quantity;
                std::cin >> quantity;
                check.updateItem(index, quantity);
                std::cin.ignore();
            }
            else {
                std::cout << "Product not found" << std::endl;
            }
        }
        else if (command == "remove") {
            std::cout << "Enter product name: ";
            std::string name;
            getline(std::cin, name);
            int index = -1;
            for (int i = 0; i < check.numItems; i++) {
                if (check.items[i].product.name == name) {
                    index = i;
                    break;
                }
            }
            if (index != -1) {
                std::cout << "Enter quantity to remove: ";
                int quantity;
                std::cin >> quantity;
                if (quantity >= check.items[index].quantity) {
                    check.removeItem(index);
                }
                else {
                    check.updateItem(index, check.items[index].quantity - quantity);
                }
                std::cin.ignore();
            }
            else {
                std::cout << "Product not found" << std::endl;
            }
        }
        else if (command == "total") {
            double totalSum = check.totalSum();
            std::cout << "Check date and time: " << check.date << std::endl;
            for (int i = 0; i < check.numItems; i++) {
                std::cout << check.items[i].product.name << ": " << check.items[i].quantity << " x " << check.items[i].product.price << " = " << check.items[i].sum << std::endl;
            }
            std::cout << "Total check amount: " << totalSum << std::endl;
        }
        else if (command == "search") {
            searchProducts(products, numProducts);
        }
        else if (command == "print") {
            printProductsTable(products, numProducts);
        }
        else if (command == "quit") {
            done = true;
        }
    }
    delete[] products;
    return 0;
}