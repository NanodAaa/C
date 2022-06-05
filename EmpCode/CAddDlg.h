// CAddDlg.h

#pragma once
#include "afxdialogex.h"


// CAddDlg 对话框

class CAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddDlg)

public:
	CAddDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CAddDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnBnClickedAddFindButton();
	afx_msg void OnBnClickedAddAddButton();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEditNum();
	afx_msg void OnEnChangeEditName();

	// 员工号
	CEdit m_editNum;
	// 员工姓名
	CEdit m_editName;
	// 员工工资
	CEdit m_editPay;
	// 员工职位	// 员工职位
	CEdit m_editPosition;



	// 储存员工号
	CString m_strNum;
	// 储存员工姓名
	CString m_strName;
	// 储存员工工资
	CString m_strPay;
	// 储存员工职位
	CString m_strPosition;
	
	afx_msg void OnEnChangeEditPay();
};
