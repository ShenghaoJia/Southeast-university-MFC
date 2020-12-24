//********************************************************************************************************
//文件名:                                       ChooseTypeJud.h
//版本:                                         1.0
//目的及主要功能:                               出判断题时对应的对话框
//创建日期:                                     2020.9.5
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#pragma once


// ChooseTypeJud 对话框

class ChooseTypeJud : public CDialogEx
{
	DECLARE_DYNAMIC(ChooseTypeJud)

public:
	ChooseTypeJud(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChooseTypeJud();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGJUD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strJudTopic;//与题目编辑框相关联的变量
	int m_nJudScore;//与分值编辑框相关联的变量
	CString m_strJudAnswer;//储存答案的变量
	
	virtual BOOL OnInitDialog();//初始化对话框的函数
	afx_msg void OnBnClickedOk();//点击确定后的响应函数
	
};
