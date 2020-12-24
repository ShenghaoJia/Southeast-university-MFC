//********************************************************************************************************
//文件名:                                       ChooseTypeSAA.cpp
//版本:                                         1.0
//目的及主要功能:                               简答题答题时的对话框
//创建日期:                                     2020.9.7
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
// ChooseTypeSAA.cpp: 实现文件
//

#include "pch.h"
#include "AEsystem.h"
#include "ChooseTypeSAA.h"
#include "afxdialogex.h"


// ChooseTypeSAA 对话框

IMPLEMENT_DYNAMIC(ChooseTypeSAA, CDialogEx)

ChooseTypeSAA::ChooseTypeSAA(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGSA_A, pParent)
	, m_strSaATopic(_T(""))
	, m_strSaAAnswer(_T(""))
{


}

ChooseTypeSAA::~ChooseTypeSAA()
{
}

void ChooseTypeSAA::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strSaATopic);
	DDX_Text(pDX, IDC_EDIT2, m_strSaAAnswer);
}


BEGIN_MESSAGE_MAP(ChooseTypeSAA, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ChooseTypeSAA::OnBnClickedPrevious)
	ON_BN_CLICKED(IDC_BUTTON2, &ChooseTypeSAA::OnBnClickedNext)
	ON_BN_CLICKED(IDC_BUTTON3, &ChooseTypeSAA::OnBnClickedFinish)
END_MESSAGE_MAP()


// ChooseTypeSAA 消息处理程序

BOOL ChooseTypeSAA::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void ChooseTypeSAA::TopicAnalyze(const CString topic, int score)
{
	// TODO: 在此处添加实现代码
	CString t_strSrc;
	t_strSrc.Format(_T("%d"), score);

	m_strSaATopic = topic + _T(" (") + t_strSrc + _T("分)");

}

void ChooseTypeSAA::OnBnClickedPrevious()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);

	EndDialog(-1);
}


void ChooseTypeSAA::OnBnClickedNext()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);

	EndDialog(1);
}


void ChooseTypeSAA::OnBnClickedFinish()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);

	EndDialog(0);
}
