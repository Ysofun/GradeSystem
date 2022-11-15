#include "InputJsonStrategy.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Student.h"
#include <vector>
#include "StudentController.h"

InputJsonStrategy::~InputJsonStrategy()
{

}

void InputJsonStrategy::DoAlgorithm()
{
	std::cout << "请输入json文件路径" << std::endl;
	std::string FilePath;
	std::cin >> FilePath;
	std::ifstream infile(FilePath);
	if (!infile)
	{
		std::cout << "打开json文件失败" << std::endl;
		return;
	}

	Student student;
	std::string line;
	bool bIsEffectiveName = false;
	while (getline(infile, line))
	{
		line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
		std::istringstream sin(line);
		std::vector<std::string> fields;
		std::string field;
		while (getline(sin, field, ':'))
		{
			field.erase(std::remove(field.begin(), field.end(), '"'), field.end());
			fields.emplace_back(field);
		}
		if (fields[0] == "name")
		{
			fields[1].pop_back();
			bIsEffectiveName = fields[1] != "";
			if (bIsEffectiveName) { student.SetName(fields[1]); }
		}
		else if (fields[0] == "chinese" && bIsEffectiveName)
		{
			student.SetChinese(atoi(fields[1].c_str()));
		}
		else if (fields[0] == "english" && bIsEffectiveName)
		{
			student.SetEnglish(atoi(fields[1].c_str()));
		}
		else if (fields[0] == "math" && bIsEffectiveName)
		{
			student.SetMath(atoi(fields[1].c_str()));
			student.UpdateTotal();
			StudentController::GetInstance()->InsertStudent(student);
		}
	}
	StudentController::GetInstance()->CalcStudent();
}

