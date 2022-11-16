#pragma once
#include "OutputStrategy.h"

/* 输出Csv格式类 */
class OutputCsvStrategy : public OutputStrategy
{

public:
	void DoAlgorithm(ScoreValue[]) override;
	void DoAlgorithm(std::string, const std::vector<Student>&) override;
};

