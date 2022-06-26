#include "Observable.h"
#include "algorithm"


void Observable::AddObserver(Observer* observer)
{
	observers.push_back(observer);
}
void Observable::RemoveObserver(Observer* observer)
{
	observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}
void Observable::NotifyObservers()
{
	for(auto observer : observers)
	{
		observer->HandleEvent();
	}
}
