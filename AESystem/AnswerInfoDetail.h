//***************************************************************************
//弃置的类，未使用
//
//
//***************************************************************************
#pragma once


// AnswerInfoDetail 对话框

class AnswerInfoDetail : public CDialogEx
{
	DECLARE_DYNAMIC(AnswerInfoDetail)

public:
	AnswerInfoDetail(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AnswerInfoDetail();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strDetail;
	afx_msg void OnBnClickedPrevious();
	afx_msg void OnBnClickedNext();
	afx_msg void OnBnClickedFinish();
	virtual BOOL OnInitDialog();
	CString m_strName;
};
