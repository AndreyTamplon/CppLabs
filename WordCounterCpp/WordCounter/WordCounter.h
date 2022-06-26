#ifndef WORDCOUNTER_WORDCOUNTER_H
#define WORDCOUNTER_WORDCOUNTER_H
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ios>
#include <algorithm>

class WordCounter
{
private:
    std::map<std::string, int> dictionary;
    long long int number_of_words;
    void ParseString(std::string line);
    static bool CheckSymbol(char symbol);
    std::vector<std::pair<std::string, int>> GetSortedWords();
public:
    WordCounter();
    WordCounter(const std::string& input_filepath, const std::string& output_filepath);
    ~WordCounter() = default;
    WordCounter(const WordCounter& counter) = default;
    WordCounter(WordCounter&& counter) noexcept;
    WordCounter& operator=(const WordCounter& counter) = default;
    WordCounter& operator=(WordCounter&& counter) noexcept;
    void CountWords(const std::string& input_filepath, const std::string& output_filepath);
    void DisplayWords();
    void ResetTheCounter();
};
class ComparePairs
{
public:
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const
    {
        return (a.second != b.second)? a.second > b.second : a.first > b.first;
    }
};



#endif //WORDCOUNTER_WORDCOUNTER_H
