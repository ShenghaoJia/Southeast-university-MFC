#pragma once


// EnterName 对话框

class EnterName : public CDialogEx
{
	DECLARE_DYNAMIC(EnterName)

public:
	EnterName(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~EnterName();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGNAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
