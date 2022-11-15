#include "OutputHtmlStrategy.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include "Student.h"

void OutputHtmlStrategy::DoAlgorithm()
{
	
}

void OutputHtmlStrategy::DoAlgorithm(ScoreValue SubjectScore[])
{
	std::ofstream outfile("Result/Result.html");
	if (!outfile)
	{
		std::cout << "���ļ�ʧ��" << std::endl;
		return;
	}

	outfile << "<html>" << std::endl;
	outfile << "<body>" << std::endl;
	outfile << "<table border = 1>" << std::endl;
	outfile << "<tr>" << std::endl;
	outfile << "<td>" << "��Ŀ" << "</td>" << std::endl;
	outfile << "<td>" << "��߷�" << "</td>" << std::endl;
	outfile << "<td>" << "��ͷ�" << "</td>" << std::endl;
	outfile << "<td>" << "ƽ����" << "</td>" << std::endl;
	outfile << "</tr>" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		outfile << "<tr>" << std::endl;
		outfile << "<td>" << SubjectScore[i].Subject << "</td>" << std::endl;
		outfile << "<td>" << SubjectScore[i].MaxValue << "</td>" << std::endl;
		outfile << "<td>" << SubjectScore[i].MinValue << "</td>" << std::endl;
		outfile << "<td>" << SubjectScore[i].AverageValue << "</td>" << std::endl;
		outfile << "</tr>" << std::endl;
	}
	outfile << "</table>" << std::endl;
	outfile << "</body>" << std::endl;
	outfile << "</html>" << std::endl;
}

void OutputHtmlStrategy::DoAlgorithm(std::string Subject, const std::vector<Student>& Students)
{
	std::string FilePath = "Result/" + Subject + "Result.html";
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

	outfile << "<html>" << std::endl;
	outfile << "<body>" << std::endl;
	outfile << "<table border = 1>" << std::endl;
	outfile << "<tr>" << std::endl;
	outfile << "<td>" << "����" << "</td>" << std::endl;
	outfile << "<td>" << Subject << "</td>" << std::endl;
	outfile << "</tr>" << std::endl;
	for (int i = 0; i < Students.size(); i++)
	{
		outfile << "<tr>" << std::endl;
		outfile << "<td>" << Students[i].GetName() << "</td>" << std::endl;
		outfile << "<td>" << Value(Students[i]) << "</td>" << std::endl;
		outfile << "</tr>" << std::endl;
	}
	outfile << "</table>" << std::endl;
	outfile << "</body>" << std::endl;
	outfile << "</html>" << std::endl;
}
