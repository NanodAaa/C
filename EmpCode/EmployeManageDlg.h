
// EmployeManageDlg.h: 头文件
//

#pragma once

#include "CStudent.h"

// CEmployeManageDlg 对话框
class CEmployeManageDlg : public CDialogEx
{
// 构造
public:
	CEmployeManageDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EMPLOYEMANAGE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddButton();
	afx_msg void OnBnClickedFindButton();

	CList <CStudent, CStudent&> m_StudentList; // 用来储存 员工信息的链表


	afx_msg void OnBnClickedDeleteButton();
	afx_msg void OnBnClickedModifyButton();
	afx_msg void OnBnClickedImportButton();
	afx_msg void OnBnClickedExportButton();
	afx_msg void OnBnClickedBrowseButton();
};
