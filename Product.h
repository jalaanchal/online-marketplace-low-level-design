
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
   private:
    string productId;
    string name;
    double price;

   public:
    Product() {
        productId = "";
        name = "";
        price = 0.0;
    }

    Product(const string& productId, const string& name, double price)
        : productId(productId), name(name), price(price) {
    }

    const string& getProductId() const {
        return productId;
    }

    const string& getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    void setProductId(const string& productId) {
        this->productId = productId;
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setPrice(double price) {
        this->price = price;
    }
};

#endif
