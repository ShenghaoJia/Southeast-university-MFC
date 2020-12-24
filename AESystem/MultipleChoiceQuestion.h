//********************************************************************************************************
//文件名:                                       MultipleChoiceQuestion.h
//版本:                                         1.0
//目的及主要功能:                               多选题类
//创建日期:                                     2020.9.4
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#pragma once
#include "TestQuestion.h"
class MultipleChoiceQuestion :
    public TestQuestion
{
    DECLARE_SERIAL(MultipleChoiceQuestion)
public:
    MultipleChoiceQuestion();
    virtual ~MultipleChoiceQuestion();

    virtual void Serialize(CArchive& ar);//重写的Serialize函数
    virtual int MarkPaper(const CString ans);//判卷函数
};

