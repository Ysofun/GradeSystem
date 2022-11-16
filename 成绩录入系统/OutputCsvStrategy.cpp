#include "OutputCsvStrategy.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include "Student.h"

void OutputCsvStrategy::DoAlgorithm(ScoreValue SubjectScore[])
{
	std::ofstream outfile("Result/Result.csv");
	if (!outfile)
	{
		std::cout << "打开文件失败" << std::endl;
		return;
	}

	outfile << "科目,最高分,最低分,平均分" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		outfile << SubjectScore[i].Subject << ',' << SubjectScore[i].MaxValue << ',' << 
			SubjectScore[i].MinValue << ',' << SubjectScore[i].AverageValue << std::endl;
	}
}

void OutputCsvStrategy::DoAlgorithm(std::string Subject, const std::vector<Student>& Students)
{
	std::string FilePath = "Result/" + Subject + "Result.csv";
	std::ofstream outfile(FilePath);
	if (!outfile)
	{
		std::cout << "打开文件失败" << std::endl;
		return;
	}

	std::function<int(Student)> Value;
	if (Subject == "语文") { Value = [](Student a) -> int { return a.GetChinese(); }; }
	else if (Subject == "英语") { Value = [](Student a) -> int { return a.GetEnglish(); }; }
	else if (Subject == "数学") { Value = [](Student a) -> int { return a.GetMath(); }; }
	else if (Subject == "总分") { Value = [](Student a) -> int { return a.GetTotal(); }; }

	outfile << "姓名," << Subject << std::endl;
	for (int i = 0; i < Students.size(); i++)
	{
		outfile << Students[i].GetName() << "," << Value(Students[i]) << std::endl;
	}
}
