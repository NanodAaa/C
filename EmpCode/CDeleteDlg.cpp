// CDeleteDlg.cpp: 实现文件
//

#include "pch.h"
#include "EmployeManage.h"
#include "afxdialogex.h"
#include "CDeleteDlg.h"
#include "EmployeManageDlg.h"
#include "CStudent.h"


// CDeleteDlg 对话框

IMPLEMENT_DYNAMIC(CDeleteDlg, CDialogEx)

CDeleteDlg::CDeleteDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DELETE_DIALOG, pParent)
{

}

CDeleteDlg::~CDeleteDlg()
{
}

void CDeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_DELETE, m_editNum);
}


BEGIN_MESSAGE_MAP(CDeleteDlg, CDialogEx)
	ON_BN_CLICKED(IDC_DELETE_DELALL_BUTTON, &CDeleteDlg::OnBnClickedDeleteDelallButton)
	ON_BN_CLICKED(ID_DELETE_DEL_BUTTON, &CDeleteDlg::OnBnClickedDeleteDelButton)
END_MESSAGE_MAP()




// CDeleteDlg 消息处理程序

// “删除员工”对话框“删除”按钮
void CDeleteDlg::OnBnClickedDeleteDelButton()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString choose;

	UpdateData(TRUE);

	CEmployeManageDlg* pManageDlg = (CEmployeManageDlg*)m_pParentWnd; // 访问父窗口的数据

	CString strEditNum;
	m_editNum.GetWindowText(strEditNum); // 获取 编辑框 中的数据

	// 判断输入是否为空
	if (strEditNum.IsEmpty())
	{
		MessageBox(_T("未输入员工工号！"));
		return;
	}

	// 判断是否要删除
	if (IDCANCEL == MessageBox(_T("确认要删除此员工的信息吗？"), _T("警告!"), MB_OKCANCEL | MB_ICONWARNING))
	{
		return; // 取消删除返回 主页面
	}

	CStudent stu;
	stu.m_strNum = strEditNum;

	POSITION pos = pManageDlg->m_StudentList.Find(stu); // 查询与输入工号相同的员工
	// 没找到则返回错误信息
	if (pos == NULL)
	{
		MessageBox(_T("未找到此工号对应的员工！"));
		return;
	}

	pManageDlg->m_StudentList.RemoveAt(pos); // 删除指定位置的节点

	MessageBox(_T("该员工数据已删除"));

}


// “删除员工”对话框“删除所有”按钮
void CDeleteDlg::OnBnClickedDeleteDelallButton()
{
	// TODO: 在此添加控件通知处理程序代码

	CEmployeManageDlg* pManageDlg = (CEmployeManageDlg*)m_pParentWnd; // 访问父窗口的数据
	
	//CString choose;
	if (IDOK == MessageBox(_T("确认要删除所有的员工信息吗？"), _T("警告!"), MB_OKCANCEL | MB_ICONWARNING))
	{
		pManageDlg->m_StudentList.RemoveAll(); // 删除所有员工信息
		MessageBox(_T("所有员工信息已成功删除！"));
		return;
	}
	else
	{
		return;
	}

}

