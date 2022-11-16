#pragma once
#include <map>
#include <string>
#include "SingletonInstance.h"

class InputStrategy;

/* 输入策略模式工厂 */
class InputStrategyFactory : public SingletonInstance<InputStrategyFactory>
{
	friend class SingletonInstance<InputStrategyFactory>;
public:
	~InputStrategyFactory();
	InputStrategyFactory(const InputStrategyFactory&) = delete;
	const InputStrategyFactory& operator=(const InputStrategyFactory&) = delete;

	/* 初始化所有输入策略 */
	void InitStrategy();

	/* 将输入策略注册到map中 */
	void RegisterStrategy(const std::string& name, InputStrategy* strategy);
	
	/* 获得输入策略 */
	InputStrategy* GetStrategy(const std::string& name);
	
	/* 执行策略 */
	void ExecuteStrategy(const std::string& name);

private:
	InputStrategyFactory();
	std::map<std::string, InputStrategy*> m_StrategyRegistry;
};