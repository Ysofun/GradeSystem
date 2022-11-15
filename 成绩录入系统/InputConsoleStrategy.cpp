#include "InputConsoleStrategy.h"
#include "StudentController.h"
#include <iostream>
#include <vector>
#include <sstream>
#include "Student.h"
#include "FunctionLibrary.h"


InputConsoleStrategy::~InputConsoleStrategy()
{
	std::cout << "ConsoleStrategy Destructor" << std::endl;
}

void InputConsoleStrategy::DoAlgorithm()
{
	std::cout << "请按照姓名,语文,英语,数学的格式输入" << std::endl;
	std::cout << "每一行仅输入一个人的数据" << std::endl;
	std::cout << "如果一行中某项数据有空缺，请保证格式正确并留空" << std::endl;

	std::string OneLineInfomation;
	while (getline(std::cin, OneLineInfomation))
	{
		std::istringstream sin(OneLineInfomation);
		std::vector<std::string> fields;
		std::string field;
		while (getline(sin, field, ','))
		{
			fields.emplace_back(field);
		}
		if (fields.size() != 0 && fields[0] != "")
		{
			int chinese = fields.size() >= 2 ? atoi(fields[1].c_str()) : 0;
			int english = fields.size() >= 3 ? atoi(fields[2].c_str()) : 0;
			int math = fields.size() == 4 ? atoi(fields[3].c_str()) : 0;
			StudentController::GetInstance()->InsertStudent(Student(fields[0], chinese, english, math));
		}
	}

	StudentController::GetInstance()->CalcStudent();
}