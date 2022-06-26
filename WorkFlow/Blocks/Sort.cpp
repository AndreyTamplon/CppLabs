#include "Sort.h"

static BlockMaker<Sort> maker("sort");

std::list<std::string> Sort::Execute(const std::list<std::string> &text, const std::vector<std::string> &args)
{
    if(!args.empty())
    {
        throw InvalidNumberOfArguments();
    }
    std::list<std::string> new_text(text);
    new_text.sort();
    return new_text;
}
BlockType Sort::GetType()
{
    return BlockType::INOUT;
}
