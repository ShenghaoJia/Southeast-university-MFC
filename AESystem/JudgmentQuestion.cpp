//********************************************************************************************************
//文件名:                                       JudgmentQuestion.cpp
//版本:                                         1.0
//目的及主要功能:                               判断题类
//创建日期:                                     2020.9.4
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#include "pch.h"
#include "JudgmentQuestion.h"

IMPLEMENT_SERIAL(JudgmentQuestion,CObject,1)

JudgmentQuestion::JudgmentQuestion()
{

}

JudgmentQuestion::~JudgmentQuestion()
{

}

void JudgmentQuestion::Serialize(CArchive& ar)//重写的Serialize函数
{
	if (ar.IsStoring())
	{	// storing code
		ar << m_strTopic << m_strAnswer << m_nScore << m_nType;
	}
	else
	{	// loading code
		ar >> m_strTopic >> m_strAnswer >> m_nScore >> m_nType;
	}
}


int JudgmentQuestion::MarkPaper(const CString ans)//判卷函数
{
	// TODO: 在此处添加实现代码.
	if (ans == this->m_strAnswer)
		return this->m_nScore;
	else
		return 0;
}
