#include <vector>

#include "AI.h"

std::vector<int> AI::GetNumber()
{
	std::vector<int> number = possible_numbers[possible_numbers.size() - 1];
	possible_numbers.pop_back();
	return number;
}
AI::AI()
{
	for(int a = 0; a < 10; ++a)
	{
		for(int b = 0; b < 10; ++b)
		{
			if(b == a)
			{
				continue;
			}
			for(int c = 0; c < 10; ++c)
			{
				if(c == b || c == a)
				{
					continue;
				}
				for(int d = 0; d < 10; ++d)
				{
					if(d == c || d == b || d == a)
					{
						continue;
					}
					possible_numbers.push_back(std::vector<int>{a, b, c, d});
				}
			}
		}
	}
}
