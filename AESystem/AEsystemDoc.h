//********************************************************************************************************
//文件名:                                       AEsystemDoc.h
//版本:                                         1.0
//目的及主要功能:                               整个程序的文档
//创建日期:                                     2020.9.4
//修改日期:                                     2020.9.4 
//作者:                                         贾晟浩
//修改者:                                       贾晟浩
//联系方式:
//********************************************************************************************************

// AEsystemDoc.h: CAEsystemDoc 类的接口
//


#pragma once
#include"TestPaper.h"
#include"Student.h"

class CAEsystemDoc : public CDocument
{
protected: // 仅从序列化创建
	CAEsystemDoc() noexcept;
	DECLARE_DYNCREATE(CAEsystemDoc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CAEsystemDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	TestPaper m_TpMyTestPaper;//试卷
	CStringArray m_astrMyAnswer;//答案（因为有多道题所以用CString类型的数组）
	vector<Student> m_vsStuIfo;
	vector<int> MarkPaper();
	void SetAnswer(const CStringArray& ans);
};
