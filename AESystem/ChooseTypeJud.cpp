//********************************************************************************************************
//文件名:                                       ChooseTypeJud.cpp
//版本:                                         1.0
//目的及主要功能:                               出判断题时对应的对话框
//创建日期:                                     2020.9.5
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
// ChooseTypeJud.cpp: 实现文件
//

#include "pch.h"
#include "AEsystem.h"
#include "ChooseTypeJud.h"
#include "afxdialogex.h"


// ChooseTypeJud 对话框

IMPLEMENT_DYNAMIC(ChooseTypeJud, CDialogEx)

ChooseTypeJud::ChooseTypeJud(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGJUD, pParent)
	, m_strJudTopic(_T(""))
	, m_nJudScore(0)
{

	m_strJudAnswer = _T("");
}

ChooseTypeJud::~ChooseTypeJud()
{
}

void ChooseTypeJud::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strJudTopic);
	DDX_Text(pDX, IDC_EDIT2, m_nJudScore);
}


BEGIN_MESSAGE_MAP(ChooseTypeJud, CDialogEx)
	ON_BN_CLICKED(IDOK, &ChooseTypeJud::OnBnClickedOk)
END_MESSAGE_MAP()


// ChooseTypeJud 消息处理程序


BOOL ChooseTypeJud::OnInitDialog()//初始化对话框的函数
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//根据上次的选择初始化对话框
	if(m_strJudAnswer==_T("FALSE"))
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(BST_CHECKED);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ChooseTypeJud::OnBnClickedOk()//点击确定后的响应函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);

	if (m_strJudTopic == _T(""))//题干为空
	{
		MessageBox(_T("题干不能为空"));
	}
	else if (m_nJudScore < 1 || m_nJudScore>99)//分值超出范围
	{
		MessageBox(_T("分值需要在0-100之间"));
	}
	else//根据按钮的选择情况存储答案
	{
		if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO1), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"正确"
		{
			this->m_strJudAnswer = _T("TRUE");
		}
		else
		{
			this->m_strJudAnswer = _T("FALSE");
		}
		CDialogEx::OnOK();
	}
	
}
