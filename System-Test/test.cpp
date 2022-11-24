#include "pch.h"
#include "..\成绩录入系统\FunctionLibrary.h"

TEST(FunctionLibrary, QuickSort) 
{
	std::vector<int> sortTest = { 2, 3, 1, 4, 11, 432, 1, 213, 23 };
	std::vector<int> sortExpect = { 1, 1, 2, 3, 4, 11, 23, 213, 432 };

	QuickSort<int>(sortTest, 0, sortTest.size() - 1, [](int a, int b) -> bool { return a <= b; });
	EXPECT_EQ(sortTest, sortExpect);

	sortTest = { 2, 1, 1, 1, 1 };
	sortExpect = { 1, 1, 1, 1, 2 };
	QuickSort<int>(sortTest, 0, sortTest.size() - 1, [](int a, int b) -> bool { return a <= b; });
	EXPECT_EQ(sortTest, sortExpect);
}

TEST(FunctionLibrary, GetValue)
{
	std::vector<int> sortTest = { 2, 3, 1, 4, 11, 432, 1, 213, 23 };

	int maxm = GetMaxValue<int>(sortTest, [](int a) -> int { return a; });
	int minm = GetMinValue<int>(sortTest, [](int a) -> int { return a; });
	int average = GetAverageValue<int>(sortTest, [](int a) -> int { return a; });

	EXPECT_EQ(maxm, 432);
	EXPECT_EQ(minm, 1);
	EXPECT_EQ(average, (float)(690 / 9));
}