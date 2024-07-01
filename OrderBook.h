#pragma once

#include <vector>
#include <mutex>

struct Order {
    int id;
    double price;
    int quantity;
    alignas(64) char padding[64 - sizeof(int) - sizeof(double) - sizeof(int)];
};

class OrderBook {
public:
    void addOrder(int id, double price, int quantity);
    void processOrders();

private:
    std::vector<Order> orders;
    std::mutex order_mutex;
};
