//********************************************************************************************************
//文件名:                                       MultipleChoiceQuestion.cpp
//版本:                                         1.0
//目的及主要功能:                               多选题类
//创建日期:                                     2020.9.4
//修改日期:                                      
//作者:                                         贾晟浩
//修改者:                                         
//联系方式:
//********************************************************************************************************
#include "pch.h"
#include "MultipleChoiceQuestion.h"

IMPLEMENT_SERIAL(MultipleChoiceQuestion,CObject,1)

MultipleChoiceQuestion::MultipleChoiceQuestion()
{

}

MultipleChoiceQuestion::~MultipleChoiceQuestion()
{

}

void MultipleChoiceQuestion::Serialize(CArchive& ar)//重写的Serialize函数
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


int MultipleChoiceQuestion::MarkPaper(const CString ans)
{
	// TODO: 在此处添加实现代码.
	CString t_strSrc = ans;//将ans复制一份出来
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

	int t_nSize = t_strResult.GetSize();//取出答案的个数

	
	//同样的办法取出标准答案
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
	if (t_nSize == 0)
	{
		return 0;
	}

	if (t_nSize == t_nStdSize)//如果两个答案相等
	{
		for (int i = 0; i < t_nStdSize;i++)//依次比对
		{
			int j = 0;
			for (; j < t_nSize; j++)
			{
				if (t_strStdResult[i] == t_strResult[j])
					break;
			}
			if (j == t_nSize && t_strStdResult[i] != t_strResult[j-1])//如果已经比对到最后仍然没有找到匹配的答案,说明答案有错
			{
				return 0;
			}
		}
		return this->m_nScore;//所有答案都匹配成功，答案全部正确

	}
	else if (t_nSize < t_nStdSize)//如果学生的答案个数少于标准答案个数
	{
		for (int i = 0; i < t_nSize; i++)//以学生的答案数量作为大循环，从标准答案里找对应的答案
		{
			int j = 0;
			for (; j < t_nStdSize; j++)
			{
				if (t_strResult[i] == t_strStdResult[j])
					break;
			}
			if (j == t_nStdSize && t_strStdResult[j-1] != t_strResult[i])//如果已经比对到最后仍然没有找到匹配的答案,说明答案有错
			{
				return 0;
			}
		}
		return this->m_nScore / 2;//学生所有的答案都在标准答案中，给一半分
	}
	else//学生给出的答案比标准答案多，一定有错
	{
		return 0;
	}
	
}
