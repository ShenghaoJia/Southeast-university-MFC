//********************************************************************************************************
//文件名:                                       ChooseTypeSinA.h
//版本:                                         1.0
//目的及主要功能:                               单选题答题时的对话框
//创建日期:                                     2020.9.6
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#pragma once


// ChooseTypeSinA 对话框

class ChooseTypeSinA : public CDialogEx
{
	DECLARE_DYNAMIC(ChooseTypeSinA)

public:
	ChooseTypeSinA(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChooseTypeSinA();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGSIN_A };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();//初始化对话框

	void TopicAnalyze(const CString topic,int score);//将试卷中的题目分解并放到各个选项中
	afx_msg void OnBnClickedButtonPrevious();//点击了上一题的响应函数
	afx_msg void OnBnClickedNext();//点击了下一题的响应函数
	afx_msg void OnBnClickedFinish();//点击了交卷的响应函数

	CString m_strSinATopic;//和题目编辑框相关联的变量
	CString m_strSinATopicA;//和A选项相关联的变量
	CString m_strSinATopicB;//和B选项相关联的变量
	CString m_strSinATopicC;//和C选项相关联的变量
	CString m_strSinATopicD;//和D选项相关联的变量
	CString m_strSinAAnswer;//根据选择生成的答案
	
};
