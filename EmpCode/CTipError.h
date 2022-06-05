#pragma once
#include "afxdialogex.h"


// CTipError 对话框

class CTipError : public CDialogEx
{
	DECLARE_DYNAMIC(CTipError)

public:
	CTipError(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTipError();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIP_ERR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
