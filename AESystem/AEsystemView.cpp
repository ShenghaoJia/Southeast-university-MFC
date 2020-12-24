//********************************************************************************************************
//文件名:                                       AEsystemView.cpp
//版本:                                         1.0
//目的及主要功能:                               整个程序的初始视图类
//创建日期:                                     2020.9.4
//修改日期:                                     2020.9.5
//                                              2020.9.6
//                                              2020.9.7
//作者:                                         贾晟浩
//修改者:                                       贾晟浩  
//联系方式:
//********************************************************************************************************

// AEsystemView.cpp: CAEsystemView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "AEsystem.h"
#endif

#include "AEsystemDoc.h"
#include "AEsystemView.h"
#include"ChooseType.h"
#include"ChooseTypeSin.h"
#include"ChooseTypeMul.h"
#include"ChooseTypeSA.h"
#include"ChooseTypeJud.h"
#include"QuestionListView.h"
#include"ChooseTypeSinA.h"
#include"ChooseTypeMulA.h"
#include"ChooseTypeSAA.h"
#include"ChooseTypeJudA.h"
#include"EnterName.h"
#include"AnswerInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAEsystemView

IMPLEMENT_DYNCREATE(CAEsystemView, CView)

BEGIN_MESSAGE_MAP(CAEsystemView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CAEsystemView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32771, &CAEsystemView::OnSetQuestion)
	ON_COMMAND(ID_32772, &CAEsystemView::OnAnswerQuestion)
	ON_COMMAND(ID_32773, &CAEsystemView::CheckInfo)
END_MESSAGE_MAP()

// CAEsystemView 构造/析构

CAEsystemView::CAEsystemView() noexcept
{
	// TODO: 在此处添加构造代码

	m_strVieTopic = _T("");
	m_strVieAnswer = _T("");
	m_nVieScore = 0;
	m_nVieType = 0;
}

CAEsystemView::~CAEsystemView()
{
}

BOOL CAEsystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CAEsystemView 绘图

void CAEsystemView::OnDraw(CDC* /*pDC*/)
{
	CAEsystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CAEsystemView 打印


void CAEsystemView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CAEsystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CAEsystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CAEsystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CAEsystemView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CAEsystemView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CAEsystemView 诊断

#ifdef _DEBUG
void CAEsystemView::AssertValid() const
{
	CView::AssertValid();
}

void CAEsystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAEsystemDoc* CAEsystemView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAEsystemDoc)));
	return (CAEsystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CAEsystemView 消息处理程序


void CAEsystemView::OnSetQuestion()//单击出题后的响应函数
{
	CAEsystemDoc* t_pDocData = this->GetDocument();//获取文档类的指针
	if (t_pDocData->m_TpMyTestPaper.m_nPaperNum != 0)
	{
		MessageBox(_T("当前系统中已经存在试题，无法再次出题"));
	}
	else
	{
		ChooseType t_CtDlg;//选择类型对话框的对象

		((CAEsystemApp*)AfxGetApp())->SwitchView();//初始化试题列表

		while (t_pDocData->m_TpMyTestPaper.m_nTotalScore != 100)//如果总分没有到100分，一直循环
		{
			t_CtDlg.DoModal();//选择类型对话框显示
			this->m_nVieType = t_CtDlg.m_nType;//拿到选择框的选项

			if (this->m_nVieType == SINGLE_CHOICE)//如果选择的是单选题
			{
				ChooseTypeSin t_CtsDlg;//定义单选题的对话框对象
				if (t_CtsDlg.DoModal() == IDOK)
				{
					//t_CtsDlg.DoModal();//单选题对话框显示
					//将单选框中获得的信息传入view类的数据成员中，包括题目，答案和分数
					this->m_strVieTopic = t_CtsDlg.m_strSinTopicTotal;
					this->m_strVieAnswer = t_CtsDlg.m_strSinAnswer;
					this->m_nVieScore = t_CtsDlg.m_nSinScore;

					while (!t_pDocData->m_TpMyTestPaper.AddQuestion(this->m_strVieTopic, this->m_strVieAnswer, this->m_nVieScore, SINGLE_CHOICE))//如果增加题目没有成功，即总分超过了100分
					{
						//将上面的步骤不断重复
						MessageBox(_T("总分超过100分，请修改分值"));
						t_CtsDlg.DoModal();
						this->m_strVieTopic = t_CtsDlg.m_strSinTopicTotal;
						this->m_strVieAnswer = t_CtsDlg.m_strSinAnswer;
						this->m_nVieScore = t_CtsDlg.m_nSinScore;
					}

					MessageBox(_T("试题添加成功"));//显示“试题添加成功”
					t_pDocData->UpdateAllViews(NULL);//更新试题列表数据
				}

			}
			if (this->m_nVieType == MULTIPLE_CHOICE)//如果选择的是多选题
			{
				ChooseTypeMul t_CtmDlg;
				if (t_CtmDlg.DoModal() == IDOK)
				{
					//t_CtmDlg.DoModal();
					this->m_strVieTopic = t_CtmDlg.m_strMulTopicTotal;
					this->m_strVieAnswer = t_CtmDlg.m_strMulAnswer;
					this->m_nVieScore = t_CtmDlg.m_nMulScore;

					while (!t_pDocData->m_TpMyTestPaper.AddQuestion(this->m_strVieTopic, this->m_strVieAnswer, this->m_nVieScore, MULTIPLE_CHOICE))
					{
						MessageBox(_T("总分超过100分，请修改分值"));
						t_CtmDlg.DoModal();
						this->m_strVieTopic = t_CtmDlg.m_strMulTopicTotal;
						this->m_strVieAnswer = t_CtmDlg.m_strMulAnswer;
						this->m_nVieScore = t_CtmDlg.m_nMulScore;
					}
					MessageBox(_T("试题添加成功"));
					t_pDocData->UpdateAllViews(NULL);
				}

			}
			if (this->m_nVieType == SHORT_ANSWER)//如果选择的是简答题
			{
				ChooseTypeSA t_CtsaDlg;
				if (t_CtsaDlg.DoModal() == IDOK)
				{
					//t_CtsaDlg.DoModal();
					this->m_strVieTopic = t_CtsaDlg.m_strSaTopic;
					this->m_strVieAnswer = t_CtsaDlg.m_strSaAnswer;
					this->m_nVieScore = t_CtsaDlg.m_nSaScore;

					while (!t_pDocData->m_TpMyTestPaper.AddQuestion(this->m_strVieTopic, this->m_strVieAnswer, this->m_nVieScore, SHORT_ANSWER))
					{
						MessageBox(_T("总分超过100分，请修改分值"));
						t_CtsaDlg.DoModal();
						this->m_strVieTopic = t_CtsaDlg.m_strSaTopic;
						this->m_strVieAnswer = t_CtsaDlg.m_strSaAnswer;
						this->m_nVieScore = t_CtsaDlg.m_nSaScore;
					}
					MessageBox(_T("试题添加成功"));
					t_pDocData->UpdateAllViews(NULL);
				}

			}
			if (this->m_nVieType == JUDGMENT_CHOICE)//如果选择的是判断题
			{
				//t_CtjDlg.DoModal();
				ChooseTypeJud t_CtjDlg;
				if (t_CtjDlg.DoModal() == IDOK)
				{
					this->m_strVieTopic = t_CtjDlg.m_strJudTopic;
					this->m_strVieAnswer = t_CtjDlg.m_strJudAnswer;
					this->m_nVieScore = t_CtjDlg.m_nJudScore;

					while (!t_pDocData->m_TpMyTestPaper.AddQuestion(this->m_strVieTopic, this->m_strVieAnswer, this->m_nVieScore, JUDGMENT_CHOICE))
					{
						MessageBox(_T("总分超过100分，请修改分值"));
						t_CtjDlg.DoModal();
						this->m_strVieTopic = t_CtjDlg.m_strJudTopic;
						this->m_strVieAnswer = t_CtjDlg.m_strJudAnswer;
						this->m_nVieScore = t_CtjDlg.m_nJudScore;

					}
					MessageBox(_T("试题添加成功"));
					t_pDocData->UpdateAllViews(NULL);
				}
			}
		}

		MessageBox(_T("您的出题已满100分，出题结束，请点击保存按钮保存,保存后方可答题"));//总分数达到100分，出题结束
	}

	
	// TODO: 在此添加命令处理程序代码
}


void CAEsystemView::OnAnswerQuestion()
{
	CAEsystemDoc* t_pDocData = this->GetDocument();//获取文档类的指针
	if (t_pDocData->m_TpMyTestPaper.m_nPaperNum == 0)
		MessageBox(_T("题库里暂时没有试题，无法考试"));
	else
	{
		EnterName t_enStuName;
		t_enStuName.DoModal();//显示输入名字对话框

		CStringArray t_strAns;
		for (int i = 0; i < t_pDocData->m_TpMyTestPaper.m_nPaperNum; i++)//先将答案的容器创建好
		{
			t_strAns.Add(_T(""));
		}
		int t_nCounter = 0;
		while (true)
		{
			if (t_pDocData->m_TpMyTestPaper.m_vnPaperType[t_nCounter] == SINGLE_CHOICE)
			{
				ChooseTypeSinA t_CtsaTemp;
				t_CtsaTemp.TopicAnalyze(t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[t_nCounter]->m_strTopic, t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[t_nCounter]->m_nScore);
				t_CtsaTemp.m_strSinAAnswer = t_strAns[t_nCounter];

				int t_nOrder = t_CtsaTemp.DoModal();
				if (t_nOrder==0)//如果点击交卷
				{
					MessageBox(_T("交卷成功"));
					t_strAns[t_nCounter] = t_CtsaTemp.m_strSinAAnswer;
					break;
				}
				else if (t_nOrder == -1 && t_nCounter != 0)//如果点击了上一题且该题不是第一题
				{
					t_strAns[t_nCounter] = t_CtsaTemp.m_strSinAAnswer;
					t_nCounter--;
					continue;
				}
				else if (t_nOrder == 1 && t_nCounter != t_pDocData->m_TpMyTestPaper.m_nPaperNum-1)//如果点击了下一题且该题不是最后一题
				{
					t_strAns[t_nCounter] = t_CtsaTemp.m_strSinAAnswer;
					t_nCounter++;
					continue;
				}
				else
				{
					MessageBox(_T("该题已经是第一题或者最后一题"));
					t_strAns[t_nCounter] = t_CtsaTemp.m_strSinAAnswer;
					continue;
				}
			}
			if (t_pDocData->m_TpMyTestPaper.m_vnPaperType[t_nCounter] == MULTIPLE_CHOICE)
			{
				ChooseTypeMulA t_CtmaTemp;
				t_CtmaTemp.TopicAnalyze(t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[t_nCounter]->m_strTopic, t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[t_nCounter]->m_nScore);
				t_CtmaTemp.m_strMulAAnswer = t_strAns[t_nCounter];

				int t_nOrder = t_CtmaTemp.DoModal();
				if (t_nOrder == 0)//如果点击交卷
				{
					MessageBox(_T("交卷成功"));
					t_strAns[t_nCounter] = t_CtmaTemp.m_strMulAAnswer;
					break;
				}
				else if (t_nOrder == -1 && t_nCounter != 0)//如果点击了上一题且该题不是第一题
				{
					t_strAns[t_nCounter] = t_CtmaTemp.m_strMulAAnswer;
					t_nCounter--;
					continue;
				}
				else if (t_nOrder == 1 && t_nCounter != t_pDocData->m_TpMyTestPaper.m_nPaperNum - 1)//如果点击了下一题且该题不是最后一题
				{
					t_strAns[t_nCounter] = t_CtmaTemp.m_strMulAAnswer;
					t_nCounter++;
					continue;
				}
				else
				{
					MessageBox(_T("该题已经是第一题或者最后一题"));
					t_strAns[t_nCounter] = t_CtmaTemp.m_strMulAAnswer;
					continue;
				}
			}
			if (t_pDocData->m_TpMyTestPaper.m_vnPaperType[t_nCounter] == SHORT_ANSWER)
			{
				ChooseTypeSAA t_CtsaaTemp;
				t_CtsaaTemp.TopicAnalyze(t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[t_nCounter]->m_strTopic, t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[t_nCounter]->m_nScore);
				t_CtsaaTemp.m_strSaAAnswer = t_strAns[t_nCounter];

				int t_nOrder = t_CtsaaTemp.DoModal();
				if (t_nOrder == 0)//如果点击交卷
				{
					MessageBox(_T("交卷成功"));
					t_strAns[t_nCounter] = t_CtsaaTemp.m_strSaAAnswer;
					break;
				}
				else if (t_nOrder == -1 && t_nCounter != 0)//如果点击了上一题且该题不是第一题
				{
					t_strAns[t_nCounter] = t_CtsaaTemp.m_strSaAAnswer;
					t_nCounter--;
					continue;
				}
				else if (t_nOrder == 1 && t_nCounter != t_pDocData->m_TpMyTestPaper.m_nPaperNum - 1)//如果点击了下一题且该题不是最后一题
				{
					t_strAns[t_nCounter] = t_CtsaaTemp.m_strSaAAnswer;
					t_nCounter++;
					continue;
				}
				else
				{
					MessageBox(_T("该题已经是第一题或者最后一题"));
					t_strAns[t_nCounter] = t_CtsaaTemp.m_strSaAAnswer;
					continue;
				}

			}
			if (t_pDocData->m_TpMyTestPaper.m_vnPaperType[t_nCounter] == JUDGMENT_CHOICE)
			{
				ChooseTypeJudA t_CtjaTemp;
				t_CtjaTemp.TopicAnalyze(t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[t_nCounter]->m_strTopic, t_pDocData->m_TpMyTestPaper.m_vpTqExamPaper[t_nCounter]->m_nScore);
				t_CtjaTemp.m_strJudAAnswer = t_strAns[t_nCounter];

				int t_nOrder = t_CtjaTemp.DoModal();
				if (t_nOrder == 0)//如果点击交卷
				{
					MessageBox(_T("交卷成功"));
					t_strAns[t_nCounter] = t_CtjaTemp.m_strJudAAnswer;
					break;
				}
				else if (t_nOrder == -1 && t_nCounter != 0)//如果点击了上一题且该题不是第一题
				{
					t_strAns[t_nCounter] = t_CtjaTemp.m_strJudAAnswer;
					t_nCounter--;
					continue;
				}
				else if (t_nOrder == 1 && t_nCounter != t_pDocData->m_TpMyTestPaper.m_nPaperNum - 1)//如果点击了下一题且该题不是最后一题
				{
					t_strAns[t_nCounter] = t_CtjaTemp.m_strJudAAnswer;
					t_nCounter++;
					continue;
				}
				else
				{
					MessageBox(_T("该题已经是第一题或者最后一题"));
					t_strAns[t_nCounter] = t_CtjaTemp.m_strJudAAnswer;
					continue;
				}
			}
		}
		//答题完毕，开始判卷
		CString t_strScore;
		t_pDocData->SetAnswer(t_strAns);
		vector<int> t_nTotalScore = t_pDocData->MarkPaper();
		t_strScore.Format(_T("%d"), t_nTotalScore[t_nTotalScore.size() - 1]);
		MessageBox(_T("答题结束，您的总分是 ") + t_strScore + _T(" 分"));

		t_pDocData->m_vsStuIfo.push_back(Student(t_nTotalScore, t_enStuName.m_strName));
	}

	// TODO: 在此添加命令处理程序代码
}


void CAEsystemView::CheckInfo()
{
	CAEsystemDoc* t_pDocData = this->GetDocument();//获取文档类的指针
	AnswerInfo t_ansInfo;

	for (int i = 0; i < t_pDocData->m_vsStuIfo.size(); i++)
	{
		t_ansInfo.m_stuInfo.push_back(Student(t_pDocData->m_vsStuIfo[i].m_nScore, t_pDocData->m_vsStuIfo[i].m_strName));
	}

	t_ansInfo.DoModal();
	// TODO: 在此添加命令处理程序代码
}
