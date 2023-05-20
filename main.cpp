#include <iostream>

#include "Marketplace.h"
using namespace std;

int main() {
    Marketplace marketplace;

    User user1("userId1", "Jalaanchal Tewari", "jt@gmail.com", "password1");
    marketplace.createUser(user1);

    cout << endl;

    Product product1("productId1", "Product 1", 10);
    marketplace.addProduct(product1);
    Product product2("productId2", "Product 2", 20);
    marketplace.addProduct(product2);

    cout << endl;

    marketplace.addToCart("userId1", "productId1", 2);
    marketplace.addToCart("userId1", "productId2", 1);

    cout << endl;

    cout << "User 1 Cart:" << endl;
    const vector<CartItem>& user1Cart = marketplace.getCart("userId1");
    for (const CartItem& item : user1Cart) {
        cout << "Product: " << item.getProduct()->getName() << ", Quantity: " << item.getQuantity() << endl;
    }

    cout << endl;

    try {
        marketplace.checkout("userId1");
        cout << "User 1 checkout successful\n";
    } catch (const exception& e) {
        cout << "User 1 checkout failed: " << e.what() << endl;
    }

    cout << endl;

    cout << "User 1 Order History:" << endl;
    const vector<Order>& user1OrderHistory = marketplace.getOrderHistory("userId1");
    for (const Order& order : user1OrderHistory) {
        cout << "Order Id: " << order.getOrderId() << endl;
        const vector<CartItem>& items = order.getItems();
        for (const CartItem& item : items) {
            cout << "Product: " << item.getProduct()->getName() << ", Quantity: " << item.getQuantity() << endl;
        }
        cout << endl;
    }

    return 0;
}
