// CStudent.h
// ���ڴ��� CAddDlg.cpp �д�������ݣ����� EMPdlg.cpp ����

#pragma once

//#include "atlstr.h"
//#include "Afxtempl.h"

#include <afxtempl.h>

class CStudent
{
public:
	CStudent(void) {};

	// ����Ա����Ϣ
	CString m_strFullName;
	CString m_strNum;
	CString m_strPay;
	CString m_strPosition;

	// Clist.Find ���ж�����
	bool operator== (const CStudent& src) const
	{
		return (m_strNum == src.m_strNum);
	}

};
