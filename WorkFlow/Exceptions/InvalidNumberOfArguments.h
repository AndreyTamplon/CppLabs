#ifndef WORKFLOW_INVALIDNUMBEROFARGUMENTS_H
#define WORKFLOW_INVALIDNUMBEROFARGUMENTS_H


class InvalidNumberOfArguments {
private:
    std::string error_message = "Invalid Number Of Arguments";
public:
    InvalidNumberOfArguments() = default;
    explicit InvalidNumberOfArguments(std::string error) : error_message(error)
    {
    }
    const char* what() const noexcept
    {
        return error_message.c_str();
    }
};


#endif //WORKFLOW_INVALIDNUMBEROFARGUMENTS_H
