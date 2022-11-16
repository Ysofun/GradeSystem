#pragma once
#include <string>

/* ѧ�Ƴɼ����� */
struct ScoreValue
{
	std::string Subject;
	int MaxValue;
	int MinValue;
	float AverageValue;
	ScoreValue() : Subject(""), MaxValue(0), MinValue(0), AverageValue(0.f) {}
	ScoreValue(const std::string& subject) : Subject(subject), MaxValue(0), MinValue(0), AverageValue(0.f) {}
	ScoreValue(const std::string& subject, int maxvalue, int minvalue, int averagevalue)
		: Subject(subject), MaxValue(maxvalue), MinValue(minvalue), AverageValue(averagevalue) {}
};