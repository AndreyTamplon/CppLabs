#include <iostream>
#include "Model.h"
#include <chrono>
#include <random>

std::pair<int, int> Model::CalcBnC(const std::vector<int>& number) const
{
	int bulls = 0, cows = 0;
	for(int i = 0; i < number.size(); ++i)
	{
		for(int j = 0; j < number.size(); ++j)
		{
			if (number[i] == riddled_number[j])
			{
				if(i == j)
				{
					bulls++;
				}
				else
				{
					cows++;
				}
			}
		}
	}
	return std::make_pair(bulls, cows);
}

void Model::PickUpNumber()
{
	std::vector<int> unused_digits(10);
	for(int i = 0; i < unused_digits.size(); ++i)
	{
		unused_digits[i] = i;
	}
	riddled_number.resize(4);
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::minstd_rand0 generator (seed);
	for(int& i : riddled_number)
	{
		int index = generator() % unused_digits.size();
		i = unused_digits[index];
		unused_digits.erase(unused_digits.begin() + index);
	}
}

Model::Model()
{
	attempt_number = 0;
	PickUpNumber();
}

bool Model::IsMatch() const
{
	return CalcBnC(last_guess).first == last_guess.size();
}

void Model::ProcessTurn(std::vector<int>& guess)
{
	attempt_number++;
	last_guess = guess;
	NotifyObservers();
}

int Model::GetAttemptNumber() const
{
	return attempt_number;
}
std::vector<int> Model::GetLastGuess() const
{
	return last_guess;
}
std::pair<int, int> Model::GetBnC() const
{
	return CalcBnC(last_guess);
}
