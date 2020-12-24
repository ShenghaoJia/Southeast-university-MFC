//********************************************************************************************************
//文件名:                                       ChooseTypeMul.cpp
//版本:                                         1.0
//目的及主要功能:                               出多选题时对应的对话框
//创建日期:                                     2020.9.5
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
// ChooseTypeMul.cpp: 实现文件
//

#include "pch.h"
#include "AEsystem.h"
#include "ChooseTypeMul.h"
#include "afxdialogex.h"


// ChooseTypeMul 对话框

IMPLEMENT_DYNAMIC(ChooseTypeMul, CDialogEx)

ChooseTypeMul::ChooseTypeMul(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGMUL, pParent)
	, m_strMulTopic(_T(""))
	, m_nMulScore(0)
	, m_strMulTopicA(_T(""))
	, m_strMulTopicB(_T(""))
	, m_strMulTopicC(_T(""))
	, m_strMulTopicD(_T(""))
{

	m_strMulAnswer = _T("");
	m_strMulTopicTotal = _T("");
}

ChooseTypeMul::~ChooseTypeMul()
{
}

void ChooseTypeMul::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strMulTopic);
	DDX_Text(pDX, IDC_EDIT2, m_nMulScore);
	DDX_Text(pDX, IDC_EDIT3, m_strMulTopicA);
	DDX_Text(pDX, IDC_EDIT4, m_strMulTopicB);
	DDX_Text(pDX, IDC_EDIT5, m_strMulTopicC);
	DDX_Text(pDX, IDC_EDIT6, m_strMulTopicD);
}


BEGIN_MESSAGE_MAP(ChooseTypeMul, CDialogEx)
	ON_BN_CLICKED(IDOK, &ChooseTypeMul::OnBnClickedOk)
END_MESSAGE_MAP()


// ChooseTypeMul 消息处理程序


BOOL ChooseTypeMul::OnInitDialog()//初始化对话框的函数
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//根据上一次的选择初始化按钮
	if(m_strMulAnswer.Find(_T("A"))!=-1)
		((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(BST_CHECKED);//将选项框A设置勾选状态
	if(m_strMulAnswer.Find(_T("B"))!=-1)
		((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(BST_CHECKED);//将选项框B设置勾选状态
	if (m_strMulAnswer.Find(_T("C")) != -1)
		((CButton*)GetDlgItem(IDC_CHECK3))->SetCheck(BST_CHECKED);//将选项框C设置勾选状态
	if (m_strMulAnswer.Find(_T("D")) != -1)
		((CButton*)GetDlgItem(IDC_CHECK4))->SetCheck(BST_CHECKED);//将选项框D设置勾选状态


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ChooseTypeMul::OnBnClickedOk()//点击确定之后的响应函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_strMulAnswer = _T("");
	if (this->m_strMulTopic == _T(""))//题干为空
	{
		MessageBox(_T("题干不能为空"));
	}
	else if (this->m_nMulScore < 1 || this->m_nMulScore>99)//分值超出范围
	{
		MessageBox(_T("分值需要在0-100之间"));
	}
	else if (((CButton*)GetDlgItem(IDC_CHECK1))->GetState() == BST_UNCHECKED &&
		((CButton*)GetDlgItem(IDC_CHECK2))->GetState() == BST_UNCHECKED &&
		((CButton*)GetDlgItem(IDC_CHECK3))->GetState() == BST_UNCHECKED &&
		((CButton*)GetDlgItem(IDC_CHECK4))->GetState() == BST_UNCHECKED)//如果四个复选框都没有被选中
	{
		MessageBox(_T("至少选择一个答案"));
	}
	else if (m_strMulTopicA == _T("") || m_strMulTopicB == _T("") || m_strMulTopicC == _T("") || m_strMulTopicD == _T(""))//有选项描述为空
	{
		MessageBox(_T("选项描述不能为空"));
	}
	else//根据勾选情况编写答案
	{
		if (((CButton*)GetDlgItem(IDC_CHECK1))->GetState() == BST_CHECKED)//如果第一个复选框被选中
			m_strMulAnswer += _T("A;");
		if (((CButton*)GetDlgItem(IDC_CHECK2))->GetState() == BST_CHECKED)//如果第二个复选框被选中
			m_strMulAnswer += _T("B;");
		if (((CButton*)GetDlgItem(IDC_CHECK3))->GetState() == BST_CHECKED)//如果第三个复选框被选中
			m_strMulAnswer += _T("C;");
		if (((CButton*)GetDlgItem(IDC_CHECK4))->GetState() == BST_CHECKED)//如果第四个复选框被选中
			m_strMulAnswer += _T("D;");

		m_strMulTopicTotal = m_strMulTopic + _T(";") + m_strMulTopicA + _T(";") + m_strMulTopicB + _T(";") + m_strMulTopicC + _T(";") + m_strMulTopicD;
		CDialogEx::OnOK();
	}
	
}
