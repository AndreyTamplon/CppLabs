cmake_minimum_required(VERSION 3.20)
project(WorkFlow)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(C:/Users/andre/CLionProjects/googletest gt)
include_directories(C:/Users/andre/CLionProjects/googletest/googletest/include)
#include the googlemock/include dir
include_directories(C:/Users/andre/CLionProjects/googletest/googlemock/include)
add_executable(WorkFlow WorkFlowExecutor.h WorkFlowParser.h Block.h
        Blocks/ReadFile.cpp Blocks/ReadFile.h BlockFactory.h Blocks/Sort.cpp Blocks/Sort.h IBlockMaker.h
        Exceptions/BadBlockOrder.h Exceptions/UndefinedBlock.h Exceptions/MultipleMakers.h BlockMaker.h Exceptions/InvalidInputStructure.h
        Blocks/WriteFile.cpp Blocks/WriteFile.h Blocks/Dump.cpp Blocks/Dump.h Blocks/Grep.cpp
        Blocks/Grep.h Blocks/Replace.cpp Blocks/Replace.h Exceptions/InvalidNumberOfArguments.h Blocks/WriteCore.cpp
        Blocks/WriteCore.h Tests/Tests.cpp)
target_link_libraries(WorkFlow gtest gtest_main)