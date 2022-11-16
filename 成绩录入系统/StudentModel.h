#pragma once
#include <vector>
#include <map>
#include <functional>
#include <string>

class Student;

/* Model���ŵײ����� */
class StudentModel
{
private:
	std::vector<Student> Students;
	std::map<std::string, int> IdxOfStudent;

public:
	StudentModel();
	~StudentModel();

	/* ����Ŀ�����������в��빦�ܣ�����ͨ��map��⵽�Ƿ��Ѿ����� */
	void InsertData(Student student);

	std::vector<Student>& GetStudentArray();
	int GetSize() const;
};