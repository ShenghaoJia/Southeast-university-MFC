//********************************************************************************************************
//文件名:                                       SingleChoiceQuestion.cpp
//版本:                                         1.0
//目的及主要功能:                               单选题类
//创建日期:                                     2020.9.4
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#include "pch.h"
#include "SingleChoiceQuestion.h"

IMPLEMENT_SERIAL(SingleChoiceQuestion,CObject,1)

SingleChoiceQuestion::SingleChoiceQuestion()
{

}

SingleChoiceQuestion::~SingleChoiceQuestion()
{

}

void SingleChoiceQuestion::Serialize(CArchive& ar)//重写的Serialize函数
{
	if (ar.IsStoring())
	{	// storing code
		ar << m_strTopic << m_strAnswer << m_nScore << m_nType;;
	}
	else
	{	// loading code
		ar >> m_strTopic >> m_strAnswer >> m_nScore >> m_nType;
	}
}

int SingleChoiceQuestion::MarkPaper(const CString ans)
{
	//单选只有一个答案，故只要答案和标准答案相同即可得满分
	if (ans == this->m_strAnswer)
		return this->m_nScore;
	else
		return 0;
}
