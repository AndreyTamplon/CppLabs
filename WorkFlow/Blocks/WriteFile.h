#ifndef WORKFLOW_WRITEFILE_H
#define WORKFLOW_WRITEFILE_H

#include "WriteCore.h"
#include "../Block.h"
#include "../BlockMaker.h"

class WriteFile : public Block, public WriteCore
{
    std::list<std::string> Execute(const std::list<std::string> &text, const std::vector<std::string> &args) override;
    BlockType GetType() override;
    ~WriteFile() override = default;
};


#endif //WORKFLOW_WRITEFILE_H
