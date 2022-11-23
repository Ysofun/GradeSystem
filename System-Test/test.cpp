#include "pch.h"
#include "..\成绩录入系统\FunctionLibrary.h"

TEST(FunctionLibrary, QuickSort) 
{
	std::vector<int> sortTest = { 2, 3, 1, 4, 11, 432, 1, 213, 23 };
	std::vector<int> sortExpect = { 1, 1, 2, 3, 4, 11, 23, 213, 432 };

	QuickSort<int>(sortTest, 0, sortTest.size() - 1, [](int a, int b) -> bool { return a <= b; });
	EXPECT_EQ(sortTest, sortExpect);
}