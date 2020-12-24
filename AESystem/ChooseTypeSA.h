//********************************************************************************************************
//文件名:                                       ChooseTypeSA.h
//版本:                                         1.0
//目的及主要功能:                               出简答题时对应的对话框
//创建日期:                                     2020.9.5
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#pragma once


// ChooseTypeSA 对话框

class ChooseTypeSA : public CDialogEx
{
	DECLARE_DYNAMIC(ChooseTypeSA)

public:
	ChooseTypeSA(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChooseTypeSA();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGSA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();//对话框的初始化函数
	afx_msg void OnBnClickedOk();//点击确定后的响应函数

	CString m_strSaTopic;//和题干编辑框相关联的变量
	CString m_strSaAnswer;//和答案编辑框相关联的对象
	int m_nSaScore;//和分数编辑框相关联的对象
	
};
