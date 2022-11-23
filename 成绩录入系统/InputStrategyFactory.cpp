#include "InputStrategyFactory.h"
#include "InputStrategy.h"
#include "InputConsoleStrategy.h"
#include "InputCsvStrategy.h"
#include "InputJsonStrategy.h"

REGISTER_STRATEGY(InputConsoleStrategy, "Console");
REGISTER_STRATEGY(InputCsvStrategy, "Csv");
REGISTER_STRATEGY(InputJsonStrategy, "Json");

InputStrategy* InputStrategyFactory::GetStrategy(const std::string& name)
{
	if (m_StrategyRegistry.find(name) == m_StrategyRegistry.end())
	{
		throw std::invalid_argument("This name id not exist!");
	}

	return m_StrategyRegistry[name]();
}

void InputStrategyFactory::ExecuteStrategy(const std::string& name)
{
	auto Strategy = GetStrategy(name);
	if (Strategy != nullptr)
	{
		Strategy->DoAlgorithm();
	}
}
