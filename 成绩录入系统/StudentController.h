#pragma once
#include "SingletonInstance.h"
#include "ScoreValue.h"
#include <functional>

class Student;
class StudentView;
class StudentModel;

class StudentController : public SingletonInstance<StudentController>
{
	friend class SingletonInstance<StudentController>;
public:
	~StudentController();
	StudentController(const StudentController&) = delete;
	const StudentController& operator=(const StudentController&) = delete;

	void Init(StudentModel* studentModel, StudentView* studentView);
	void InsertStudent(Student);
	ScoreValue GetSubjectValue(const std::string&, const std::function<int(Student)>&);
	void SortSubject(const std::function<bool(Student, Student)>&);
	void CalcStudent();
	void UpdateView(ScoreValue SubjectScore[]);
	void UpdateView(const std::string&);

private:
	StudentController();

	StudentView* m_StudentView;
	StudentModel* m_StudentModel;
};