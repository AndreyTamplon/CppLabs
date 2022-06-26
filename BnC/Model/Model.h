#ifndef LAB4_MODEL_MODEL_H_
#define LAB4_MODEL_MODEL_H_

#include <vector>
#include "../Observer/Observable.h"

class Model : public Observable
{
private:
	std::vector<int> riddled_number;
	int attempt_number;
	std::vector<int> last_guess;
	std::pair<int, int> CalcBnC(const std::vector<int>& number) const;
	void PickUpNumber();
public:
	Model();
	bool IsMatch() const;
	void ProcessTurn(std::vector<int>& guess);
	int GetAttemptNumber() const;
	std::vector<int> GetLastGuess() const;
	std::pair<int, int> GetBnC() const;
};

#endif //LAB4_MODEL_MODEL_H_
