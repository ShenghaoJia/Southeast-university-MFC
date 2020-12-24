#pragma once
#include<vector>
using namespace std;

class Student
{
public:
	Student(vector<int>,CString);
	~Student();

	vector<int> m_nScore;
	CString m_strName;
};

