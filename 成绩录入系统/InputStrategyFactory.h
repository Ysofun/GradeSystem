#pragma once
#include <map>
#include <string>
#include "SingletonInstance.h"
#include <functional>

class InputStrategy;

/* �������ģʽ���� */
class InputStrategyFactory : public SingletonInstance<InputStrategyFactory>
{
	friend class SingletonInstance<InputStrategyFactory>;
public:
	~InputStrategyFactory() = default;
	InputStrategyFactory(const InputStrategyFactory&) = delete;
	const InputStrategyFactory& operator=(const InputStrategyFactory&) = delete;

	template<typename T>
	struct RegisterTool
	{
		template<typename... Args>
		RegisterTool(const std::string& name, Args... args)
		{
			InputStrategyFactory::GetInstance()->m_StrategyRegistry.emplace(name, [=] { return new T(args...); });
		}
	};
	
	/* ���������� */
	InputStrategy* GetStrategy(const std::string& name);
	
	/* ִ�в��� */
	void ExecuteStrategy(const std::string& name);

private:
	InputStrategyFactory() {}
	std::map<std::string, std::function<InputStrategy*()>> m_StrategyRegistry;
};

#define REGISTER_STRATEGY_NAME(T) REG_STR_##T##_
#define REGISTER_STRATEGY(T, key, ...) \
static InputStrategyFactory::RegisterTool<T> REGISTER_STRATEGY_NAME(T)(key, ##__VA_ARGS__)