//********************************************************************************************************
//文件名:                                       ChooseTypeSin.h
//版本:                                         1.0
//目的及主要功能:                               出单选题时对应的对话框
//创建日期:                                     2020.9.5
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#pragma once


// ChooseTypeSin 对话框

class ChooseTypeSin : public CDialogEx
{
	DECLARE_DYNAMIC(ChooseTypeSin)

public:
	ChooseTypeSin(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChooseTypeSin();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGSIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();//对话框的初始化函数
	afx_msg void OnBnClickedOk();//点击确定的响应函数

	CString m_strSinTopic;// 和题目的文本框关联的变量
	CString m_strSinAnswer;//表示答案的变量
	int m_nSinScore;// 和分值编辑框关联的变量

	CString m_strSinTopicA;
	CString m_strSinTopicB;
	CString m_strSinTopicC;
	CString m_strSinTopicD;
	
	CString m_strSinTopicTotal;
};
