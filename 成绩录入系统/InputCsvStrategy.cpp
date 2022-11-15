#include "InputCsvStrategy.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Student.h"
#include "StudentController.h"


InputCsvStrategy::~InputCsvStrategy()
{

}

void InputCsvStrategy::DoAlgorithm()
{
	std::cout << "请输入csv文件路径" << std::endl;
	std::string FilePath;
	std::cin >> FilePath;
	std::ifstream infile(FilePath);
	if (!infile)
	{
		std::cout << "打开Csv文件失败" << std::endl;
		return;
	}

	std::string line;
	getline(infile, line);
	while (getline(infile, line))
	{
		std::istringstream sin(line);
		std::vector<std::string> fields;
		std::string field;
		while (getline(sin, field, ','))
		{
			fields.emplace_back(field);
		}

		if (fields[0] != "")
		{
			int chinese = fields.size() >= 2 ? atoi(fields[1].c_str()) : 0;
			int english = fields.size() >= 3 ? atoi(fields[2].c_str()) : 0;
			int math = fields.size() == 4? atoi(fields[3].c_str()) : 0;
			StudentController::GetInstance()->InsertStudent(Student(fields[0], chinese, english, math));
		}
	}

	StudentController::GetInstance()->CalcStudent();
}

