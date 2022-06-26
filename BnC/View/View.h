#ifndef LAB4_VIEW_VIEW_H_
#define LAB4_VIEW_VIEW_H_

#include <utility>
#include <vector>
#include "../Model/Model.h"
#include "../Observer/Observer.h"
#include "memory"

class View : public Observer
{
private:
	std::shared_ptr<Model> model;
public:
	explicit View(const std::shared_ptr<Model>& model);
	void HandleEvent() override;
};

#endif //LAB4_VIEW_VIEW_H_
