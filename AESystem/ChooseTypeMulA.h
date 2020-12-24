//********************************************************************************************************
//文件名:                                       ChooseTypeMulA.h
//版本:                                         1.0
//目的及主要功能:                               多选题答题时的对话框
//创建日期:                                     2020.9.7
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#pragma once


// ChooseTypeMulA 对话框

class ChooseTypeMulA : public CDialogEx
{
	DECLARE_DYNAMIC(ChooseTypeMulA)

public:
	ChooseTypeMulA(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChooseTypeMulA();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGMUL_A };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strMulATopic;//和题目编辑框关联的变量
	CString m_strMulATopicA;//和选项A编辑框相关联的变量
	CString m_strMulATopicB;//和选项B编辑框相关联的变量
	CString m_strMulATopicC;//和选项C编辑框相关联的变量
	CString m_strMulATopicD;//和选项D编辑框相关联的变量
	CString m_strMulAAnswer;//储存答案的变量

	virtual BOOL OnInitDialog();//初始化对话框
	afx_msg void OnBnClickedButtonPrevious();//点击上一题后的响应函数
	afx_msg void OnBnClickedNext();//点击下一题后的响应函数
	afx_msg void OnBnClickedFinish();//点击交卷后的响应函数
	void TopicAnalyze(const CString topic,int score);//将试卷中题目分解成题目和选项的函数
};
