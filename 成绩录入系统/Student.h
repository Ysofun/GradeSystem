#pragma once
#include <string>


class Student
{
private:
	
	std::string m_Name;
	int m_Chinese;
	int m_Math;
	int m_English;
	int m_Total;

public:

	// 构造函数及重载
	Student(std::string name, int chinese, int english, int math)
		: m_Name(name), m_Chinese(chinese), m_English(english), m_Math(math)
	{
		m_Total = m_Chinese + m_English + m_Math;
	}
	
	Student(std::string name)
		: m_Name(name), m_Chinese(0), m_English(0), m_Math(0)
	{
		m_Total = m_Chinese + m_English + m_Math;
	}
	
	~Student() {}

	inline std::string GetName() const { return m_Name; }
	inline int GetChinese() const { return m_Chinese; }
	inline int GetEnglish() const { return m_English; }
	inline int GetMath() const { return m_Math; }
	inline int GetTotal() const { return m_Total; }

	void SetName(const std::string& name) { m_Name = name; }
	void SetChinese(int chinese) { m_Chinese = chinese; }
	void SetEnglish(int english) { m_English = english; }
	void SetMath(int math) { m_Math = math; }
	void UpdateTotal() { m_Total = m_Chinese + m_English + m_Math; }
};