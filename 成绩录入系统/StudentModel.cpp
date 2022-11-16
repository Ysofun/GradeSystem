#include "StudentModel.h"
#include "Student.h"


StudentModel::StudentModel()
{
	Students.clear();
	IdxOfStudent.clear();
}

StudentModel::~StudentModel()
{
	Students.clear();
	IdxOfStudent.clear();
}

void StudentModel::InsertData(Student student)
{
	std::map<std::string, int>::iterator it;
	it = IdxOfStudent.find(student.GetName());
	if (it != IdxOfStudent.end())
	{
		Students[it->second] = student;
		Students[it->second].UpdateTotal();
	}
	else
	{
		student.UpdateTotal();
		Students.emplace_back(student);
		IdxOfStudent[student.GetName()] = Students.size() - 1;
	}
}

std::vector<Student>& StudentModel::GetStudentArray()
{
	return Students;
}

int StudentModel::GetSize() const
{
	return Students.size();
}

