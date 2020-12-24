// EnterName.cpp: 实现文件
//

#include "pch.h"
#include "AEsystem.h"
#include "EnterName.h"
#include "afxdialogex.h"


// EnterName 对话框

IMPLEMENT_DYNAMIC(EnterName, CDialogEx)

EnterName::EnterName(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGNAME, pParent)
	, m_strName(_T(""))
{

}

EnterName::~EnterName()
{
}

void EnterName::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strName);
}


BEGIN_MESSAGE_MAP(EnterName, CDialogEx)
	ON_BN_CLICKED(IDOK, &EnterName::OnBnClickedOk)
END_MESSAGE_MAP()


// EnterName 消息处理程序


BOOL EnterName::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void EnterName::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if (m_strName == _T(""))
	{
		MessageBox(_T("请填入您的姓名"));
	}
	else
	{
		MessageBox(_T("信息录入成功，请开始答题"));
		CDialogEx::OnOK();
	}
	
}
