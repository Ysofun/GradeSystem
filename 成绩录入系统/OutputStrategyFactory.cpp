#include "OutputStrategyFactory.h"
#include "OutputStrategy.h"
#include "Student.h"
#include "OutputCsvStrategy.h"
#include "OutputHtmlStrategy.h"


OutputStrategyFactory::OutputStrategyFactory()
{
	m_StrategyRegistry.clear();
}

OutputStrategyFactory::~OutputStrategyFactory()
{
	m_StrategyRegistry.clear();
}

void OutputStrategyFactory::InitStrategy()
{
	OutputCsvStrategy* csv = new OutputCsvStrategy();
	OutputHtmlStrategy* html = new OutputHtmlStrategy();
	RegisterStrategy("Csv", csv);
	RegisterStrategy("Html", html);
}

void OutputStrategyFactory::RegisterStrategy(const std::string& name, OutputStrategy* strategy)
{
	m_StrategyRegistry[name] = strategy;
}

OutputStrategy* OutputStrategyFactory::GetStrategy(const std::string& name)
{
	std::map<std::string, OutputStrategy*>::iterator it;
	it = m_StrategyRegistry.find(name);

	if (it != m_StrategyRegistry.end())
	{
		return it->second;
	}
	return nullptr;
}

void OutputStrategyFactory::ExecuteStrategy(const std::string& name, ScoreValue SubjectScore[])
{
	GetStrategy(name)->DoAlgorithm(SubjectScore);
}

void OutputStrategyFactory::ExecuteStrategy(const std::string& name, const std::string& Subject, const std::vector<Student>& Students)
{
	GetStrategy(name)->DoAlgorithm(Subject, Students);
}
