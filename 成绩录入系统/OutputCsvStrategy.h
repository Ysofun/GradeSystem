#pragma once
#include "OutputStrategy.h"

/* ���Csv��ʽ�� */
class OutputCsvStrategy : public OutputStrategy
{

public:
	void DoAlgorithm(ScoreValue[]) override;
	void DoAlgorithm(std::string, const std::vector<Student>&) override;
};

