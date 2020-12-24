//********************************************************************************************************
//文件名:                                       ExistingQuestion.cpp
//版本:                                         1.0
//目的及主要功能:                               出题结束后浏览题目的对话框
//创建日期:                                     2020.9.7
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
// ExistingQuestion.cpp: 实现文件
//

#include "pch.h"
#include "AEsystem.h"
#include "ExistingQuestion.h"
#include "afxdialogex.h"


// ExistingQuestion 对话框

IMPLEMENT_DYNAMIC(ExistingQuestion, CDialogEx)

ExistingQuestion::ExistingQuestion(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGCHECK, pParent)
	, m_strEqTopic(_T(""))
	, m_strEqAnswer(_T(""))
{

}

ExistingQuestion::~ExistingQuestion()
{
}

void ExistingQuestion::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strEqTopic);
	DDX_Text(pDX, IDC_EDIT2, m_strEqAnswer);
}


BEGIN_MESSAGE_MAP(ExistingQuestion, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ExistingQuestion::OnBnClickedPrevious)
	ON_BN_CLICKED(IDC_BUTTON2, &ExistingQuestion::OnBnClickedNext)
	ON_BN_CLICKED(IDC_BUTTON3, &ExistingQuestion::OnBnClickedFinish)
END_MESSAGE_MAP()


// ExistingQuestion 消息处理程序


BOOL ExistingQuestion::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ExistingQuestion::OnBnClickedPrevious()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(-1);
}


void ExistingQuestion::OnBnClickedNext()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(1);
}


void ExistingQuestion::OnBnClickedFinish()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}
