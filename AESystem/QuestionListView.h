//********************************************************************************************************
//文件名:                                       QuestionListView.h
//版本:                                         1.0
//目的及主要功能:                               新建的视图类，出题时用来显示题目列表
//创建日期:                                     2020.9.6
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#pragma once
#include<afxcview.h>
class QuestionListView :
    public CListView
{
public:
    QuestionListView();
    ~QuestionListView();


    virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
    bool m_bIsFirst;//是否为第一次打开
    int m_nQuestionSize;//当前试卷题目的数量
    DECLARE_MESSAGE_MAP()
    afx_msg void OnNMDblclk(NMHDR* pNMHDR, LRESULT* pResult);//双击了表格
};

