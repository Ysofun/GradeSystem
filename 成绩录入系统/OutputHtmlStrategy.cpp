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
		std::cout << "打开文件失败" << std::endl;
		return;
	}

	outfile << "<html>" << std::endl;
	outfile << "<body>" << std::endl;
	outfile << "<table border = 1>" << std::endl;
	outfile << "<tr>" << std::endl;
	outfile << "<td>" << "科目" << "</td>" << std::endl;
	outfile << "<td>" << "最高分" << "</td>" << std::endl;
	outfile << "<td>" << "最低分" << "</td>" << std::endl;
	outfile << "<td>" << "平均分" << "</td>" << std::endl;
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
		std::cout << "打开文件失败" << std::endl;
		return;
	}

	std::function<int(Student)> Value;
	if (Subject == "语文") { Value = [](Student a) -> int { return a.GetChinese(); }; }
	else if (Subject == "英语") { Value = [](Student a) -> int { return a.GetEnglish(); }; }
	else if (Subject == "数学") { Value = [](Student a) -> int { return a.GetMath(); }; }
	else if (Subject == "总分") { Value = [](Student a) -> int { return a.GetTotal(); }; }

	outfile << "<html>" << std::endl;
	outfile << "<body>" << std::endl;
	outfile << "<table border = 1>" << std::endl;
	outfile << "<tr>" << std::endl;
	outfile << "<td>" << "姓名" << "</td>" << std::endl;
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
