#include <iostream>
#include <memory>
#include "Controller.h"
#include "../Exceptions/InvalidInput.h"
#include "../Model/Human.h"
#include "../Model/AI.h"

void Controller::MakeTurn(Model& model, std::vector<int>& guess)
{
	model.ProcessTurn(guess);
}

void Controller::StartGame()
{
	PlayerType player_type = ChoosePlayerType();
	std::shared_ptr<Player> player;
	if(player_type == PlayerType::Human)
	{
		player = std::shared_ptr<Player>(new Human);
	}
	else
	{
		player = std::shared_ptr<Player>(new AI);
	}
	std::shared_ptr<Model> model = std::make_shared<Model> ();
	View view(model);
	while(true)
	{
		std::vector<int> guess = player->GetNumber();
		MakeTurn(*model, guess);
		if(model->IsMatch())
		{
			break;
		}
	}

}
PlayerType Controller::ChoosePlayerType()
{
	std::string input;
	std::cout << "Please choose game mode: type 0 for computer vs computer, type 1 if wanna play by yourself " << std::endl;
	std::getline(std::cin, input);
	if(input == "0")
	{
		return PlayerType::AI;
	}
	else if (input == "1")
	{
		return PlayerType::Human;
	}
	else
	{
		throw InvalidInput();
	}
}
