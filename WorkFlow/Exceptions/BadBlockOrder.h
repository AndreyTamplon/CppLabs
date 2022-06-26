#ifndef WORKFLOW_BADBLOCKORDER_H
#define WORKFLOW_BADBLOCKORDER_H

class BadBlockOrder : public std::exception
{
private:
    std::string error_message = "Bad Block Order";
public:
    BadBlockOrder() = default;
    explicit BadBlockOrder(std::string error) : error_message(error)
    {
    }
    const char* what() const noexcept override
    {
        return error_message.c_str();
    }
};

#endif //WORKFLOW_BADBLOCKORDER_H
