#ifndef LAB4_MODEL_AI_H_
#define LAB4_MODEL_AI_H_
#include "Player.h"


class AI : public Player
{
private:
	std::vector<std::vector<int>> possible_numbers;
public:
	AI();
	std::vector<int> GetNumber();
};

#endif //LAB4_MODEL_AI_H_
