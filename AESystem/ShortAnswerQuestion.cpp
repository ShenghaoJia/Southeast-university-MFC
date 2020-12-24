//********************************************************************************************************
//文件名:                                       ShortAnswerQuestion.cpp
//版本:                                         1.0
//目的及主要功能:                               简答题类
//创建日期:                                     2020.9.4
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#include "pch.h"
#include "ShortAnswerQuestion.h"

IMPLEMENT_SERIAL(ShortAnswerQuestion,CObject,1)

ShortAnswerQuestion::ShortAnswerQuestion()
{

}

ShortAnswerQuestion::~ShortAnswerQuestion()
{

}

void ShortAnswerQuestion::Serialize(CArchive& ar)//重写的Serialize函数
{
	if (ar.IsStoring())
	{	// storing code
		ar << m_strTopic << m_strAnswer << m_nScore << m_nType;
	}
	else
	{	// loading code
		ar >> m_strTopic >> m_strAnswer >> m_nScore >> m_nType;
	}
}


int ShortAnswerQuestion::MarkPaper(const CString ans)
{
	// TODO: 在此处添加实现代码.
	//和多选题类的判卷相似，先从标准答案里取出关键词

	CString strGap = _T(";");
	CString t_strStdSrc = this->m_strAnswer;
	CStringArray t_strStdResult;

	int t_nStdPos = t_strStdSrc.Find(strGap);

	CString t_strStdLeft = _T("");
	while (t_nStdPos >= 0)
	{
		t_strStdLeft = t_strStdSrc.Left(t_nStdPos);
		if (!t_strStdLeft.IsEmpty())
			t_strStdResult.Add(t_strStdLeft);

		t_strStdSrc = t_strStdSrc.Right(t_strStdSrc.GetLength() - t_nStdPos - 1);
		t_nStdPos = t_strStdSrc.Find(strGap);

	}

	if (!t_strStdSrc.IsEmpty())
	{
		t_strStdResult.Add(t_strStdSrc);
	}

	int t_nStdSize = t_strStdResult.GetSize();

	///////////////////////////////////////////////////////////////////////////////////
	int t_nCorrectNum = 0;//能够匹配到的关键词的个数

	for (int i = 0; i < t_nStdSize; i++)//每个关键词进行比对
	{
		int t_nIsFind = ans.Find(t_strStdResult[i]);
		if (t_nIsFind != -1)
			t_nCorrectNum++;
	}
	if (t_nStdSize == t_nCorrectNum)
	{
		return this->m_nScore;
	}
	else
	{
		double t_dReturnValue = (this->m_nScore / t_nStdSize) * t_nCorrectNum;//按关键词的总数和匹配到关键词的个数进行打分
		return t_dReturnValue;
	}
	

}
