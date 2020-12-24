//********************************************************************************************************
//文件名:                                       AnswerInfo.cpp
//版本:                                         1.0
//目的及主要功能:                               对话框类，用来浏览所有答题学生的信息
//创建日期:                                     2020.9.13
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
// AnswerInfo.cpp: 实现文件
//

#include "pch.h"
#include "AEsystem.h"
#include "AnswerInfo.h"
#include "afxdialogex.h"
#include"AnswerInfoDetail.h"


// AnswerInfo 对话框

IMPLEMENT_DYNAMIC(AnswerInfo, CDialogEx)

AnswerInfo::AnswerInfo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

AnswerInfo::~AnswerInfo()
{
}

void AnswerInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(AnswerInfo, CDialogEx)
	//ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &AnswerInfo::OnNMDblclkList)
END_MESSAGE_MAP()


// AnswerInfo 消息处理程序


BOOL AnswerInfo::OnInitDialog()//初始化对话框的函数
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (m_stuInfo.size() > 0)
	{
		m_list.InsertColumn(0, _T("学号"));
		m_list.InsertColumn(1, _T("成绩"));

		CString t_strTemp;
		for (int i = 0; i < m_stuInfo[0].m_nScore.size()-1; i++)
		{
			t_strTemp.Format(_T("%d"), i + 1);
			m_list.InsertColumn(i + 2, t_strTemp + _T("题"));
		}
		CRect rect;
		m_list.GetClientRect(rect); //获得当前客户区信息  
		for (int i = 0; i < m_stuInfo[0].m_nScore.size()+1; i++)
		{
			m_list.SetColumnWidth(i, rect.Width() / m_stuInfo[0].m_nScore.size() + 2); //设置列的宽度。  
			//m_list.SetColumnWidth(1, rect.Width() / 2);
		}
		
		for (int i = 0; i < m_stuInfo.size(); i++)
		{
			t_strTemp.Format(_T("%d"), m_stuInfo[i].m_nScore[m_stuInfo[i].m_nScore.size() - 1]);
			m_list.InsertItem(i, m_stuInfo[i].m_strName);
			m_list.SetItemText(i, 1, t_strTemp);
			for (int j = 0; j < m_stuInfo[0].m_nScore.size()-1; j++)
			{
				t_strTemp.Format(_T("%d"), m_stuInfo[i].m_nScore[j]);
				m_list.SetItemText(i, j+2, t_strTemp);
			}
		}

	}
	else
	{
		//MessageBox(_T("无有效信息"));
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


//void AnswerInfo::OnNMDblclkList(NMHDR* pNMHDR, LRESULT* pResult)
//{
//	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//	// TODO: 在此添加控件通知处理程序代码
//	int t_nCounter = 0;
//	while (true)
//	{
//		AnswerInfoDetail t_MyDetail;
//		CString t_strTemp;
//		for (int i = 0; i < m_stuInfo[t_nCounter].m_nScore.size(); i++)
//		{
//			t_strTemp.Format(_T("%d"), m_stuInfo[t_nCounter].m_nScore[i]);
//			t_MyDetail.m_strDetail += t_strTemp;
//			t_MyDetail.m_strDetail += _T(" ; ");
//		}
//		t_MyDetail.m_strName = m_stuInfo[t_nCounter].m_strName;
//		int t_nOrder = t_MyDetail.DoModal();
//		if (t_nOrder == -1 && t_nCounter != 0)
//		{
//			t_nCounter--;
//			continue;
//		}
//		else if(t_nOrder==1&&t_nCounter!=m_stuInfo.size()-1)
//		{
//			t_nCounter++;
//			continue;
//		}
//		else if (t_nOrder == 0)
//		{
//			break;
//		}
//		else
//		{
//			MessageBox(_T("已经是第一个或最后一个学生"));
//		}
//	}
//	*pResult = 0;
//}
