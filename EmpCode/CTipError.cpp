// CTipError.cpp: 实现文件
//

#include "pch.h"
#include "EmployeManage.h"
#include "afxdialogex.h"
#include "CTipError.h"


// CTipError 对话框

IMPLEMENT_DYNAMIC(CTipError, CDialogEx)

CTipError::CTipError(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TIP_ERR, pParent)
{

}

CTipError::~CTipError()
{
}

void CTipError::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTipError, CDialogEx)
END_MESSAGE_MAP()


// CTipError 消息处理程序
