#pragma once
#include <map>
#include <string>
#include <vector>
#include <functional>
#include "ScoreValue.h"
#include "SingletonInstance.h"

class OutputStrategy;
class Student;

/* 输出策略工厂 */
class OutputStrategyFactory : public SingletonInstance<OutputStrategyFactory>
{
	friend class SingletonInstance<OutputStrategyFactory>;
public:
	~OutputStrategyFactory() {}
	OutputStrategyFactory(const OutputStrategyFactory&) = delete;
	const OutputStrategyFactory& operator=(const OutputStrategyFactory&) = delete;

	template<typename T>
	struct RegisterTool
	{
		template<typename... Args>
		RegisterTool(const std::string& name, Args... args)
		{
			OutputStrategyFactory::GetInstance().m_StrategyRegistry.emplace(name, [=] { return new T(args...); });
		}
	};
	
	/* 获得策略 */
	OutputStrategy* GetStrategy(const std::string& name);
	
	/* 执行策略 */
	void ExecuteStrategy(const std::string& name, ScoreValue SubjectScore[]);
	void ExecuteStrategy(const std::string& name, const std::string& Subject, const std::vector<Student>& Students);

private:
	OutputStrategyFactory() {}
	std::map<std::string, std::function<OutputStrategy*()>> m_StrategyRegistry;
};

#define REGISTER_STRATEGY_NAME(T) REG_STR_##T##_
#define REGISTER_OUTPUT_STRATEGY(T, key, ...) \
static OutputStrategyFactory::RegisterTool<T> REGISTER_STRATEGY_NAME(T)(key, ##__VA_ARGS__)