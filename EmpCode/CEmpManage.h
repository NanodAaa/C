#pragma once
#include "afxdialogex.h"


// CEmpManage 对话框

class CEmpManage : public CDialogEx
{
	DECLARE_DYNAMIC(CEmpManage)

public:
	CEmpManage(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CEmpManage();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EMPLOYEMANAGE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
