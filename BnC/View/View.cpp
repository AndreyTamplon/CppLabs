#include <iostream>
#include "View.h"


View::View(const std::shared_ptr<Model>& model)
{
	std::cout<<"Attempt_number number BnC\n";
	this->model = model;
	model->AddObserver(this);
}

void View::HandleEvent()
{
	std::cout << model->GetAttemptNumber() << " ";
	for(auto n : model->GetLastGuess())
	{
		std::cout<<n;
	}
	std::cout <<" " << model->GetBnC().first << " " << model->GetBnC().second << std::endl;
}

