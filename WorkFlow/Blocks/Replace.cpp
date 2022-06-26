#include "Replace.h"

static BlockMaker<Replace> maker("replace");

std::list<std::string> Replace::Execute(const std::list<std::string> &text, const std::vector<std::string> &args)
{
	if (args.size() != 2)
	{
		throw InvalidNumberOfArguments();
	}
	std::list<std::string> new_text = text;
	for(auto& line : new_text)
	{
		std::string new_string;
		new_string.reserve(line.length());

		std::string::size_type last_pos = 0;
		std::string::size_type find_pos;

		while(std::string::npos != (find_pos = line.find(args[0], last_pos)))
		{
			new_string.append(line, last_pos, find_pos - last_pos);
			new_string += args[1];
			last_pos = find_pos + args[0].length();
		}
		new_string += line.substr(last_pos);
		line.swap(new_string);
	}
	return new_text;
}
BlockType Replace::GetType()
{
    return BlockType::INOUT;
}