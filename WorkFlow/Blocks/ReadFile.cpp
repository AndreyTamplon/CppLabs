#include "ReadFile.h"


static BlockMaker<ReadFile> maker("readfile");

std::list<std::string> ReadFile::Execute(const std::list<std::string> &text, const std::vector<std::string> &args)
{
    if(args.size() != 1)
    {
        throw InvalidNumberOfArguments();
    }
    std::list<std::string> new_text;
	std::ifstream in;
	try
	{
		in.open(args[0]);
		std::string line;
		while(std::getline(in, line))
		{
			new_text.emplace_back(line);
		}
		in.close();
	}
	catch (const std::ifstream::failure &ex)
	{
		std::cerr << "Error: " << ex.what() << std::endl;
	}
    return new_text;
}
BlockType ReadFile::GetType()
{
    return BlockType::IN;
}