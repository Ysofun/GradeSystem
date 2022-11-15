#pragma once
#include "ScoreValue.h"
#include <string>
#include <vector>

class Student;

class OutputStrategy
{
public:
	virtual ~OutputStrategy() = default;
	virtual void DoAlgorithm() = 0;
	virtual void DoAlgorithm(ScoreValue[]) = 0;
	virtual void DoAlgorithm(std::string, const std::vector<Student>&) = 0;
};