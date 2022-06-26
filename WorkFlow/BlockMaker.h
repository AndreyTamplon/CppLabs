#ifndef WORKFLOW_BLOCKMAKER_H
#define WORKFLOW_BLOCKMAKER_H

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "IBlockMaker.h"
#include "BlockFactory.h"

template<typename T>

class BlockMaker : public IBlockMaker
{
public:
    explicit BlockMaker(const std::string& key)
    {
        BlockFactory::GetInstance().RegisterMaker(key, this);
    }
    Block* Create() const override
    {
        return new T();
    }
};

#endif //WORKFLOW_BLOCKMAKER_H
