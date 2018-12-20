cmake_minimum_required(VERSION 3.12)
project(heap)

set(CMAKE_CXX_STANDARD 14)

add_executable(heap heap.h heap.cpp test.cpp vector.h binomialheap.h)