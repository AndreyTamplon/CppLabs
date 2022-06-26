#ifndef WORKFLOW_BLOCKS_WRITECORE_H_
#define WORKFLOW_BLOCKS_WRITECORE_H_
#include <fstream>
#include "list"
#include <vector>
#include <string>
#include <iostream>
#include "../Exceptions/InvalidNumberOfArguments.h"
class WriteCore
{
public:
	void WriteInFile(const std::list<std::string> &text, const std::vector<std::string> &args);
};


#endif // WORKFLOW_BLOCKS_WRITECORE_H_
