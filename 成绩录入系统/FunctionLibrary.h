#pragma once
#include <string>
#include <vector>
#include <functional>

#pragma region 模板函数
// 模板函数定义和声明都必须要在.h文件中
template<typename T>
void QuickSort(std::vector<T>& SourceArray, int l, int r, const std::function<bool(T, T)>& cmp)
{
	if (l >= r) { return; }

	int mid = rand() % (r - l + 1) + l;
	std::swap(SourceArray[l], SourceArray[mid]);
	T pivot = SourceArray[l];

	int i = l, j = r;
	while (i < j)
	{
		while (i < j && cmp(pivot, SourceArray[j])) { j--; }
		if (i < j) { SourceArray[i++] = SourceArray[j]; }

		while (i < j && cmp(SourceArray[i], pivot)) { i++; }
		if (i < j) { SourceArray[j--] = SourceArray[i]; }
	}

	SourceArray[i] = pivot;
	QuickSort(SourceArray, l, i - 1, cmp);
	QuickSort(SourceArray, i + 1, r, cmp);
}

template<typename T>
int GetMaxValue(const std::vector<T>& SourceArray, const std::function<int(T)>& GetValue)
{
	int MaxValue = 0;
	for (int i = 0; i < SourceArray.size(); i++)
	{
		MaxValue = std::max(MaxValue, GetValue(SourceArray[i]));
	}
	return MaxValue;
}

template<typename T>
int GetMinValue(const std::vector<T>& SourceArray, const std::function<int(T)>& GetValue)
{
	int MinValue = 1000;
	for (int i = 0; i < SourceArray.size(); i++)
	{
		MinValue = std::min(MinValue, GetValue(SourceArray[i]));
	}
	return MinValue;
}

template<typename T>
float GetAverageValue(const std::vector<T>& SourceArray, const std::function<int(T)>& GetValue)
{
	int ValueSum = 0;
	for (int i = 0; i < SourceArray.size(); i++)
	{
		ValueSum += GetValue(SourceArray[i]);
	}
	return (float)ValueSum / SourceArray.size();
}
#pragma endregion