#pragma once
#include "OutputStrategy.h"

/* Html��ʽ����� */
class OutputHtmlStrategy : public OutputStrategy
{

public:
	void DoAlgorithm(ScoreValue[]) override;
	void DoAlgorithm(std::string, const std::vector<Student>&) override;
};

