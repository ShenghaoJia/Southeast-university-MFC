//********************************************************************************************************
//文件名:                                       ChooseTypeMul.h
//版本:                                         1.0
//目的及主要功能:                               出多选题时对应的对话框
//创建日期:                                     2020.9.5
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#pragma once


// ChooseTypeMul 对话框

class ChooseTypeMul : public CDialogEx
{
	DECLARE_DYNAMIC(ChooseTypeMul)

public:
	ChooseTypeMul(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChooseTypeMul();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGMUL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();//初始化对话框的函数
	afx_msg void OnBnClickedOk();//点击确定后的响应函数

	CString m_strMulTopic;// 和题干相关联的变量
	int m_nMulScore;// 和分值编辑框关联的变量
	CString m_strMulAnswer;//答案的字符串
	CString m_strMulTopicA;//与选项A编辑框关联的字符串
	CString m_strMulTopicB;//与选项B编辑框关联的字符串
	CString m_strMulTopicC;//与选项C编辑框关联的字符串
	CString m_strMulTopicD;//与选项D编辑框关联的字符串
	CString m_strMulTopicTotal;//整个题目的命题（题干+选项）
};
