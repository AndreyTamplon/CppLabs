#ifndef WORKFLOW_MULTIPLEMAKERS_H
#define WORKFLOW_MULTIPLEMAKERS_H


class MultipleMakers {
private:
    std::string error_message = "Multiple Makers";
public:
    MultipleMakers() = default;
    explicit MultipleMakers(std::string error) : error_message(error)
    {
    }
    const char* what() const noexcept
    {
        return error_message.c_str();
    }
};
#endif //WORKFLOW_MULTIPLEMAKERS_H
