#pragma once
#include <map>
#include <string>
#include "SingletonInstance.h"
#include <vector>
#include "ScoreValue.h"

class OutputStrategy;
class Student;

/* 输出策略工厂 */
class OutputStrategyFactory : public SingletonInstance<OutputStrategyFactory>
{
	friend class SingletonInstance<OutputStrategyFactory>;
public:
	~OutputStrategyFactory();
	OutputStrategyFactory(const OutputStrategyFactory&) = delete;
	const OutputStrategyFactory& operator=(const OutputStrategyFactory&) = delete;

	/* 初始化所有输出策略 */
	void InitStrategy();
	
	/* 将输出策略注册到map中 */
	void RegisterStrategy(const std::string& name, OutputStrategy* strategy);
	
	/* 获得策略 */
	OutputStrategy* GetStrategy(const std::string& name);
	
	/* 执行策略 */
	void ExecuteStrategy(const std::string& name, ScoreValue SubjectScore[]);
	void ExecuteStrategy(const std::string& name, const std::string& Subject, const std::vector<Student>& Students);

private:
	OutputStrategyFactory();
	std::map<std::string, OutputStrategy*> m_StrategyRegistry;
};