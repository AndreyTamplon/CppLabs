#ifndef LAB4_MODEL_HUMAN_H_
#define LAB4_MODEL_HUMAN_H_
#include <string>
#include <vector>
#include "Player.h"


class Human : public Player
{
private:
	bool CheckInput(std::string& input);
public:
	std::vector<int> GetNumber() override;
};

#endif //LAB4_MODEL_HUMAN_H_
