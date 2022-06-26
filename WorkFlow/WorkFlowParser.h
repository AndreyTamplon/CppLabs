#ifndef WORKFLOW_WORKFLOWPARSER_H
#define WORKFLOW_WORKFLOWPARSER_H
#include <iostream>
#include "istream"
#include "string"
#include "list"
#include "vector"
#include "Exceptions/InvalidInputStructure.h"
class WorkFlowParser
{
public:
    std::list<std::pair < std::string, std::vector < std::string > > > GetBlocks(std::istream& in)
    {
        std::list<std::pair < std::string, std::vector<std::string > > > processed_input;
        std::vector<std::pair < int, std::pair < std::string, std::vector < std::string > > > > temporary_storage(1);
        std::string line;
        std::getline(in, line);
        if (line != "desc")
        {
			std::cout<<"line = " << line << "\n";
            throw InvalidInputStructure();
        }
        int current_array_idx = 0;
        while(std::getline(in, line))
        {
            if(line == "csed")
            {
                break;
            }
            int space_position = line.find(' '), block_index;
            if(space_position == std::string::npos)
            {
                throw InvalidInputStructure();
            }
            try
            {
                block_index = std::stoi(line.substr(0, space_position));
            }
            catch (std::exception& ex)
            {
                std::cerr << "Error: " << ex.what() << std::endl;
            }
            int i = line.find(' ',line.find('='));
            while(!std::isalpha(line[i]))
            {
                ++i;
            }
            int block_name_end = line.find(' ', i);
            if(current_array_idx == temporary_storage.size())
            {
                temporary_storage.resize(temporary_storage.size() * 2);
            }
            temporary_storage[current_array_idx].second.first = line.substr(i, block_name_end - i);
            temporary_storage[current_array_idx].first = block_index;
            int j = block_name_end;
            bool end_of_line = false;
            while(j < line.size())
            {
                while(!std::isalpha(line[j]))
                {
                    if(j == line.size())
                    {
                        end_of_line = true;
                        break;
                    }
                    ++j;
                }
                if(end_of_line)
                {
                    break;
                }
                int argument_name_end = line.find(' ', j);
                temporary_storage[current_array_idx].second.second.emplace_back(line.substr(j, argument_name_end - j));
                j = argument_name_end;
            }
            ++current_array_idx;
        }
        std::getline(in, line);
        int i = 0;
        while(i < line.size())
        {
            int space_position = line.find(' ', i), block_idx, Id;
			if(space_position == -1)
			{
				Id = std::stoi(line.substr(i, line.size() - i));
			}
			else
			{
				Id = std::stoi(line.substr(i, space_position - i));
			}
			for(int j = 0; j < temporary_storage.size(); ++j)
            {
                if(temporary_storage[j].first == Id)
                {
                    block_idx = j;
					break;
                }
            }
            processed_input.emplace_back(temporary_storage[block_idx].second);
            i = (space_position != -1) * space_position + 4 + (space_position == -1) * line.size();
        }
        return processed_input;
    }
};
#endif //WORKFLOW_WORKFLOWPARSER_H
