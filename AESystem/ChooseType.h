//********************************************************************************************************
//文件名:                                       ChooseType.h
//版本:                                         1.0
//目的及主要功能:                               用于选择试题类型的对话框
//创建日期:                                     2020.9.4
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#pragma once


// ChooseType 对话框

class ChooseType : public CDialogEx
{
	DECLARE_DYNAMIC(ChooseType)

public:
	ChooseType(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChooseType();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGTYPE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_nType;//根据选择的按钮返回的三个不同题型

	afx_msg void OnBnClickedOk();//点击确定后的响应函数
	virtual BOOL OnInitDialog();//对话框的初始化函数
};
