/*
* 详细介绍可在README.txt文件中查阅
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