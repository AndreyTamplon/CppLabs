#ifndef LAB4_EXCEPTIONS_INVALIDINPUT_H_
#define LAB4_EXCEPTIONS_INVALIDINPUT_H_

class InvalidInput : public std::exception
{
private:
	std::string error_message = "Invalid Input";
public:
	InvalidInput() = default;
	explicit InvalidInput(std::string error) : error_message(error)
	{
	}
	const char* what() const noexcept
	{
		return error_message.c_str();
	}
};

#endif //LAB4_EXCEPTIONS_INVALIDINPUT_H_
