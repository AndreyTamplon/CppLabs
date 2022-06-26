#include "Grep.h"


static BlockMaker<Grep> maker("grep");

std::list<std::string> Grep::Execute(const std::list<std::string> &text, const std::vector<std::string> &args)
{
	if (args.size() != 1) {
		throw InvalidNumberOfArguments();
	}
	std::list<std::string> new_text;
	for (auto &line : text)
	{
		if(line.find(args[0]) != std::string::npos)
		{
			new_text.emplace_back(line);
		}
	}
	return new_text;
}
BlockType Grep::GetType()
{
    return BlockType::INOUT;
}