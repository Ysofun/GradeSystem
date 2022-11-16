#include "StudentView.h"
#include "InputStrategyFactory.h"
#include <iostream>
#include "OutputStrategyFactory.h"


/* 数据输入 */
void StudentView::GetDataInput()
{
	std::cout << "请输入文件录入方式：Console/Csv/Json" << std::endl;
	std::cin >> m_InputFileType;
	std::cout << "请输入文件输出方式：Csv/Html" << std::endl;
	std::cin >> m_OutputFileType;
	InputStrategyFactory::GetInstance()->ExecuteStrategy(m_InputFileType);
}

/* 数据输出 */
void StudentView::PrintData(ScoreValue SubjectScore[])
{
	OutputStrategyFactory::GetInstance()->ExecuteStrategy(m_OutputFileType, SubjectScore);
}

void StudentView::PrintData(const std::string& Subject, const std::vector<Student>& Students)
{
	OutputStrategyFactory::GetInstance()->ExecuteStrategy(m_OutputFileType, Subject, Students);
}
