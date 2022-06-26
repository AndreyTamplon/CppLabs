cmake_minimum_required(VERSION 3.20)
project(WordCounter)

set(CMAKE_CXX_STANDARD 17)

add_executable(WordCounter main.cpp WordCounter.cpp WordCounter.h main.cpp)
