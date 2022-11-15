#pragma once
#include <string>
#include "ScoreValue.h"
#include <vector>

class Student;


class StudentView
{
private:
	std::string m_InputFileType;
	std::string m_OutputFileType;

public:
	void GetDataInput();
	void PrintData(ScoreValue SubjectScore[]);
	void PrintData(const std::string& Subject, const std::vector<Student>& Students);
};