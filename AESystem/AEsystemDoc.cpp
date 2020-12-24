//********************************************************************************************************
//文件名:                                       AEsystemDoc.cpp
//版本:                                         1.0
//目的及主要功能:                               整个程序的文档
//创建日期:                                     2020.9.4
//修改日期:                                     2020.9.4 
//作者:                                         贾晟浩
//修改者:                                       贾晟浩  
//联系方式:
//********************************************************************************************************

// AEsystemDoc.cpp: CAEsystemDoc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "AEsystem.h"
#endif

#include "AEsystemDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAEsystemDoc

IMPLEMENT_DYNCREATE(CAEsystemDoc, CDocument)

BEGIN_MESSAGE_MAP(CAEsystemDoc, CDocument)
END_MESSAGE_MAP()


// CAEsystemDoc 构造/析构

CAEsystemDoc::CAEsystemDoc() noexcept
{
	// TODO: 在此添加一次性构造代码

}

CAEsystemDoc::~CAEsystemDoc()
{
}

BOOL CAEsystemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CAEsystemDoc 序列化

void CAEsystemDoc::Serialize(CArchive& ar)
{
	//只保存试题不保存答案
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		m_TpMyTestPaper.Serialize(ar);
		/*for (int i = 0; i < m_astrMyAnswer.GetSize(); i++)
		{
			ar << m_astrMyAnswer[i];
		}*/
		((CAEsystemApp*)AfxGetApp())->SwitchView();//将试题列表隐藏
	}
	else
	{
		// TODO: 在此添加加载代码
		m_TpMyTestPaper.Serialize(ar);
		/*for (int i = 0; i < m_TpMyTestPaper.m_nPaperNum; i++)
		{
			m_astrMyAnswer.Add(_T(""));
			ar >> m_astrMyAnswer[i];
		}*/
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CAEsystemDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CAEsystemDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CAEsystemDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CAEsystemDoc 诊断

#ifdef _DEBUG
void CAEsystemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAEsystemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CAEsystemDoc 命令


vector<int> CAEsystemDoc::MarkPaper()
{
	// TODO: 在此处添加实现代码.
	vector<int> t_vi;
	int t_nTotalScore = 0;
	for (int i = 0; i < m_TpMyTestPaper.m_nPaperNum; i++)
	{
		t_nTotalScore += m_TpMyTestPaper.m_vpTqExamPaper[i]->MarkPaper(m_astrMyAnswer[i]);
		t_vi.push_back(m_TpMyTestPaper.m_vpTqExamPaper[i]->MarkPaper(m_astrMyAnswer[i]));
	}
	t_vi.push_back(t_nTotalScore);
	return t_vi;
}


void CAEsystemDoc::SetAnswer(const CStringArray& ans)
{
	// TODO: 在此处添加实现代码.
	for (int i = 0; i < m_TpMyTestPaper.m_nPaperNum; i++)
	{
		m_astrMyAnswer.Add(_T(""));
		m_astrMyAnswer[i] = ans[i];
	}
}
