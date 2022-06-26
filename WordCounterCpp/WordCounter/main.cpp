#include "WordCounter.h"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        return 0;
    }
    const std::string input = (std::string)(argv[1]);
    const std::string output = (std::string)(argv[2]);
    WordCounter counter(input, output);
}