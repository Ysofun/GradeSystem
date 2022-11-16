#pragma once
#include <map>
#include <string>
#include "SingletonInstance.h"

class InputStrategy;

/* �������ģʽ���� */
class InputStrategyFactory : public SingletonInstance<InputStrategyFactory>
{
	friend class SingletonInstance<InputStrategyFactory>;
public:
	~InputStrategyFactory();
	InputStrategyFactory(const InputStrategyFactory&) = delete;
	const InputStrategyFactory& operator=(const InputStrategyFactory&) = delete;

	/* ��ʼ������������� */
	void InitStrategy();

	/* ���������ע�ᵽmap�� */
	void RegisterStrategy(const std::string& name, InputStrategy* strategy);
	
	/* ���������� */
	InputStrategy* GetStrategy(const std::string& name);
	
	/* ִ�в��� */
	void ExecuteStrategy(const std::string& name);

private:
	InputStrategyFactory();
	std::map<std::string, InputStrategy*> m_StrategyRegistry;
};