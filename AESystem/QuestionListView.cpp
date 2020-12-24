//********************************************************************************************************
//文件名:                                       QuestionListView.cpp
//版本:                                         1.0
//目的及主要功能:                               新建的视图类，出题时用来显示题目列表
//创建日期:                                     2020.9.6
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#include "pch.h"
#include "QuestionListView.h"
#include"AEsystemDoc.h"
#include"ExistingQuestion.h"

QuestionListView::QuestionListView()
	:m_nQuestionSize(),
	m_bIsFirst(true)
{

}

QuestionListView::~QuestionListView()
{

}

void QuestionListView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: 在此添加专用代码和/或调用基类
	CAEsystemDoc* t_pDocData = (CAEsystemDoc*)GetDocument();//获取文件的指针

	if (m_bIsFirst)//如果是第一次update
	{
		m_nQuestionSize = t_pDocData->m_TpMyTestPaper.m_nPaperNum;//获取试题长度

		CListCtrl& m_list = GetListCtrl();//得到内置的listctrl引用

		LONG lStyle;
		lStyle = GetWindowLong(m_list.m_hWnd, GWL_STYLE);//获取当前窗口风格
		lStyle &= ~LVS_TYPEMASK; //清除显示方式位
		lStyle |= LVS_REPORT; //设置报表风格
		SetWindowLong(m_list.m_hWnd, GWL_STYLE, lStyle); //设置窗口风格
		DWORD dwStyle = m_list.GetExtendedStyle();

		//选中某行使整行高亮（只适用于报表风格的listctrl）
		dwStyle |= LVS_EX_FULLROWSELECT;
		dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与报表风格的listctrl）
		m_list.SetExtendedStyle(dwStyle); //设置扩展风格
		m_list.SetBkColor(RGB(200, 200, 200)); //设置背景颜色
		m_list.SetTextBkColor(RGB(200, 200, 200)); //设置文本背景颜色
		m_list.SetTextColor(RGB(10, 10, 80)); //设置文本颜色
		//插入列的标题，为了简单起见，我只插入三列

		m_list.InsertColumn(0, _T("题目序号"), LVCFMT_CENTER, 110);
		m_list.InsertColumn(1, _T("题目类型"), LVCFMT_CENTER, 110);
		m_list.InsertColumn(2, _T("题目分值"), LVCFMT_CENTER, 110);

		for (int i = 0; i < m_nQuestionSize; i++)//初始化表格
		{
			CString t_strTemp;//将数字转化成字符串的过度字符串
			t_strTemp.Format(_T("%d"), i+1);

			m_list.InsertItem(i, t_strTemp);//创建行
			if (t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[i]->m_nType == SINGLE_CHOICE)//如果是单选题
				m_list.SetItemText(i, 1, _T("单选题"));
			if (t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[i]->m_nType == MULTIPLE_CHOICE)//如果是多选题
				m_list.SetItemText(i, 1, _T("多选题"));
			if (t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[i]->m_nType == SHORT_ANSWER)//如果是简答题
				m_list.SetItemText(i, 1, _T("简答题"));
			if (t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[i]->m_nType == JUDGMENT_CHOICE)//如果是判断题
				m_list.SetItemText(i, 1, _T("判断题"));

			t_strTemp.Format(_T("%d"), t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[i]->m_nScore);//将题目分数转为字符串
			m_list.SetItemText(i, 2, t_strTemp);//输出分值
		}

		m_bIsFirst = false;
	}
	else//如果不是第一次update,则一定发生在添加试题的过程当中
	{
		CListCtrl& m_list = GetListCtrl();//得到内置的listctrl引用
		CString t_strTemp;

		t_strTemp.Format(_T("%d"), m_nQuestionSize+1);
		m_list.InsertItem(m_nQuestionSize, t_strTemp);

		if (t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[m_nQuestionSize]->m_nType == SINGLE_CHOICE)//如果是单选题
			m_list.SetItemText(m_nQuestionSize, 1, _T("单选题"));
		if (t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[m_nQuestionSize]->m_nType == MULTIPLE_CHOICE)//如果是多选题
			m_list.SetItemText(m_nQuestionSize, 1, _T("多选题"));
		if (t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[m_nQuestionSize]->m_nType == SHORT_ANSWER)//如果是简答题
			m_list.SetItemText(m_nQuestionSize, 1, _T("简答题"));
		if (t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[m_nQuestionSize]->m_nType == JUDGMENT_CHOICE)//如果是判断题
			m_list.SetItemText(m_nQuestionSize, 1, _T("判断题"));

		t_strTemp.Format(_T("%d"), t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[m_nQuestionSize]->m_nScore);//将题目分数转为字符串
		m_list.SetItemText(m_nQuestionSize, 2, t_strTemp);//输出分值

		m_nQuestionSize++;//试题数量+1
	}
}
BEGIN_MESSAGE_MAP(QuestionListView, CListView)
	ON_NOTIFY_REFLECT(NM_DBLCLK, &QuestionListView::OnNMDblclk)
END_MESSAGE_MAP()


void QuestionListView::OnNMDblclk(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CAEsystemDoc* t_pDocData = (CAEsystemDoc*)GetDocument();//获取文件的指针
	int t_nCounter = 0;
	CString t_strSrc;
	while (true)
	{
		ExistingQuestion t_eqTemp;
		t_strSrc.Format(_T("%d"), t_nCounter+1);
		t_eqTemp.m_strEqTopic = _T("（第") + t_strSrc + _T("题)") + t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[t_nCounter]->m_strTopic;
		t_eqTemp.m_strEqAnswer = t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[t_nCounter]->m_strAnswer;

		int t_nOrder = t_eqTemp.DoModal();
		if (t_nOrder == 0)
		{
			break;
		}
		else if (t_nOrder == 1 && t_nCounter != t_pDocData->m_TpMyTestPaper.m_nPaperNum - 1)
		{
			t_nCounter++;
			continue;
		}
		else if (t_nOrder == -1 && t_nCounter != 0)
		{
			t_nCounter--;
			continue;
		}
		else
		{
			MessageBox(_T("已经是第一题或最后一题"));
			continue;
		}
	}

	*pResult = 0;
}
