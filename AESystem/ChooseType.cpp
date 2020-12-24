//********************************************************************************************************
//文件名:                                       ChooseType.cpp
//版本:                                         1.0
//目的及主要功能:                               用于选择试题类型的对话框
//创建日期:                                     2020.9.4
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
// ChooseType.cpp: 实现文件
//

#include "pch.h"
#include "AEsystem.h"
#include "ChooseType.h"
#include "afxdialogex.h"
#include"TestQuestion.h"


// ChooseType 对话框

IMPLEMENT_DYNAMIC(ChooseType, CDialogEx)

ChooseType::ChooseType(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGTYPE, pParent)
{

	m_nType = 0;
}

ChooseType::~ChooseType()
{
}

void ChooseType::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ChooseType, CDialogEx)
	ON_BN_CLICKED(IDOK, &ChooseType::OnBnClickedOk)
END_MESSAGE_MAP()


BOOL ChooseType::OnInitDialog()//对话框的初始化函数
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(BST_CHECKED);//程序启动时默认为单选按钮1选中

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

// ChooseType 消息处理程序

void ChooseType::OnBnClickedOk()//单机确定后的响应函数
{
	// TODO: 在此添加控件通知处理程序代码
	

	if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO1), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"单选"
	{
		m_nType = SINGLE_CHOICE;
	}

	else if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO2), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"多选"
	{
		m_nType = MULTIPLE_CHOICE;
	}

	else if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO3), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"简答"
	{
		m_nType = SHORT_ANSWER;
	}

	else if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO4), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"判断"
	{
		m_nType = JUDGMENT_CHOICE;
	}
	CDialogEx::OnOK();
}