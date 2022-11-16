#pragma once
#include "SingletonInstance.h"
#include "ScoreValue.h"
#include <functional>

class Student;
class StudentView;
class StudentModel;

/* ʵ�����ݵļ��� */
class StudentController : public SingletonInstance<StudentController>
{
	friend class SingletonInstance<StudentController>;
public:
	~StudentController();
	StudentController(const StudentController&) = delete;
	const StudentController& operator=(const StudentController&) = delete;

	/* ��ʼ��Model��View */
	void Init(StudentModel* studentModel, StudentView* studentView);

	/* �������� */
	void InsertStudent(Student);

	/* ���ѧ�Ƶ���߷֡���ͷ֡�ƽ���� */
	ScoreValue GetSubjectValue(const std::string&, const std::function<int(Student)>&);
	/* ��ÿ��ѧ�Ƶķ����������� */
	void SortSubject(const std::function<bool(Student, Student)>&);
	/* ���㺯�� */
	void CalcStudent();
	
	/* ������� */
	void UpdateView(ScoreValue SubjectScore[]);
	void UpdateView(const std::string&);

private:
	StudentController();

	StudentView* m_StudentView;
	StudentModel* m_StudentModel;
};