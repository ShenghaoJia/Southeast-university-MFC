//********************************************************************************************************
//文件名:                                       ChooseTypeJudA.cpp
//版本:                                         1.0
//目的及主要功能:                               判断题答题时的对话框
//创建日期:                                     2020.9.7
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
// ChooseTypeJudA.cpp: 实现文件
//

#include "pch.h"
#include "AEsystem.h"
#include "ChooseTypeJudA.h"
#include "afxdialogex.h"


// ChooseTypeJudA 对话框

IMPLEMENT_DYNAMIC(ChooseTypeJudA, CDialogEx)

ChooseTypeJudA::ChooseTypeJudA(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGJUD_A, pParent)
	, m_strJudATopic(_T(""))
{

	m_strJudAAnswer = _T("");
}

ChooseTypeJudA::~ChooseTypeJudA()
{
}

void ChooseTypeJudA::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strJudATopic);
}


BEGIN_MESSAGE_MAP(ChooseTypeJudA, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ChooseTypeJudA::OnBnClickedPrevious)
	ON_BN_CLICKED(IDC_BUTTON2, &ChooseTypeJudA::OnBnClickedNext)
	ON_BN_CLICKED(IDC_BUTTON3, &ChooseTypeJudA::OnBnClickedFinish)
END_MESSAGE_MAP()


// ChooseTypeJudA 消息处理程序


BOOL ChooseTypeJudA::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (m_strJudAAnswer == _T("FALSE"))
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(BST_CHECKED);
	
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ChooseTypeJudA::TopicAnalyze(const CString topic, int score)
{
	// TODO: 在此处添加实现代码.
	CString t_strSrc;
	t_strSrc.Format(_T("%d"), score);

	m_strJudATopic = topic + _T(" (") + t_strSrc + _T("分)");

}


void ChooseTypeJudA::OnBnClickedPrevious()
{
	// TODO: 在此添加控件通知处理程序代码
	if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO1), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"正确"
	{
		this->m_strJudAAnswer = _T("TRUE");
	}
	else
	{
		this->m_strJudAAnswer = _T("FALSE");
	}

	EndDialog(-1);
}


void ChooseTypeJudA::OnBnClickedNext()
{
	// TODO: 在此添加控件通知处理程序代码
	if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO1), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"正确"
	{
		this->m_strJudAAnswer = _T("TRUE");
	}
	else
	{
		this->m_strJudAAnswer = _T("FALSE");
	}

	EndDialog(1);
}


void ChooseTypeJudA::OnBnClickedFinish()
{
	// TODO: 在此添加控件通知处理程序代码
	if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO1), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"正确"
	{
		this->m_strJudAAnswer = _T("TRUE");
	}
	else
	{
		this->m_strJudAAnswer = _T("FALSE");
	}

	EndDialog(0);
}
