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

/* 插入数据并检测是否已存在，若存在则修改 */
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

/* 获得数组 */
std::vector<Student>& StudentModel::GetStudentArray()
{
	return Students;
}

/* 获得数组大小 */
int StudentModel::GetSize() const
{
	return Students.size();
}

