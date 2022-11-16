#pragma once
#include <string>
#include "ScoreValue.h"
#include <vector>

class Student;

/* View层负责数据的输入和输出 */
class StudentView
{
private:
	std::string m_InputFileType;
	std::string m_OutputFileType;

public:
	/* 输入 */
	void GetDataInput();
	
	/* 输出 */
	void PrintData(ScoreValue SubjectScore[]);
	void PrintData(const std::string& Subject, const std::vector<Student>& Students);
};