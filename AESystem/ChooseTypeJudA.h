//********************************************************************************************************
//文件名:                                       ChooseTypeJudA.h
//版本:                                         1.0
//目的及主要功能:                               判断题答题时的对话框
//创建日期:                                     2020.9.7
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#pragma once


// ChooseTypeJudA 对话框

class ChooseTypeJudA : public CDialogEx
{
	DECLARE_DYNAMIC(ChooseTypeJudA)

public:
	ChooseTypeJudA(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChooseTypeJudA();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGJUD_A };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strJudATopic;//和题目编辑框关联的变量
	CString m_strJudAAnswer;//储存答案的变量

	virtual BOOL OnInitDialog();//初始化对话框
	void TopicAnalyze(const CString topic, int score);//将试卷中的题目放入编辑框中
	afx_msg void OnBnClickedPrevious();//点击上一题的响应函数
	afx_msg void OnBnClickedNext();//点击下一题的响应函数
	afx_msg void OnBnClickedFinish();//点击交卷的响应函数
};
