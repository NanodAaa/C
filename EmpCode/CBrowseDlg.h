#pragma once
#include "afxdialogex.h"


// CBrowseDlg 对话框

class CBrowseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBrowseDlg)

public:
	CBrowseDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CBrowseDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BROWSE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	
	
	// 浏览员工
	CListCtrl m_browseList;
	afx_msg void OnLvnItemchangedBrowseList(NMHDR* pNMHDR, LRESULT* pResult);

	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRefreshButton();
};
