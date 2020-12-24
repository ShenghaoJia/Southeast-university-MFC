//********************************************************************************************************
//文件名:                                       TestPaper.h
//版本:                                         1.0
//目的及主要功能:                               试卷类，用于将多个试题整合起来
//创建日期:                                     2020.9.4
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#pragma once
#include <afx.h>
#include<vector>
using namespace std;

//#include"TestQuestion.h"
#include"SingleChoiceQuestion.h"
#include"MultipleChoiceQuestion.h"
#include"ShortAnswerQuestion.h"
#include"JudgmentQuestion.h"
class TestPaper :
    public CObject
{
    DECLARE_SERIAL(TestPaper)
public:
    TestPaper();
    ~TestPaper();

    virtual void Serialize(CArchive& ar);//重写的Serialize函数
    bool AddQuestion(const CString topic, const CString answer, int score, int type);//添加试题

    vector<TestQuestion*> m_vpTqExamPaper;//试卷题目
    vector<int> m_vnPaperType;//试卷题目的类型
    int m_nPaperNum;//试题的数量
    int m_nTotalScore;//试卷的总分
    
};

