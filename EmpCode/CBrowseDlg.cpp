// CBrowseDlg.cpp: 实现文件
//

#include "pch.h"
#include "EmployeManage.h"
#include "afxdialogex.h"
#include "CBrowseDlg.h"
#include "EmployeManageDlg.h"
#include "CStudent.h"

// CBrowseDlg 对话框

IMPLEMENT_DYNAMIC(CBrowseDlg, CDialogEx)

CBrowseDlg::CBrowseDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BROWSE_DIALOG, pParent)
{

}

CBrowseDlg::~CBrowseDlg()
{
}

void CBrowseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BROWSE_LIST, m_browseList);
}


BEGIN_MESSAGE_MAP(CBrowseDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_BROWSE_LIST, &CBrowseDlg::OnLvnItemchangedBrowseList)
	ON_BN_CLICKED(IDOK, &CBrowseDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_REFRESH_BUTTON, &CBrowseDlg::OnBnClickedRefreshButton)
END_MESSAGE_MAP()


// CBrowseDlg 消息处理程序


void CBrowseDlg::OnLvnItemchangedBrowseList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	

}

void CBrowseDlg::OnBnClickedRefreshButton()
{
	// TODO: 在此添加控件通知处理程序代码

	CEmployeManageDlg* pManageDlg = (CEmployeManageDlg*)m_pParentWnd; // 访问父窗口的数据
	CRect rect;
	
	// 获取编程语言列表视图控件的位置和大小 
	m_browseList.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_browseList.SetExtendedStyle(m_browseList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加四列   
	m_browseList.InsertColumn(0, _T("工号"), LVCFMT_CENTER, rect.Width() / 4, 0);
	m_browseList.InsertColumn(1, _T("姓名"), LVCFMT_CENTER, rect.Width() / 4, 1);
	m_browseList.InsertColumn(2, _T("工资"), LVCFMT_CENTER, rect.Width() / 4, 2);
	m_browseList.InsertColumn(2, _T("职位"), LVCFMT_CENTER, rect.Width() / 4, 3);

	// 在列表视图控件中插入列表项，并设置列表子项文本 
	
	//POSITION pos = pManageDlg->m_StudentList.GetHeadPosition(); //获取头结点地址
	
	CStudent stu;
	

	// 想表格中写入学生信息
	for (int line = 0; line < pManageDlg->m_StudentList.GetCount(); line++)
	{
		int column = 1;
		
		// 将链表信息储存到类中
		stu = pManageDlg->m_StudentList.GetAt(pManageDlg->m_StudentList.FindIndex(line));

		m_browseList.InsertItem(line, stu.m_strFullName);

		while (column != 4)
		{
			m_browseList.SetItemText(line, column, stu.m_strNum);
			column++;
			m_browseList.SetItemText(line, column, stu.m_strPay);
			column++;
			m_browseList.SetItemText(line, column, stu.m_strPosition);
			column++;
		}
			
	}

}


void CBrowseDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CDialogEx::OnOK();
}


