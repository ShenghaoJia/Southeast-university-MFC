//********************************************************************************************************
//文件名:                                       ChooseTypeSAA.h
//版本:                                         1.0
//目的及主要功能:                               简答题答题时的对话框
//创建日期:                                     2020.9.7
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#pragma once


// ChooseTypeSAA 对话框

class ChooseTypeSAA : public CDialogEx
{
	DECLARE_DYNAMIC(ChooseTypeSAA)

public:
	ChooseTypeSAA(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChooseTypeSAA();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGSA_A };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strSaATopic;//和题目编辑框相关联的变量
	CString m_strSaAAnswer;//和答案编辑框相关联的变量

	virtual BOOL OnInitDialog();//初始化对话框
	void TopicAnalyze(const CString topic, int score);//将试卷中的题目放到题目编辑框中
	afx_msg void OnBnClickedPrevious();//点击上一题的响应函数
	afx_msg void OnBnClickedNext();//点击下一题的响应函数
	afx_msg void OnBnClickedFinish();//点击交卷的响应函数
};
