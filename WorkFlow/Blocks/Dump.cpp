#include "Dump.h"

static BlockMaker<Dump> maker("dump");

std::list<std::string> Dump::Execute(const std::list<std::string> &text, const std::vector<std::string> &args)
{
	WriteInFile(text, args);
    return text;
}
BlockType Dump::GetType()
{
    return BlockType::INOUT;
}