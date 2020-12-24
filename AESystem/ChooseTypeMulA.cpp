//********************************************************************************************************
//文件名:                                       ChooseTypeMulA.cpp
//版本:                                         1.0
//目的及主要功能:                               多选题答题时的对话框
//创建日期:                                     2020.9.7
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
// ChooseTypeMulA.cpp: 实现文件
//

#include "pch.h"
#include "AEsystem.h"
#include "ChooseTypeMulA.h"
#include "afxdialogex.h"


// ChooseTypeMulA 对话框

IMPLEMENT_DYNAMIC(ChooseTypeMulA, CDialogEx)

ChooseTypeMulA::ChooseTypeMulA(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGMUL_A, pParent)
	, m_strMulATopic(_T(""))
	, m_strMulATopicA(_T(""))
	, m_strMulATopicB(_T(""))
	, m_strMulATopicC(_T(""))
	, m_strMulATopicD(_T(""))
{

	m_strMulAAnswer = _T("");
}

ChooseTypeMulA::~ChooseTypeMulA()
{
}

void ChooseTypeMulA::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strMulATopic);
	DDX_Text(pDX, IDC_EDIT2, m_strMulATopicA);
	DDX_Text(pDX, IDC_EDIT3, m_strMulATopicB);
	DDX_Text(pDX, IDC_EDIT4, m_strMulATopicC);
	DDX_Text(pDX, IDC_EDIT5, m_strMulATopicD);
}


BEGIN_MESSAGE_MAP(ChooseTypeMulA, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ChooseTypeMulA::OnBnClickedButtonPrevious)
	ON_BN_CLICKED(IDC_BUTTON2, &ChooseTypeMulA::OnBnClickedNext)
	ON_BN_CLICKED(IDC_BUTTON3, &ChooseTypeMulA::OnBnClickedFinish)
END_MESSAGE_MAP()


// ChooseTypeMulA 消息处理程序

BOOL ChooseTypeMulA::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (m_strMulAAnswer.Find(_T("A")) != -1)
		((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(BST_CHECKED);//将选项框A设置勾选状态
	if (m_strMulAAnswer.Find(_T("B")) != -1)
		((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(BST_CHECKED);//将选项框B设置勾选状态
	if (m_strMulAAnswer.Find(_T("C")) != -1)
		((CButton*)GetDlgItem(IDC_CHECK3))->SetCheck(BST_CHECKED);//将选项框C设置勾选状态
	if (m_strMulAAnswer.Find(_T("D")) != -1)
		((CButton*)GetDlgItem(IDC_CHECK4))->SetCheck(BST_CHECKED);//将选项框D设置勾选状态

	UpdateData(false);
	m_strMulAAnswer = _T("");
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void ChooseTypeMulA::TopicAnalyze(const CString topic,int score)
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

	m_strMulATopic = t_strResult[0] + _T(" (") + t_strSrc + _T("分)");
	m_strMulATopicA = t_strResult[1];
	m_strMulATopicB = t_strResult[2];
	m_strMulATopicC = t_strResult[3];
	m_strMulATopicD = t_strResult[4];
}


void ChooseTypeMulA::OnBnClickedButtonPrevious()
{
	// TODO: 在此添加控件通知处理程序代码
	//根据选择情况生成答案
	if (((CButton*)GetDlgItem(IDC_CHECK1))->GetState() == BST_CHECKED)//如果第一个复选框被选中
		m_strMulAAnswer += _T("A;");
	if (((CButton*)GetDlgItem(IDC_CHECK2))->GetState() == BST_CHECKED)//如果第二个复选框被选中
		m_strMulAAnswer += _T("B;");
	if (((CButton*)GetDlgItem(IDC_CHECK3))->GetState() == BST_CHECKED)//如果第三个复选框被选中
		m_strMulAAnswer += _T("C;");
	if (((CButton*)GetDlgItem(IDC_CHECK4))->GetState() == BST_CHECKED)//如果第四个复选框被选中
		m_strMulAAnswer += _T("D;");

	EndDialog(-1);
}




void ChooseTypeMulA::OnBnClickedNext()
{
	// TODO: 在此添加控件通知处理程序代码
	if (((CButton*)GetDlgItem(IDC_CHECK1))->GetState() == BST_CHECKED)//如果第一个复选框被选中
		m_strMulAAnswer += _T("A;");
	if (((CButton*)GetDlgItem(IDC_CHECK2))->GetState() == BST_CHECKED)//如果第二个复选框被选中
		m_strMulAAnswer += _T("B;");
	if (((CButton*)GetDlgItem(IDC_CHECK3))->GetState() == BST_CHECKED)//如果第三个复选框被选中
		m_strMulAAnswer += _T("C;");
	if (((CButton*)GetDlgItem(IDC_CHECK4))->GetState() == BST_CHECKED)//如果第四个复选框被选中
		m_strMulAAnswer += _T("D;");

	EndDialog(1);
}


void ChooseTypeMulA::OnBnClickedFinish()
{
	// TODO: 在此添加控件通知处理程序代码
	if (((CButton*)GetDlgItem(IDC_CHECK1))->GetState() == BST_CHECKED)//如果第一个复选框被选中
		m_strMulAAnswer += _T("A;");
	if (((CButton*)GetDlgItem(IDC_CHECK2))->GetState() == BST_CHECKED)//如果第二个复选框被选中
		m_strMulAAnswer += _T("B;");
	if (((CButton*)GetDlgItem(IDC_CHECK3))->GetState() == BST_CHECKED)//如果第三个复选框被选中
		m_strMulAAnswer += _T("C;");
	if (((CButton*)GetDlgItem(IDC_CHECK4))->GetState() == BST_CHECKED)//如果第四个复选框被选中
		m_strMulAAnswer += _T("D;");

	EndDialog(0);
}
