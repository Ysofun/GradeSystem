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
		std::cout << "���ļ�ʧ��" << std::endl;
		return;
	}

	outfile << "��Ŀ,��߷�,��ͷ�,ƽ����" << std::endl;
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
		std::cout << "���ļ�ʧ��" << std::endl;
		return;
	}

	std::function<int(Student)> Value;
	if (Subject == "����") { Value = [](Student a) -> int { return a.GetChinese(); }; }
	else if (Subject == "Ӣ��") { Value = [](Student a) -> int { return a.GetEnglish(); }; }
	else if (Subject == "��ѧ") { Value = [](Student a) -> int { return a.GetMath(); }; }
	else if (Subject == "�ܷ�") { Value = [](Student a) -> int { return a.GetTotal(); }; }

	outfile << "����," << Subject << std::endl;
	for (int i = 0; i < Students.size(); i++)
	{
		outfile << Students[i].GetName() << "," << Value(Students[i]) << std::endl;
	}
}
