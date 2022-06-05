// CStudent.h
// 用于储存 CAddDlg.cpp 中储存的数据，便于 EMPdlg.cpp 调用

#pragma once

//#include "atlstr.h"
//#include "Afxtempl.h"

#include <afxtempl.h>

class CStudent
{
public:
	CStudent(void) {};

	// 储存员工信息
	CString m_strFullName;
	CString m_strNum;
	CString m_strPay;
	CString m_strPosition;

	// Clist.Find 的判断条件
	bool operator== (const CStudent& src) const
	{
		return (m_strNum == src.m_strNum);
	}

};
