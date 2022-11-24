#include "InputStrategyFactory.h"
#include "InputStrategy.h"
#include "InputConsoleStrategy.h"
#include "InputCsvStrategy.h"
#include "InputJsonStrategy.h"

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

REGISTER_INPUT_STRATEGY(InputConsoleStrategy, "Console");
REGISTER_INPUT_STRATEGY(InputCsvStrategy, "Csv");
REGISTER_INPUT_STRATEGY(InputJsonStrategy, "Json");