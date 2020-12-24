//********************************************************************************************************
//文件名:                                       TestQuestion.cpp
//版本:                                         1.0
//目的及主要功能:                               所有试题类的基类
//创建日期:                                     2020.9.4
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#include "pch.h"
#include "TestQuestion.h"

IMPLEMENT_SERIAL(TestQuestion,CObject,1)

TestQuestion::TestQuestion()
	:m_strTopic(_T("")),
	m_strAnswer(_T("")),
	m_nScore(0),
	m_nType(0)
{

}

TestQuestion::~TestQuestion()
{

}

void TestQuestion::Serialize(CArchive& ar)
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


int TestQuestion::MarkPaper(const CString ans)
{
	// TODO: 在此处添加实现代码.

	return 0;
}
