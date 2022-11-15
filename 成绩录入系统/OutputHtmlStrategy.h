#pragma once
#include "OutputStrategy.h"


class OutputHtmlStrategy : public OutputStrategy
{

public:
	void DoAlgorithm() override;
	void DoAlgorithm(ScoreValue[]) override;
	void DoAlgorithm(std::string, const std::vector<Student>&) override;
};

