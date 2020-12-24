//********************************************************************************************************
//文件名:                                       ChooseTypeSA.cpp
//版本:                                         1.0
//目的及主要功能:                               出简答题时对应的对话框
//创建日期:                                     2020.9.5
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
// ChooseTypeSA.cpp: 实现文件
//

#include "pch.h"
#include "AEsystem.h"
#include "ChooseTypeSA.h"
#include "afxdialogex.h"


// ChooseTypeSA 对话框

IMPLEMENT_DYNAMIC(ChooseTypeSA, CDialogEx)

ChooseTypeSA::ChooseTypeSA(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGSA, pParent)
	, m_strSaTopic(_T(""))
	, m_strSaAnswer(_T(""))
	, m_nSaScore(0)
{

}

ChooseTypeSA::~ChooseTypeSA()
{
}

void ChooseTypeSA::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strSaTopic);
	DDX_Text(pDX, IDC_EDIT2, m_strSaAnswer);
	DDX_Text(pDX, IDC_EDIT3, m_nSaScore);
}


BEGIN_MESSAGE_MAP(ChooseTypeSA, CDialogEx)
	ON_BN_CLICKED(IDOK, &ChooseTypeSA::OnBnClickedOk)
END_MESSAGE_MAP()


// ChooseTypeSA 消息处理程序


BOOL ChooseTypeSA::OnInitDialog()//对话框的初始化函数
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ChooseTypeSA::OnBnClickedOk()//点击确定后的响应函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);

	if (m_strSaTopic == _T(""))//题干为空
	{
		MessageBox(_T("题干不能为空"));
	}
	else if (m_strSaAnswer == _T(""))//答案为空
	{
		MessageBox(_T("答案不能为空"));
	}
	else if (m_nSaScore < 1 || m_nSaScore>99)//分值超出范围
	{
		MessageBox(_T("分值需要在0-100之间"));
	}
	else
	{
		CDialogEx::OnOK();
	}
	
}
