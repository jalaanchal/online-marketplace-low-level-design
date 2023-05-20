#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>

#include "CartItem.h"
using namespace std;

class Order {
   private:
    string orderId;
    vector<CartItem> items;

   public:
    Order(const string& orderId, const vector<CartItem>& items)
        : orderId(orderId), items(items) {
    }

    const string& getOrderId() const {
        return orderId;
    }

    const vector<CartItem>& getItems() const {
        return items;
    }

    void setOrderId(const string& orderId) {
        this->orderId = orderId;
    }

    void setItems(const vector<CartItem>& items) {
        this->items = items;
    }
};

#endif
