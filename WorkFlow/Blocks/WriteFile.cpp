#include "WriteFile.h"


static BlockMaker<WriteFile> maker("writefile");
std::list<std::string> WriteFile::Execute(const std::list<std::string> &text, const std::vector<std::string> &args)
{
	WriteInFile(text, args);
	return text;
}
BlockType WriteFile::GetType()
{
    return BlockType::OUT;
}