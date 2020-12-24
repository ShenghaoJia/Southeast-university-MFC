//********************************************************************************************************
//文件名:                                       TestQuestion.h
//版本:                                         1.0
//目的及主要功能:                               所有试题类的基类
//创建日期:                                     2020.9.4
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#pragma once
#include <afx.h>

enum
{
	SINGLE_CHOICE, MULTIPLE_CHOICE, SHORT_ANSWER,JUDGMENT_CHOICE//单选，多选，简答
};

class TestQuestion : public CObject
{
	DECLARE_SERIAL(TestQuestion)
public:
	TestQuestion();
	virtual ~TestQuestion();

	CString m_strTopic;//题目
	CString m_strAnswer;//答案
	int m_nScore;//本题的分数
	int m_nType;//题目类型

	virtual void Serialize(CArchive& ar);//重载的Serialize函数
	virtual int MarkPaper(const CString ans);//判卷函数
};

