#include "pch.h"
#include "Student.h"

Student::Student(vector<int> score, const CString name)
	:m_strName(name)
{
	for (int i = 0; i < score.size(); i++)
		this->m_nScore.push_back(score[i]);
}

Student::~Student()
{

}