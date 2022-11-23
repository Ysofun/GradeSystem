/*
* ��ϸ���ܿ���README.txt�ļ��в���
*/

#include "StudentController.h"
#include "StudentModel.h"
#include "StudentView.h"
#include "InputStrategyFactory.h"
#include "OutputStrategyFactory.h"

int main()
{
	StudentModel* studentModel = new StudentModel();
	StudentView* studentView = new StudentView();
	StudentController::GetInstance()->Init(studentModel, studentView);
	studentView->GetDataInput();

	return 0;
}