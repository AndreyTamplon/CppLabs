#ifndef WORKFLOW_READFILE_H
#define WORKFLOW_READFILE_H

#include <list>
#include <string>
#include <vector>
#include "../Block.h"
#include "../BlockMaker.h"
#include "../Exceptions/InvalidNumberOfArguments.h"
#include "fstream"


class ReadFile : public Block
{
public:
    std::list<std::string> Execute(const std::list<std::string> &text, const std::vector<std::string> &args) override;
    BlockType GetType() override;
    ~ReadFile() override = default;
};


#endif //WORKFLOW_READFILE_H
