#ifndef WORKFLOW_SORT_H
#define WORKFLOW_SORT_H

#include <list>
#include <string>
#include <vector>
#include "../Block.h"
#include "../BlockMaker.h"
#include "../Exceptions/InvalidNumberOfArguments.h"


class Sort : public Block
{
public:
    std::list<std::string> Execute(const std::list<std::string> &text, const std::vector<std::string> &args) override;
    BlockType GetType() override;
    ~Sort() = default;
};


#endif //WORKFLOW_SORT_H
