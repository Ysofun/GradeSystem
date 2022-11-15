#pragma once
#include <vector>
#include <map>
#include <functional>
#include <string>

class Student;

class StudentModel
{
private:
	std::vector<Student> Students;
	std::map<std::string, int> IdxOfStudent;

public:
	StudentModel();
	~StudentModel();

	void InsertData(Student student);

	std::vector<Student>& GetStudentArray();
	int GetSize() const;
};