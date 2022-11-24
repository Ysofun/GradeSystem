#include "pch.h"
#include "InputStrategyFactory.h"
#include "OutputStrategyFactory.h"
#include "InputCsvStrategy.h"
#include "InputConsoleStrategy.h"
#include "InputJsonStrategy.h"
#include "OutputCsvStrategy.h"
#include "OutputHtmlStrategy.h"

TEST(FactoryTest, staticConstruct)
{
	EXPECT_STREQ(typeid(InputStrategyFactory::GetInstance()).name(), "class InputStrategyFactory");
	EXPECT_STREQ(typeid(OutputStrategyFactory::GetInstance()).name(), "class OutputStrategyFactory");

	ASSERT_TRUE(dynamic_cast<InputCsvStrategy*>(InputStrategyFactory::GetInstance().GetStrategy("Csv")));
	ASSERT_TRUE(dynamic_cast<InputConsoleStrategy*>(InputStrategyFactory::GetInstance().GetStrategy("Console")));
	ASSERT_TRUE(dynamic_cast<InputJsonStrategy*>(InputStrategyFactory::GetInstance().GetStrategy("Json")));

	ASSERT_TRUE(dynamic_cast<OutputCsvStrategy*>(OutputStrategyFactory::GetInstance().GetStrategy("Csv")));
	ASSERT_TRUE(dynamic_cast<OutputHtmlStrategy*>(OutputStrategyFactory::GetInstance().GetStrategy("Html")));
}