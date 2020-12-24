// AnswerInfoDetail.cpp: 实现文件
//

#include "pch.h"
#include "AEsystem.h"
#include "AnswerInfoDetail.h"
#include "afxdialogex.h"


// AnswerInfoDetail 对话框

IMPLEMENT_DYNAMIC(AnswerInfoDetail, CDialogEx)

AnswerInfoDetail::AnswerInfoDetail(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG, pParent)
	, m_strDetail(_T(""))
	, m_strName(_T(""))
{

}

AnswerInfoDetail::~AnswerInfoDetail()
{
}

void AnswerInfoDetail::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strDetail);
	DDX_Text(pDX, IDC_EDIT2, m_strName);
}


BEGIN_MESSAGE_MAP(AnswerInfoDetail, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &AnswerInfoDetail::OnBnClickedPrevious)
	ON_BN_CLICKED(IDC_BUTTON2, &AnswerInfoDetail::OnBnClickedNext)
	ON_BN_CLICKED(IDC_BUTTON3, &AnswerInfoDetail::OnBnClickedFinish)
END_MESSAGE_MAP()


// AnswerInfoDetail 消息处理程序


void AnswerInfoDetail::OnBnClickedPrevious()
{
	EndDialog(-1);
	// TODO: 在此添加控件通知处理程序代码
}


void AnswerInfoDetail::OnBnClickedNext()
{
	EndDialog(1);
	// TODO: 在此添加控件通知处理程序代码
}


void AnswerInfoDetail::OnBnClickedFinish()
{
	EndDialog(0);
	// TODO: 在此添加控件通知处理程序代码
}


BOOL AnswerInfoDetail::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
