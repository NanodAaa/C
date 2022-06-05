// CFindDlg.cpp: 实现文件
//

#include "pch.h"
#include "EmployeManage.h"
#include "afxdialogex.h"
#include "CFindDlg.h"
#include "EmployeManageDlg.h"
#include "CStudent.h"
#include "framework.h"
#include "CAddDlg.h"


using namespace std;

// CFindDlg 对话框

IMPLEMENT_DYNAMIC(CFindDlg, CDialogEx)

CFindDlg::CFindDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FIND_DIALOG, pParent)
{

}

CFindDlg::~CFindDlg()
{
}

void CFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NUM, m_editNum);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_EDIT_FIND_PAY, m_editPay);
	DDX_Control(pDX, IDC_EDIT_FIND_POSITION, m_editPosition);
}


BEGIN_MESSAGE_MAP(CFindDlg, CDialogEx)
	ON_BN_CLICKED(IDC_FIND_FIND_BUTTON, &CFindDlg::OnBnClickedFindFindButton)
	ON_BN_CLICKED(IDCANCEL, &CFindDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CFindDlg 消息处理程序

// 点击“查找员工”窗口 “查找”按钮
void CFindDlg::OnBnClickedFindFindButton()
{
	// TODO: 在此添加控件通知处理程序代码

	CString strEditNum;
	CString strEditName;
	CString strEditPay;
	CString strEditPosition;

	UpdateData(TRUE);
	m_editNum.GetWindowText(strEditNum);

	// 检查 员工号 是否填写
	if (strEditNum.IsEmpty())
	{
		MessageBox(TEXT("未输入员工号！"));
		return;
	}

	CEmployeManageDlg* pManageDlg = (CEmployeManageDlg*)m_pParentWnd; // 访问父窗口的数据
	
	// 将 编辑框 中数据暂存至 CStudent 中
	CStudent stu; // 创建新的 CStudent 对象
	stu.m_strNum = strEditNum;
	stu.m_strFullName = strEditName;
	stu.m_strPay = strEditPay;
	stu.m_strPosition = strEditPosition;

	// 对比 CStudent 中数据 和 链表中数据 若数据相同则获取当前节点的 POSITION
	POSITION pos = pManageDlg->m_StudentList.Find(stu); 
	// 没找到则返回错误信息
	if (pos == NULL)
	{
		MessageBox(_T("未找到此工号对应的员工！"));
		return;
	}

	CStudent stuRet = pManageDlg->m_StudentList.GetAt(pos); // 获取 pos 指向节点的数据至 stuRet

	// 在控件中显示 strEditName
	//MessageBox(stuRet.m_strFullName, TEXT("员工信息"), MB_OK);
	m_editName.SetWindowText(stuRet.m_strFullName);
	m_editPay.SetWindowText(stuRet.m_strPay);
	m_editPosition.SetWindowText(stuRet.m_strPosition);

	UpdateData(FALSE);
	
	//OnOK();

}


void CFindDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
