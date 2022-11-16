#include "StudentController.h"
#include "FunctionLibrary.h"
#include "StudentModel.h"
#include "StudentView.h"
#include "Student.h"
#include <iostream>


StudentController::StudentController()
{
	m_StudentModel = nullptr;
	m_StudentView = nullptr;
}

StudentController::~StudentController()
{

}

void StudentController::Init(StudentModel* studentModel, StudentView* studentView)
{
	m_StudentModel = studentModel;
	m_StudentView = studentView;
}

void StudentController::InsertStudent(Student student)
{
	m_StudentModel->InsertData(student);
}

ScoreValue StudentController::GetSubjectValue(const std::string& subject, const std::function<int(Student)>& Value)
{
	ScoreValue Score(subject);
	Score.MaxValue = GetMaxValue<Student>(m_StudentModel->GetStudentArray(), Value);
	Score.MinValue = GetMinValue<Student>(m_StudentModel->GetStudentArray(), Value);
	Score.AverageValue = GetAverageValue<Student>(m_StudentModel->GetStudentArray(), Value);
	return Score;
}

void StudentController::SortSubject(const std::function<bool(Student, Student)>& cmp)
{
	QuickSort<Student>(m_StudentModel->GetStudentArray(), 0, m_StudentModel->GetSize() - 1, cmp);
}

void StudentController::CalcStudent()
{
	ScoreValue SubjectScore[4];
	SubjectScore[0] = GetSubjectValue("语文", [](Student student)-> int { return student.GetChinese(); });
	SubjectScore[1] = GetSubjectValue("英语", [](Student student)-> int { return student.GetEnglish(); });
	SubjectScore[2] = GetSubjectValue("数学", [](Student student)-> int { return student.GetMath(); });
	SubjectScore[3] = GetSubjectValue("总分", [](Student student)-> int { return student.GetTotal(); });
	UpdateView(SubjectScore);

	SortSubject([](Student a, Student b) -> bool { return a.GetChinese() < b.GetChinese(); });
	UpdateView("语文");
	SortSubject([](Student a, Student b) -> bool { return a.GetEnglish() < b.GetEnglish(); });
	UpdateView("英语");
	SortSubject([](Student a, Student b) -> bool { return a.GetMath() < b.GetMath(); });
	UpdateView("数学");
	SortSubject([](Student a, Student b) -> bool { return a.GetTotal() < b.GetTotal(); });
	UpdateView("总分");
}

void StudentController::UpdateView(ScoreValue SubjectScore[])
{
	m_StudentView->PrintData(SubjectScore);
}

void StudentController::UpdateView(const std::string& Subject)
{
	m_StudentView->PrintData(Subject, m_StudentModel->GetStudentArray());
}

