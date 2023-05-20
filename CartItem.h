#ifndef CARTITEM_H
#define CARTITEM_H

#include "Product.h"
using namespace std;

class CartItem {
   private:
    const Product* product;
    int quantity;

   public:
    CartItem(const Product* product, int quantity)
        : product(product), quantity(quantity) {
    }

    const Product* getProduct() const {
        return product;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }
};

#endif
