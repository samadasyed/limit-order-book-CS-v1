#include "OrderBook.h"
#include <immintrin.h> // For SIMD
#include <algorithm>

void OrderBook::addOrder(int id, double price, int quantity) {
    std::lock_guard<std::mutex> lock(order_mutex);
    orders.push_back({id, price, quantity});
}

void OrderBook::processOrders() {
    std::lock_guard<std::mutex> lock(order_mutex);
    // Example SIMD operation (details will vary based on requirements)
    size_t size = orders.size();
    for (size_t i = 0; i < size; i += 4) {
        if (i + 3 < size) {
            __m256d prices = _mm256_set_pd(orders[i].price, orders[i+1].price, orders[i+2].price, orders[i+3].price);
            // Perform SIMD operations on prices
        }
    }
    // Simulate processing (e.g., matching, updating order book)
    std::sort(orders.begin(), orders.end(), [](const Order& a, const Order& b) {
        return a.price < b.price;
    });
}
