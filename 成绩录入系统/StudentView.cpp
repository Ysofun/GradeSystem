#include "StudentView.h"
#include "InputStrategyFactory.h"
#include <iostream>
#include "OutputStrategyFactory.h"


/* �������� */
void StudentView::GetDataInput()
{
	std::cout << "�������ļ�¼�뷽ʽ��Console/Csv/Json" << std::endl;
	std::cin >> m_InputFileType;
	std::cout << "�������ļ������ʽ��Csv/Html" << std::endl;
	std::cin >> m_OutputFileType;
	InputStrategyFactory::GetInstance()->ExecuteStrategy(m_InputFileType);
}

/* ������� */
void StudentView::PrintData(ScoreValue SubjectScore[])
{
	OutputStrategyFactory::GetInstance()->ExecuteStrategy(m_OutputFileType, SubjectScore);
}

void StudentView::PrintData(const std::string& Subject, const std::vector<Student>& Students)
{
	OutputStrategyFactory::GetInstance()->ExecuteStrategy(m_OutputFileType, Subject, Students);
}
