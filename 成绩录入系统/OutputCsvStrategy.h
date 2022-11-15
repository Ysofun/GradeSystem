#pragma once
#include "OutputStrategy.h"


class OutputCsvStrategy : public OutputStrategy
{

public:
	void DoAlgorithm() override;
	void DoAlgorithm(ScoreValue[]) override;
	void DoAlgorithm(std::string, const std::vector<Student>&) override;
};

