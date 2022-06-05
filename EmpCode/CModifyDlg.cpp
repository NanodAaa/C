// CModifyDlg.cpp: 实现文件
//

#include "pch.h"
#include "EmployeManage.h"
#include "afxdialogex.h"
#include "CModifyDlg.h"
#include "CStudent.h"
#include "EmployeManageDlg.h"


IMPLEMENT_DYNAMIC(CModifyDlg, CDialogEx)

CModifyDlg::CModifyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MODIFY_DIALOG, pParent)
{

}

CModifyDlg::~CModifyDlg()
{
}

void CModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NUM, m_editNum);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_EDIT_PAY, m_editPay);
	DDX_Control(pDX, IDC_EDIT_POSITION, m_editPosition);
}


BEGIN_MESSAGE_MAP(CModifyDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CModifyDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CModifyDlg 消息处理程序

// “修改员工信息”对话框“修改”按钮
void CModifyDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CString strEditNum;
	CString strEditName;
	CString strEditPay;
	CString strEditPosition;

	UpdateData(TRUE);

	CEmployeManageDlg* pManageDlg = (CEmployeManageDlg*)m_pParentWnd; // 访问父窗口的数据

	// 获取控件数据
	m_editNum.GetWindowText(strEditNum);
	m_editName.GetWindowText(strEditName);
	m_editPay.GetWindowText(strEditPay);
	m_editPosition.GetWindowText(strEditPosition);

	//bool errFlag = FALSE;
	// 判断输入是否为空
	if (strEditNum.IsEmpty())
	{
		MessageBox(TEXT("未填写员工号！"));
		//errFlag = TRUE;

		return;
	}
	else if (strEditName.IsEmpty())
	{
		MessageBox(TEXT("未填写员工姓名！"));
		//errFlag = TRUE;
		return;
	}
	else if (strEditPay.IsEmpty())
	{
		MessageBox(TEXT("未填写员工工资！"));
		//errFlag = TRUE;
		return;
	}
	else if (strEditPosition.IsEmpty())
	{
		MessageBox(TEXT("未填写员工职位！"));
		//errFlag = TRUE;
		return;
	}
	/*
	if (errFlag == TRUE)
	{
		MessageBox(TEXT("添加员工信息失败！"));
	}
	else
	{
		MessageBox(TEXT("添加员工信息成功！"));
	}
	*/

	// 从 编辑框 获取数据
	m_editNum.GetWindowText(strEditNum);
	m_editName.GetWindowText(strEditName);
	m_editPay.GetWindowText(strEditPay);
	m_editPosition.GetWindowText(strEditPosition);

	// 将 编辑框 中数据暂存至 CStudent 中
	CStudent stu; // 创建新的 CStudent 对象
	stu.m_strNum = strEditNum;
	stu.m_strFullName = strEditName;
	stu.m_strPay = strEditPay;
	stu.m_strPosition = strEditPosition;

	POSITION pos = pManageDlg->m_StudentList.Find(stu); // 获取员工号相等的节点的指针
	// 没找到符合该条件的则返回错误信息
	if (pos == NULL)
	{
		MessageBox(_T("未找到此工号对应的员工！"));

		return;

	}

	pManageDlg->m_StudentList.SetAt(pos, stu); // 修改 pos 指向节点的数据

	MessageBox(_T("员工信息修改成功！"));

}
