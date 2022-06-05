// CEmpManage.cpp: 实现文件
//

#include "pch.h"
#include "EmployeManage.h"
#include "afxdialogex.h"
#include "CEmpManage.h"


// CEmpManage 对话框

IMPLEMENT_DYNAMIC(CEmpManage, CDialogEx)

CEmpManage::CEmpManage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EMPLOYEMANAGE_DIALOG, pParent)
{

}

CEmpManage::~CEmpManage()
{
}

void CEmpManage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEmpManage, CDialogEx)
END_MESSAGE_MAP()


// CEmpManage 消息处理程序
