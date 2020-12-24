//********************************************************************************************************
//文件名:                                       AEsystemView.h
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

// AEsystemView.h: CAEsystemView 类的接口
//

#pragma once


class CAEsystemView : public CView
{
protected: // 仅从序列化创建
	CAEsystemView() noexcept;
	DECLARE_DYNCREATE(CAEsystemView)

// 特性
public:
	CAEsystemDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CAEsystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSetQuestion();//单击出题之后的响应函数

	CString m_strVieTopic;//临时储存题目
	CString m_strVieAnswer;//临时储存答案
	int m_nVieScore;//临时储存分数
	int m_nVieType;//临时储存类型
	afx_msg void OnAnswerQuestion();
	afx_msg void CheckInfo();
};

#ifndef _DEBUG  // AEsystemView.cpp 中的调试版本
inline CAEsystemDoc* CAEsystemView::GetDocument() const
   { return reinterpret_cast<CAEsystemDoc*>(m_pDocument); }
#endif

