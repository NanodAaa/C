#pragma once
#include "afxdialogex.h"


// CModifyDlg 对话框

class CModifyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CModifyDlg)

public:
	CModifyDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CModifyDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MODIFY_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 要修改的员工的工号
	CEdit m_editNum;
	// 要修改的员工的名字
	CEdit m_editName;
	// 要修改的员工的工资
	CEdit m_editPay;
	// 要修改的员工的职位
	CEdit m_editPosition;
	afx_msg void OnBnClickedOk();
};
