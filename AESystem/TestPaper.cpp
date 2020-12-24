//********************************************************************************************************
//文件名:                                       TestPaper.cpp
//版本:                                         1.0
//目的及主要功能:                               试卷类，用于将多个试题整合起来
//创建日期:                                     2020.9.4
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#include "pch.h"
#include "TestPaper.h"

IMPLEMENT_SERIAL(TestPaper,CObject,1)

TestPaper::TestPaper()
	:m_nPaperNum(0),
	m_nTotalScore(0)
{

}

TestPaper::~TestPaper()
{

}

void TestPaper::Serialize(CArchive& ar)//重写的Serialize函数
{
	if (ar.IsStoring())
	{	// storing code
		
		ar << m_nPaperNum;//将试题数量存入
		ar << m_nTotalScore;//将总分存入

		for (int i = 0; i < this->m_vnPaperType.size(); i++)//将类型容器存入
		{
			ar << this->m_vnPaperType[i];
		}
	
		for (int i = 0; i < this->m_vpTqExamPaper.size(); i++)//将试题容器存入
		{
			this->m_vpTqExamPaper[i]->Serialize(ar);
		}
	}
	else
	{	// loading code
		ar >> m_nPaperNum;//将试题数量拿出
		ar >> m_nTotalScore;//将总分拿出

		for (int i = 0; i < m_nPaperNum; i++)//根据试题数量将试卷类型容器拿出
		{
			m_vnPaperType.push_back(0);
			ar >> this->m_vnPaperType[i];
		}
		for (int i = 0; i < m_nPaperNum; i++)//根据试题数量和试题类型将试题拿出
		{
			if (m_vnPaperType[i] == SINGLE_CHOICE)
				m_vpTqExamPaper.push_back(new SingleChoiceQuestion());
			if (m_vnPaperType[i] == MULTIPLE_CHOICE)
				m_vpTqExamPaper.push_back(new MultipleChoiceQuestion());
			if (m_vnPaperType[i] == SHORT_ANSWER)
				m_vpTqExamPaper.push_back(new ShortAnswerQuestion());
			if (m_vnPaperType[i] == JUDGMENT_CHOICE)
				m_vpTqExamPaper.push_back(new JudgmentQuestion());
			//m_vpTqExamPaper.push_back(new TestQuestion());
			this->m_vpTqExamPaper[i]->Serialize(ar);
		}
	}
}


bool TestPaper::AddQuestion(const CString topic, const CString answer, int score, int type)//增加试题函数
{
	// TODO: 在此处添加实现代码.
	if (m_nTotalScore + score > 100)
		return false;
	else
	{
		m_vnPaperType.push_back(type);

		if (type == SINGLE_CHOICE)
			m_vpTqExamPaper.push_back(new SingleChoiceQuestion());
		if (type == MULTIPLE_CHOICE)
			m_vpTqExamPaper.push_back(new MultipleChoiceQuestion());
		if (type == SHORT_ANSWER)
			m_vpTqExamPaper.push_back(new ShortAnswerQuestion());
		if (type == JUDGMENT_CHOICE)
			m_vpTqExamPaper.push_back(new JudgmentQuestion());

		m_vpTqExamPaper.back()->m_strTopic = topic;
		m_vpTqExamPaper.back()->m_strAnswer = answer;
		m_vpTqExamPaper.back()->m_nScore = score;
		m_vpTqExamPaper.back()->m_nType = type;

		m_nPaperNum++;
		m_nTotalScore += score;
		return true;
	}


	
}
