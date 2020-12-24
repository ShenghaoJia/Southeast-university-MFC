//********************************************************************************************************
//文件名:                                       ChooseTypeSin.cpp
//版本:                                         1.0
//目的及主要功能:                               出单选题时对应的对话框
//创建日期:                                     2020.9.5
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
// ChooseTypeSin.cpp: 实现文件
//

#include "pch.h"
#include "AEsystem.h"
#include "ChooseTypeSin.h"
#include "afxdialogex.h"


// ChooseTypeSin 对话框

IMPLEMENT_DYNAMIC(ChooseTypeSin, CDialogEx)

ChooseTypeSin::ChooseTypeSin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGSIN, pParent)
	, m_strSinTopic(_T(""))
	, m_nSinScore(0)
	, m_strSinTopicA(_T(""))
	, m_strSinTopicB(_T(""))
	, m_strSinTopicC(_T(""))
	, m_strSinTopicD(_T(""))
{

	m_strSinAnswer = _T("");
	m_strSinTopicTotal = _T("");
}

ChooseTypeSin::~ChooseTypeSin()
{
}

void ChooseTypeSin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strSinTopic);
	DDX_Text(pDX, IDC_EDIT2, m_nSinScore);
	DDX_Text(pDX, IDC_EDIT3, m_strSinTopicA);
	DDX_Text(pDX, IDC_EDIT4, m_strSinTopicB);
	DDX_Text(pDX, IDC_EDIT5, m_strSinTopicC);
	DDX_Text(pDX, IDC_EDIT6, m_strSinTopicD);
}


BEGIN_MESSAGE_MAP(ChooseTypeSin, CDialogEx)
	ON_BN_CLICKED(IDOK, &ChooseTypeSin::OnBnClickedOk)
END_MESSAGE_MAP()


// ChooseTypeSin 消息处理程序


BOOL ChooseTypeSin::OnInitDialog()//初始化对话框的函数
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//根据上次的选择初始化选择按钮
	if(m_strSinAnswer==_T("B"))
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(BST_CHECKED);
	else if (m_strSinAnswer == _T("C"))
		((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(BST_CHECKED);
	else if (m_strSinAnswer == _T("D"))
		((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(BST_CHECKED);
	//((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(BST_CHECKED);//程序启动时默认为单选按钮1选中

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ChooseTypeSin::OnBnClickedOk()//点击确定后的响应函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);

	if (m_strSinTopic == _T(""))//题干为空
	{
		MessageBox(_T("题干不能为空"));
	}
	else if (m_nSinScore < 1 || m_nSinScore>99)//分值超出范围
	{
		MessageBox(_T("分值需要在0-100之间"));
	}
	else if (m_strSinTopicA == _T("") || m_strSinTopicB == _T("") || m_strSinTopicC == _T("") || m_strSinTopicD == _T(""))//缺少选项描述
	{
		MessageBox(_T("选项描述不能为空"));
	}
	else//根据勾选情况生成答案
	{
		if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO1), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"A"
		{
			this->m_strSinAnswer = _T("A");
		}
		else if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO2), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"B"
		{
			this->m_strSinAnswer = _T("B");
		}
		else if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO3), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"C"
		{
			this->m_strSinAnswer = _T("C");
		}
		else if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO4), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"D"
		{
			this->m_strSinAnswer = _T("D");
		}
		//MessageBox(_T("出题成功！"));
		m_strSinTopicTotal = m_strSinTopic + _T(";") + m_strSinTopicA + _T(";") + m_strSinTopicB + _T(";") + m_strSinTopicC + _T(";") + m_strSinTopicD;
		CDialogEx::OnOK();
	}
	
}
