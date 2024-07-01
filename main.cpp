#include <iostream>
#include "OrderBook.h"

int main() {
    OrderBook orderBook;
    orderBook.addOrder(1, 100.5, 10);
    orderBook.addOrder(2, 101.0, 5);
    orderBook.processOrders();

    return 0;
}
