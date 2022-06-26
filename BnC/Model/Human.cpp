#include <iostream>
#include <algorithm>
#include "Human.h"
#include "../Exceptions/InvalidInput.h"

bool Human::CheckInput(std::string& input)
{
	if (input.size() != 4 || std::any_of(input.begin(), input.end(), [](auto c) { return std::isdigit(c) == 0; }))
	{
		return false;
	}
	for (int i = 0; i < input.size(); ++i)
	{
		for (int j = i + 1; j < input.size(); ++j)
		{
			if (input[i] == input[j])
			{
				return false;
			}
		}
	}
	return true;
}

std::vector<int> Human::GetNumber()
{
	std::string input;
	std::cout << "Enter the number " << input << std::endl;
	std::getline(std::cin, input);
	if (!CheckInput(input))
	{
		throw InvalidInput();
	}
	else
	{
		std::vector<int> number(input.size());
		for (int i = 0; i < number.size(); ++i)
		{
			number[i] = std::stoi(input.substr(i, 1));
		}
		return number;
	}
}
