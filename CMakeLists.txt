cmake_minimum_required(VERSION 3.10)
project(FastOrderBook)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -O3")

add_executable(FastOrderBook main.cpp OrderBook.cpp)
