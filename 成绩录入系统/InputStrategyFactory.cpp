#include "InputStrategyFactory.h"
#include "InputStrategy.h"
#include "InputConsoleStrategy.h"
#include "InputCsvStrategy.h"
#include "InputJsonStrategy.h"


InputStrategyFactory::InputStrategyFactory()
{
	m_StrategyRegistry.clear();
}

InputStrategyFactory::~InputStrategyFactory()
{
	m_StrategyRegistry.clear();
}

void InputStrategyFactory::InitStrategy()
{
	InputConsoleStrategy* console = new InputConsoleStrategy();
	InputCsvStrategy* csv = new InputCsvStrategy();
	InputJsonStrategy* json = new InputJsonStrategy();
	RegisterStrategy("Console", console);
	RegisterStrategy("Csv", csv);
	RegisterStrategy("Json", json);
}

void InputStrategyFactory::RegisterStrategy(const std::string& name, InputStrategy* strategy)
{
	m_StrategyRegistry[name] = strategy;
}

InputStrategy* InputStrategyFactory::GetStrategy(const std::string& name)
{
	std::map<std::string, InputStrategy*>::iterator it;

	it = m_StrategyRegistry.find(name);
	if (it != m_StrategyRegistry.end())
	{
		return it->second;
	}

	return nullptr;
}

void InputStrategyFactory::ExecuteStrategy(const std::string& name)
{
	auto Strategy = GetStrategy(name);
	if (Strategy != nullptr)
	{
		Strategy->DoAlgorithm();
	}
}
