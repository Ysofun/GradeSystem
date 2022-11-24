#pragma once
#include <map>
#include <string>
#include "SingletonInstance.h"
#include <functional>
#include <type_traits>

class InputStrategy;

/* 输入策略模式工厂 */
class InputStrategyFactory : public SingletonInstance<InputStrategyFactory>
{
	friend class SingletonInstance<InputStrategyFactory>;
public:
	~InputStrategyFactory() {}
	InputStrategyFactory(const InputStrategyFactory&) = delete;
	const InputStrategyFactory& operator=(const InputStrategyFactory&) = delete;

	template<typename T, 
		class = typename std::enable_if_t<std::is_base_of<InputStrategy, std::decay_t<T>>::value>>
	struct RegisterTool
	{
		template<typename... Args>
		RegisterTool(const std::string& name, Args... args)
		{
			InputStrategyFactory::GetInstance().
				m_StrategyRegistry.emplace(name, [=] { return new T(args...); });
		}
	};
	
	/* 获得输入策略 */
	InputStrategy* GetStrategy(const std::string& name);
	
	/* 执行策略 */
	void ExecuteStrategy(const std::string& name);

private:
	InputStrategyFactory() {}
	std::map<std::string, std::function<InputStrategy*()>> m_StrategyRegistry;
};

#define REGISTER_STRATEGY_NAME(T) REG_STR_##T##_
#define REGISTER_INPUT_STRATEGY(T, key, ...) \
static InputStrategyFactory::RegisterTool<T> REGISTER_STRATEGY_NAME(T)(key, ##__VA_ARGS__)