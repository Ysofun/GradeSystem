#pragma once
#include "ScoreValue.h"
#include <string>
#include <vector>

class Student;

/* 输出策略抽象基类 */
class OutputStrategy
{
public:
	virtual ~OutputStrategy() = default;
	virtual void DoAlgorithm(ScoreValue[]) = 0;
	virtual void DoAlgorithm(std::string, const std::vector<Student>&) = 0;
};