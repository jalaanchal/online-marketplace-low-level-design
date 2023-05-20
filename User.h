#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

#include "CartItem.h"
#include "Order.h"
using namespace std;

class User {
   private:
    string userId;
    string name;
    string email;
    string password;
    vector<Order> orderHistory;
    vector<CartItem> cart;

   public:
    User() {
        userId = "";
        name = "";
        email = "";
        password = "";
        orderHistory = {};
        cart = {};
    }

    User(const string& userId, const string& name, const string& email, const string& password)
        : userId(userId), name(name), email(email), password(password) {
    }

    const string& getUserId() const {
        return userId;
    }

    const string& getName() const {
        return name;
    }

    const string& getEmail() const {
        return email;
    }

    const string& getPassword() const {
        return password;
    }

    void setUserId(const string& userId) {
        this->userId = userId;
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setEmail(const string& email) {
        this->email = email;
    }

    void setPassword(const string& password) {
        this->password = password;
    }

    void addToOrderHistory(const Order& order) {
        orderHistory.push_back(order);
    }

    const vector<Order>& getOrderHistory() const {
        return orderHistory;
    }

    void addToCart(const Product& product, int quantity) {
        for (CartItem& cartItem : cart) {
            if (cartItem.getProduct() == &product) {
                // Update if already present
                cartItem.setQuantity(cartItem.getQuantity() + quantity);
                return;
            }
        }
        // Add new if not present
        cart.emplace_back(&product, quantity);
    }

    const vector<CartItem>& getCart() const {
        return cart;
    }

    void clearCart() {
        cart.clear();
    }
};

#endif
