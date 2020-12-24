//********************************************************************************************************
//文件名:                                       SingleChoiceQuestion.h
//版本:                                         1.0
//目的及主要功能:                               单选题类
//创建日期:                                     2020.9.4
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#pragma once
#include "TestQuestion.h"
class SingleChoiceQuestion :public TestQuestion
{
	DECLARE_SERIAL(SingleChoiceQuestion)
public:
	SingleChoiceQuestion();
	virtual ~SingleChoiceQuestion();

	virtual void Serialize(CArchive& ar);//重写的Serialize函数
	virtual int MarkPaper(const CString ans);//判卷函数
};

