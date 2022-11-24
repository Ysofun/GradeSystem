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

	ASSERT_TRUE(InputStrategyFactory::GetInstance().GetStrategy("Csv"));
	ASSERT_TRUE(InputStrategyFactory::GetInstance().GetStrategy("Console"));
}