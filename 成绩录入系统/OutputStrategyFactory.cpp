#include "OutputStrategyFactory.h"
#include "OutputStrategy.h"
#include "Student.h"
#include "OutputCsvStrategy.h"
#include "OutputHtmlStrategy.h"

REGISTER_STRATEGY(OutputCsvStrategy, "Csv");
REGISTER_STRATEGY(OutputHtmlStrategy, "Html");

OutputStrategy* OutputStrategyFactory::GetStrategy(const std::string& name)
{
	if (m_StrategyRegistry.find(name) == m_StrategyRegistry.end())
	{
		throw std::invalid_argument("This name is not exist!");
	}
	return m_StrategyRegistry[name]();
}

void OutputStrategyFactory::ExecuteStrategy(const std::string& name, ScoreValue SubjectScore[])
{
	auto Strategy = GetStrategy(name);
	if (Strategy != nullptr)
	{
		Strategy->DoAlgorithm(SubjectScore);
	}
}

void OutputStrategyFactory::ExecuteStrategy(const std::string& name, const std::string& Subject, const std::vector<Student>& Students)
{
	auto Strategy = GetStrategy(name);
	if (Strategy != nullptr)
	{
		Strategy->DoAlgorithm(Subject, Students);
	}
}
