#ifndef WORKFLOW_INVALIDINPUTSTRUCTURE_H
#define WORKFLOW_INVALIDINPUTSTRUCTURE_H


class InvalidInputStructure : public std::exception
{
private:
    std::string error_message = "Invalid Input Structure";
public:
    InvalidInputStructure() = default;
    explicit InvalidInputStructure(std::string error) : error_message(error)
    {
    }
    const char* what() const noexcept
    {
        return error_message.c_str();
    }
};


#endif //WORKFLOW_INVALIDINPUTSTRUCTURE_H
