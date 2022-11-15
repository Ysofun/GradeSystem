#pragma once
#include <map>
#include <string>
#include "SingletonInstance.h"
#include <vector>
#include "ScoreValue.h"

class OutputStrategy;
class Student;

class OutputStrategyFactory : public SingletonInstance<OutputStrategyFactory>
{
	friend class SingletonInstance<OutputStrategyFactory>;
public:
	~OutputStrategyFactory();
	OutputStrategyFactory(const OutputStrategyFactory&) = delete;
	const OutputStrategyFactory& operator=(const OutputStrategyFactory&) = delete;

	void InitStrategy();
	void RegisterStrategy(const std::string& name, OutputStrategy* strategy);
	OutputStrategy* GetStrategy(const std::string& name);
	void ExecuteStrategy(const std::string& name, ScoreValue SubjectScore[]);
	void ExecuteStrategy(const std::string& name, const std::string& Subject, const std::vector<Student>& Students);

private:
	OutputStrategyFactory();
	std::map<std::string, OutputStrategy*> m_StrategyRegistry;
};