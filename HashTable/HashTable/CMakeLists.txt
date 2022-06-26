cmake_minimum_required(VERSION 3.20)
project(HashTable)

set(CMAKE_CXX_STANDARD 14)
#Add the google test subdirectory
add_subdirectory(C:/Users/andre/CLionProjects/googletest gt)

#include googletest/include dir
include_directories(C:/Users/andre/CLionProjects/googletest/googletest/include)
#include the googlemock/include dir
include_directories(C:/Users/andre/CLionProjects/googletest/googlemock/include)
add_executable(HashTable HashTable.cpp HashTable.h tests.cpp tests.cpp)
target_link_libraries(HashTable gtest gtest_main)
