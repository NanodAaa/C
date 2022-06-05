#pragma once
#include "afxdialogex.h"


// CFindDlg 对话框

class CFindDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFindDlg)

public:
	CFindDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CFindDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIND_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 员工名
	CEdit m_editNum;
	// 员工名
	CEdit m_editName;
	afx_msg void OnBnClickedFindFindButton();
	afx_msg void OnBnClickedCancel();
	// 员工工资
	CEdit m_editPay;
	// 员工职位
	CEdit m_editPosition;
};
