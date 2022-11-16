#pragma once
#include "SingletonInstance.h"
#include "ScoreValue.h"
#include <functional>

class Student;
class StudentView;
class StudentModel;

/* 实现数据的计算 */
class StudentController : public SingletonInstance<StudentController>
{
	friend class SingletonInstance<StudentController>;
public:
	~StudentController();
	StudentController(const StudentController&) = delete;
	const StudentController& operator=(const StudentController&) = delete;

	/* 初始化Model和View */
	void Init(StudentModel* studentModel, StudentView* studentView);

	/* 插入数据 */
	void InsertStudent(Student);

	/* 获得学科的最高分、最低分、平均分 */
	ScoreValue GetSubjectValue(const std::string&, const std::function<int(Student)>&);
	/* 对每个学科的分数进行排序 */
	void SortSubject(const std::function<bool(Student, Student)>&);
	/* 计算函数 */
	void CalcStudent();
	
	/* 更新输出 */
	void UpdateView(ScoreValue SubjectScore[]);
	void UpdateView(const std::string&);

private:
	StudentController();

	StudentView* m_StudentView;
	StudentModel* m_StudentModel;
};