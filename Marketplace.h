#ifndef MARKETPLACE_H
#define MARKETPLACE_H

#include <iostream>
#include <map>
#include <vector>

#include "Order.h"
#include "Product.h"
#include "User.h"
using namespace std;

class Marketplace {
   private:
    map<string, User> users;
    map<string, Product> products;
    map<string, vector<Order>> orderHistory;

    // helper method
    string generateOrderId() {
        int orderId = rand();
        return to_string(orderId);
    }

   public:
    void createUser(const User& user) {
        users[user.getUserId()] = user;
        cout << "User " << user.getName() << " created with userId = " << user.getUserId() << endl;
    }

    User& getUser(const string& userId) {
        return users.at(userId);
    }

    void addProduct(const Product& product) {
        products[product.getProductId()] = product;
        cout << "Product " << product.getName() << " created with productId = " << product.getProductId() << endl;
    }

    Product& getProduct(const string& productId) {
        return products.at(productId);
    }

    void addToCart(const string& userId, const string& productId, int quantity) {
        User& user = users.at(userId);
        user.addToCart(getProduct(productId), quantity);
        cout << "Product with productId = " << productId << " with quantity = " << quantity << " added to the cart of user with userId = " << userId << endl;
    }

    vector<CartItem> getCart(const string& userId) {
        User& user = users.at(userId);
        return user.getCart();
    }

    void checkout(const string& userId) {
        User& user = users[userId];
        vector<CartItem> cart = user.getCart();
        if (cart.empty()) {
            return;
        }

        Order order(generateOrderId(), cart);
        user.clearCart();

        orderHistory[userId].push_back(order);
    }

    vector<Order> getOrderHistory(const string& userId) {
        if (orderHistory.find(userId) != orderHistory.end()) {
            return orderHistory.at(userId);
        } else {
            // Handle user not found or empty order history scenario
            return {};
        }
    }
};

#endif
