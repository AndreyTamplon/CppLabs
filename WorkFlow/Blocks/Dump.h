#ifndef WORKFLOW_DUMP_H
#define WORKFLOW_DUMP_H

#include "WriteCore.h"
#include "../Block.h"
#include "../BlockMaker.h"

class Dump : public Block, public WriteCore
{
    std::list<std::string> Execute(const std::list<std::string> &text, const std::vector<std::string> &args) override;
    BlockType GetType() override;
    ~Dump() override = default;
};


#endif //WORKFLOW_DUMP_H
