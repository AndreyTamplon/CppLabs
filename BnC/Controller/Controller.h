#ifndef LAB4_CONTROLLER_CONTROLLER_H_
#define LAB4_CONTROLLER_CONTROLLER_H_
#include <utility>
#include "../Model/Model.h"
#include "../View/View.h"
enum class PlayerType
{
	Human,
	AI
};
class Controller
{
private:
	void MakeTurn(Model& model, std::vector<int>& guess);
	PlayerType ChoosePlayerType();
public:
	void StartGame();
};

#endif //LAB4_CONTROLLER_CONTROLLER_H_
