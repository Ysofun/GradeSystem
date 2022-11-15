#include "StudentController.h"
#include "StudentModel.h"
#include "StudentView.h"
#include "InputStrategyFactory.h"
#include "OutputStrategyFactory.h"

int main()
{
	InputStrategyFactory::GetInstance()->InitStrategy();
	OutputStrategyFactory::GetInstance()->InitStrategy();

	StudentModel* studentModel = new StudentModel();
	StudentView* studentView = new StudentView();
	StudentController::GetInstance()->Init(studentModel, studentView);
	studentView->GetDataInput();

	return 0;
}