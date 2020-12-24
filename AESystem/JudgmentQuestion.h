//********************************************************************************************************
//文件名:                                       JudgmentQuestion.h
//版本:                                         1.0
//目的及主要功能:                               判断题类
//创建日期:                                     2020.9.4
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#pragma once
#include "TestQuestion.h"
class JudgmentQuestion :
    public TestQuestion
{
    DECLARE_SERIAL(JudgmentQuestion)
public:
    JudgmentQuestion();
    ~JudgmentQuestion();

    virtual void Serialize(CArchive& ar);//重写的Serialize函数
    virtual int MarkPaper(const CString ans);//判卷函数
};

