//********************************************************************************************************
//文件名:                                       AnswerInfo.h
//版本:                                         1.0
//目的及主要功能:                               对话框类，用来浏览所有答题学生的信息
//创建日期:                                     2020.9.13
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#pragma once
#include"Student.h"
#include<vector>
using namespace std;

// AnswerInfo 对话框

class AnswerInfo : public CDialogEx
{
	DECLARE_DYNAMIC(AnswerInfo)

public:
	AnswerInfo(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AnswerInfo();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();//初始化对话框的函数
	CListCtrl m_list;//列表控件关联的变脸
	vector<Student> m_stuInfo;//储存的学生信息
//	afx_msg void OnNMDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
};
