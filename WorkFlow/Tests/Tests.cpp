//#include <gtest/gtest.h>
#include "fstream"
#include "../WorkFlowExecutor.h"
/*
class Fixation : public ::testing::Test
{
protected:
	std::ifstream in;
	void SetUp()
	{
		in.open("test_text1.txt");
		WorkFlowExecutor executor;
		executor.ExecuteWorkFlow(in);
		in.close();
	}
};
*/
int main()
{
	std::ifstream in;
	in.open("C:/Users/andre/CLionProjects/WorkFlow/test_text1.txt");
	WorkFlowExecutor executor;
	executor.ExecuteWorkFlow(in);
	in.close();
//	::testing::InitGoogleTest();
//	return RUN_ALL_TESTS();
}


