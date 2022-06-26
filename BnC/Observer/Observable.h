#ifndef LAB4_OBSERVER_OBSERVABLE_H_
#define LAB4_OBSERVER_OBSERVABLE_H_
#include <vector>
#include "Observer.h"

class Observable
{
private:
	std::vector<class Observer*> observers;
public:
	void AddObserver(Observer* observer);
	void RemoveObserver(Observer* observer);
	void NotifyObservers();
};

#endif //LAB4_OBSERVER_OBSERVABLE_H_
