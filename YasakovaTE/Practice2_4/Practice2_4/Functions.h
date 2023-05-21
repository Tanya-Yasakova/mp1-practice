#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include "Product.h"

Product* loadProducts(std::string filename, int& numProducts, int& capacity);

void searchProducts(Product* products, int numProducts);

void printProductsTable(Product* products, int numProducts);

#endif
