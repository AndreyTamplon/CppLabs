#ifndef WORKFLOW_BLOCKFACTORY_H
#define WORKFLOW_BLOCKFACTORY_H
#include <iostream>
#include <string>
#include <map>
#include "Block.h"
#include "IBlockMaker.h"
#include "Exceptions/MultipleMakers.h"
#include "Exceptions/UndefinedBlock.h"


class BlockFactory
{
    BlockFactory() = default;
    std::map<std::string, IBlockMaker*> _makers;
public:
    static BlockFactory& GetInstance()
    {
        static BlockFactory factory;
        return factory;
    }
    void RegisterMaker(const std::string& key, IBlockMaker* maker)
    {
        if (_makers.find(key) != _makers.end())
        {
            throw  MultipleMakers();
        }
        _makers[key] = maker;
    }


    Block* Create(std::string& block_name) const
    {
        auto i = _makers.find(block_name);
        if (i == _makers.end())
        {
            throw UndefinedBlock();
        }
        IBlockMaker* maker = i->second;
        return maker->Create();
    }

};


#endif //WORKFLOW_BLOCKFACTORY_H
