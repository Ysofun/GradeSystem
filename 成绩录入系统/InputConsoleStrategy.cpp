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
	std::cout << "�밴������,����,Ӣ��,��ѧ�ĸ�ʽ����" << std::endl;
	std::cout << "ÿһ�н�����һ���˵�����" << std::endl;
	std::cout << "���һ����ĳ�������п�ȱ���뱣֤��ʽ��ȷ������" << std::endl;

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
		if (fields[0] != "")
		{
			int chinese = atoi(fields[1].c_str());
			int english = atoi(fields[2].c_str());
			int math = atoi(fields[3].c_str());
			StudentController::GetInstance()->InsertStudent(Student(fields[0], chinese, english, math));
		}
	}

	StudentController::GetInstance()->CalcStudent();
}