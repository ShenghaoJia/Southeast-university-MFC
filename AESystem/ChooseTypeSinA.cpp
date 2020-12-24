//********************************************************************************************************
//文件名:                                       ChooseTypeSinA.cpp
//版本:                                         1.0
//目的及主要功能:                               单选题答题时的对话框
//创建日期:                                     2020.9.6
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
// ChooseTypeSinA.cpp: 实现文件
//

#include "pch.h"
#include "AEsystem.h"
#include "ChooseTypeSinA.h"
#include "afxdialogex.h"


// ChooseTypeSinA 对话框

IMPLEMENT_DYNAMIC(ChooseTypeSinA, CDialogEx)

ChooseTypeSinA::ChooseTypeSinA(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGSIN_A, pParent)
	, m_strSinATopic(_T(""))
	, m_strSinATopicA(_T(""))
	, m_strSinATopicB(_T(""))
	, m_strSinATopicC(_T(""))
	, m_strSinATopicD(_T(""))
{

	m_strSinAAnswer = _T("");

}

ChooseTypeSinA::~ChooseTypeSinA()
{
}

void ChooseTypeSinA::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strSinATopic);
	DDX_Text(pDX, IDC_EDIT2, m_strSinATopicA);
	DDX_Text(pDX, IDC_EDIT3, m_strSinATopicB);
	DDX_Text(pDX, IDC_EDIT4, m_strSinATopicC);
	DDX_Text(pDX, IDC_EDIT5, m_strSinATopicD);
}


BEGIN_MESSAGE_MAP(ChooseTypeSinA, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ChooseTypeSinA::OnBnClickedButtonPrevious)
	ON_BN_CLICKED(IDC_BUTTON2, &ChooseTypeSinA::OnBnClickedNext)
	ON_BN_CLICKED(IDC_BUTTON3, &ChooseTypeSinA::OnBnClickedFinish)
END_MESSAGE_MAP()


// ChooseTypeSinA 消息处理程序



BOOL ChooseTypeSinA::OnInitDialog()//初始化对话框
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (m_strSinAAnswer == _T("B"))
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(BST_CHECKED);
	else if (m_strSinAAnswer == _T("C"))
		((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(BST_CHECKED);
	else if (m_strSinAAnswer == _T("D"))
		((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(BST_CHECKED);
	else
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(BST_CHECKED);

	UpdateData(false);//将数据同步到编辑框中
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ChooseTypeSinA::TopicAnalyze(const CString topic,int score)//将试卷中的题目分解后放到题目和选项中
{
	// TODO: 在此处添加实现代码.
	CString t_strSrc = topic;//将ans复制一份出来
	CStringArray t_strResult;//一个CString型的数组，用来取出不同的答案

	CString strGap = _T(";");//定义分号为分隔符
	int t_nPos = t_strSrc.Find(strGap);//分隔符的数量

	CString strLeft = _T("");//分隔符左面的字符串
	while (0 <= t_nPos)//不断循环，取出左面的字符串并放入数组中
	{
		strLeft = t_strSrc.Left(t_nPos);
		if (!strLeft.IsEmpty())
			t_strResult.Add(strLeft);

		t_strSrc = t_strSrc.Right(t_strSrc.GetLength() - t_nPos - 1);
		t_nPos = t_strSrc.Find(strGap);
	}

	if (!t_strSrc.IsEmpty()) {//如果没有取完，把最后一部分加到数组中
		t_strResult.Add(t_strSrc);
	}
	t_strSrc.Format(_T("%d"), score);

	m_strSinATopic = t_strResult[0] + _T(" (") + t_strSrc + _T("分)");
	m_strSinATopicA = t_strResult[1];
	m_strSinATopicB = t_strResult[2];
	m_strSinATopicC = t_strResult[3];
	m_strSinATopicD = t_strResult[4];
}


void ChooseTypeSinA::OnBnClickedButtonPrevious()//点击上一题的响应函数
{
	// TODO: 在此添加控件通知处理程序代码
	//根据选择来生成答案
	if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO1), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"A"
	{
		this->m_strSinAAnswer = _T("A");
	}
	else if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO2), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"B"
	{
		this->m_strSinAAnswer = _T("B");
	}
	else if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO3), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"C"
	{
		this->m_strSinAAnswer = _T("C");
	}
	else if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO4), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"D"
	{
		this->m_strSinAAnswer = _T("D");
	}
	EndDialog(-1);//返回-1

}


void ChooseTypeSinA::OnBnClickedNext()//点击下一题的响应函数
{
	// TODO: 在此添加控件通知处理程序代码
	if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO1), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"A"
	{
		this->m_strSinAAnswer = _T("A");
	}
	else if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO2), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"B"
	{
		this->m_strSinAAnswer = _T("B");
	}
	else if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO3), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"C"
	{
		this->m_strSinAAnswer = _T("C");
	}
	else if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO4), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"D"
	{
		this->m_strSinAAnswer = _T("D");
	}

	EndDialog(1);
}


void ChooseTypeSinA::OnBnClickedFinish()//点击交卷的响应函数
{
	// TODO: 在此添加控件通知处理程序代码
	if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO1), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"A"
	{
		this->m_strSinAAnswer = _T("A");
	}
	else if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO2), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"B"
	{
		this->m_strSinAAnswer = _T("B");
	}
	else if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO3), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"C"
	{
		this->m_strSinAAnswer = _T("C");
	}
	else if (::SendMessage(::GetDlgItem(m_hWnd, IDC_RADIO4), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮"D"
	{
		this->m_strSinAAnswer = _T("D");
	}

	EndDialog(0);
}
