#include "WriteCore.h"


void WriteCore::WriteInFile(const std::list<std::string> &text, const std::vector<std::string> &args)
{
	if (args.size() != 1)
	{
		throw InvalidNumberOfArguments();
	}
	std::ofstream out;
	try
	{
		out.open(args[0]);
		for (auto &line: text)
		{
			out << line << std::endl;
		}
		out.close();
	}
	catch (const std::ifstream::failure &ex)
	{
		std::cerr << "Error: " << ex.what() << std::endl;
	}

}
