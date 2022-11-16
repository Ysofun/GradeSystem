#pragma once
#include <vector>
#include <map>
#include <functional>
#include <string>

class Student;

/* Model层存放底层数据 */
class StudentModel
{
private:
	std::vector<Student> Students;
	std::map<std::string, int> IdxOfStudent;

public:
	StudentModel();
	~StudentModel();

	/* 因题目描述，仅具有插入功能，可以通过map检测到是否已经插入 */
	void InsertData(Student student);

	std::vector<Student>& GetStudentArray();
	int GetSize() const;
};