// CAddDlg.cpp: 实现文件
//

#include "pch.h"
#include "EmployeManage.h"
#include "afxdialogex.h"
#include "CAddDlg.h"
#include <iostream>
#include "Afxtempl.h"
#include "CTipError.h"
#include "EmployeManageDlg.h"

using namespace std;

// CAddDlg 对话框

IMPLEMENT_DYNAMIC(CAddDlg, CDialogEx)

CAddDlg::CAddDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_DIALOG, pParent)
{

}

// 析构函数
CAddDlg::~CAddDlg()
{

}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NUM, m_editNum);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_EDIT_PAY, m_editPay);
	DDX_Control(pDX, IDC_EDIT_POSITION, m_editPosition);
}


BEGIN_MESSAGE_MAP(CAddDlg, CDialogEx)
	//ON_BN_CLICKED(IDC_ADD_FIND_BUTTON, &CAddDlg::OnBnClickedAddFindButton)
	ON_BN_CLICKED(IDC_ADD_ADD_BUTTON, &CAddDlg::OnBnClickedAddAddButton)
	ON_BN_CLICKED(IDCANCEL, &CAddDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT_NUM, &CAddDlg::OnEnChangeEditNum)
	ON_EN_CHANGE(IDC_EDIT_NAME, &CAddDlg::OnEnChangeEditName)
	ON_EN_CHANGE(IDC_EDIT_PAY, &CAddDlg::OnEnChangeEditPay)
END_MESSAGE_MAP()


// CAddDlg 消息处理程序

// “添加”窗口 “添加”按钮
void CAddDlg::OnBnClickedAddAddButton()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	
	CString strEditNum;
	CString strEditName;
	CString strEditPay;
	CString strEditPosition;

	// 获取编辑框的数据
	m_editNum.GetWindowText(strEditNum);
	m_editName.GetWindowText(strEditName);
	m_editPay.GetWindowText(strEditPay);
	m_editPosition.GetWindowText(strEditPosition);
	//m_editNum.getwindow

	bool errFlag = FALSE; // 错误标志

	// 判断输入是否为空
	if (strEditNum.IsEmpty())
	{
		MessageBox(TEXT("未填写员工号！"));
		errFlag = TRUE; // 将错误标志设为 TRUE
	}
	else if (strEditName.IsEmpty())
	{
		MessageBox(TEXT("未填写员工姓名！"));
		errFlag = TRUE;
	}
	else if (strEditPay.IsEmpty())
	{
		MessageBox(TEXT("未填写员工工资！"));
		errFlag = TRUE;
	}
	else if (strEditPosition.IsEmpty())
	{
		MessageBox(TEXT("未填写员工职位！"));
		errFlag = TRUE;
	}
	if(errFlag == TRUE)
	{
		MessageBox(TEXT("添加员工信息失败！"));
	}
	else
	{
		MessageBox(TEXT("添加员工信息成功！"));
	}

	// 保存到 CAddDlg 的成员变量
	m_strName = strEditName;
	m_strNum = strEditNum;		
	m_strPay = strEditPay;
	m_strPosition = strEditPosition;

	// 判断员工名的输入是否重复

	UpdateData(FALSE);

	OnOK();    //OnOK会退出对话框，并返回IDOK

}

// “添加员工”窗口 “返回”按钮
void CAddDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CAddDlg::OnEnChangeEditNum()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CAddDlg::OnEnChangeEditName()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CAddDlg::OnEnChangeEditPay()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
