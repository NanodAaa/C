// CDeleteDlg.h

#pragma once
#include "afxdialogex.h"


// CDeleteDlg 对话框

class CDeleteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteDlg)

public:
	CDeleteDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDeleteDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDeleteDelallButton();
	afx_msg void OnBnClickedDeleteDelButton();
	
	// 要删除员工的工号
	CEdit m_editNum;


};
