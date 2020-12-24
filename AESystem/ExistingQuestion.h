//********************************************************************************************************
//文件名:                                       ExistingQuestion.h
//版本:                                         1.0
//目的及主要功能:                               出题结束后浏览题目的对话框
//创建日期:                                     2020.9.7
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#pragma once


// ExistingQuestion 对话框

class ExistingQuestion : public CDialogEx
{
	DECLARE_DYNAMIC(ExistingQuestion)

public:
	ExistingQuestion(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ExistingQuestion();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGCHECK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString m_strEqTopic;
	CString m_strEqAnswer;
	afx_msg void OnBnClickedPrevious();
	afx_msg void OnBnClickedNext();
	afx_msg void OnBnClickedFinish();
};
