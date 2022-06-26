#include "WordCounter.h"
#include <iostream>


bool WordCounter::CheckSymbol(char symbol)
{
    int ascii_value = static_cast<int>(symbol);
    if (ascii_value < 0)
    {
        std::cerr << "Bad symbol";
        exit(1);
    }
    if(ascii_value >= '0' && ascii_value <= '9'
       || ascii_value >= 'A' && ascii_value <= 'Z'
       || ascii_value >= 'a' && ascii_value <= 'z' )
    {
        return true;
    }
    return false;
}


void WordCounter::ParseString(std::string line)
{
    int beginning_of_word = -1;
    for(int i = 0; i <= line.size(); ++i)
    {
        if((i == line.size() || !CheckSymbol(static_cast<char>(line.at(i)))) && beginning_of_word != -1)
        {
            dictionary[line.substr(beginning_of_word, i - beginning_of_word)]++;
            beginning_of_word = -1;
            number_of_words += 1;
        }
        else if(beginning_of_word == -1 && CheckSymbol(static_cast<char>(line.at(i))))
        {
            beginning_of_word = i;
        }
    }
}


void WordCounter::CountWords(const std::string& input_filepath, const std::string& output_filepath)
{
    std::fstream input_file;
    input_file.open(input_filepath, std::ios::in);
    if(!input_file)
    {
        std::cerr << "Unable to open the file";
        exit(1);
    }
    std::string line;
    while(!input_file.eof())
    {
        std::getline(input_file, line);
        ParseString(line);
    }
    std::vector<std::pair<std::string, int> > sorted_words = GetSortedWords();
    std::fstream output_file;
    output_file.open(output_filepath, std::ios::out);
    if(!output_file)
    {
        std::cerr << "Unable to open the file " << output_file.rdstate();
        exit(1);
    }
    for(const auto& it : sorted_words)
    {
        output_file << it.first << "," << it.second << ","
                    << (double)it.second/(double)number_of_words * 100 << "\n";
    }
}


std::vector<std::pair<std::string, int> > WordCounter::GetSortedWords()
{
    std::vector<std::pair<std::string, int>> words;
    for(const auto& it : dictionary)
    {
        words.emplace_back(it);
    }
    std::sort(words.begin(), words.end(), ComparePairs());
    return  words;
}

WordCounter::WordCounter() : number_of_words(0)
{

}


WordCounter::WordCounter(const std::string& input_filepath, const std::string& output_filepath) : number_of_words(0)
{
    CountWords(input_filepath, output_filepath);
}


WordCounter::WordCounter(WordCounter&& counter) noexcept
{
    dictionary = std::move(counter.dictionary);
    number_of_words = counter.number_of_words;
}

WordCounter& WordCounter::operator=(WordCounter&& counter) noexcept
{
    if (this == &counter)
    {
        return *this;
    }
    dictionary.clear();
    number_of_words = counter.number_of_words;
    dictionary = std::move(counter.dictionary);
    counter.number_of_words = 0;
    std::map<std::string, int> temp;
    counter.dictionary = temp;
    return *this;
}


void WordCounter::DisplayWords()
{
    std::vector<std::pair<std::string, int> > sorted_words = GetSortedWords();
    for(const auto& it : dictionary)
    {
        std::cout << it.first << "," << it.second << ","
                  << (double)it.second/(double)number_of_words * 100 << "\n";
    }
}


void WordCounter::ResetTheCounter()
{
    number_of_words = 0;
    dictionary.clear();
}