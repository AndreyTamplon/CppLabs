#ifndef WORKFLOW_UNDEFINEDBLOCK_H
#define WORKFLOW_UNDEFINEDBLOCK_H


class UndefinedBlock : public std::exception
{
private:
    std::string error_message = "Undefined Block";
public:
    UndefinedBlock() = default;
    explicit UndefinedBlock(std::string error) : error_message(error)
    {
    }
    const char* what() const noexcept
    {
        return error_message.c_str();
    }
};

#endif //WORKFLOW_UNDEFINEDBLOCK_H
