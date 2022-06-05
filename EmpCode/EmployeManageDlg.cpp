
// EmployeManageDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "EmployeManage.h"
#include "EmployeManageDlg.h"
#include "afxdialogex.h"
#include "CAddDlg.h"
#include "CFindDlg.h"
#include "CStudent.h"
#include "CDeleteDlg.h"
#include "CModifyDlg.h"
#include "afx.h"
#include "CBrowseDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFindFindButton();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_FIND_FIND_BUTTON, &CAboutDlg::OnBnClickedFindFindButton)
END_MESSAGE_MAP()


// CEmployeManageDlg 对话框

CEmployeManageDlg::CEmployeManageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EMPLOYEMANAGE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEmployeManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEmployeManageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CEmployeManageDlg::OnBnClickedAddButton)
	ON_BN_CLICKED(IDC_FIND_BUTTON, &CEmployeManageDlg::OnBnClickedFindButton)
	ON_BN_CLICKED(IDC_DELETE_BUTTON, &CEmployeManageDlg::OnBnClickedDeleteButton)
	ON_BN_CLICKED(IDC_MODIFY_BUTTON, &CEmployeManageDlg::OnBnClickedModifyButton)
	ON_BN_CLICKED(IDC_IMPORT_BUTTON, &CEmployeManageDlg::OnBnClickedImportButton)
	ON_BN_CLICKED(IDC_EXPORT_BUTTON, &CEmployeManageDlg::OnBnClickedExportButton)
	ON_BN_CLICKED(IDC_BROWSE_BUTTON, &CEmployeManageDlg::OnBnClickedBrowseButton)
END_MESSAGE_MAP()


// CEmployeManageDlg 消息处理程序

BOOL CEmployeManageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE

}

void CEmployeManageDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();

	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}

}

// 如果向对话框添加最小化按钮，则需要下面的代码
// 来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
// 这将由框架自动完成。

void CEmployeManageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CEmployeManageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}













//******************* 以下是 跳转窗口按钮 *******************



// 主窗口 “添加”按钮
void CEmployeManageDlg::OnBnClickedAddButton()
{
	// TODO: 在此添加控件通知处理程序代码

	CAddDlg dlg;   // CEdit 类创建 dlg 对象， 用 dlg 对象调用 CEdit 类的 DoModal 方法

	// 跳转到 “添加员工” 窗口
	// 如果 “添加员工” 窗口返回值为 IDOK 则进入 if 语句
	if (IDOK == dlg.DoModal())
	{
		CStudent student;

		UpdateData(TRUE); // 更新控件数据
	
		student.m_strFullName = dlg.m_strName;		//从 AddDlg 类里面把成员变量取出来
		student.m_strNum = dlg.m_strNum;
		student.m_strPay = dlg.m_strPay;
		student.m_strPosition = dlg.m_strPosition;
		
		m_StudentList.AddTail(student);			//添加到链表，链表在 ManageDlg 里面定义
	
		UpdateData(FALSE);

		return;

	}

}

// 主窗口 “查找”按钮
void CEmployeManageDlg::OnBnClickedFindButton()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CFindDlg dlg(this);	// 把 ManageDlg 的指针传进去
	// 跳转到 “查找员工” 窗口
	if (IDOK == dlg.DoModal())
	{
		return;

	}

}

// 主窗口“删除”按钮
void CEmployeManageDlg::OnBnClickedDeleteButton()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CDeleteDlg dlg(this);
	// 跳转到 “删除员工” 窗口
	if (IDOK == dlg.DoModal()) 
	{
		return;

	}

}

// 主窗口“修改”按钮
void CEmployeManageDlg::OnBnClickedModifyButton()
{
	// TODO: 在此添加控件通知处理程序代码

	CModifyDlg dlg(this);
	// 跳转到 “修改员工信息” 窗口
	if (IDOK == dlg.DoModal())
	{
		return;

	}

}

//******************* 以下是导入导出 *******************

// 主窗口“导入”按钮 （测试版本，不要用）
void CEmployeManageDlg::OnBnClickedImportButton()
{
	// TODO: 在此添加控件通知处理程序代码

	CStdioFile CStudentList;
	CStudent stu; // 储存

	// 确认是否要导入
	if (IDOK == MessageBox(_T("是否要导入数据？"), _T("警告！"), MB_OKCANCEL | MB_ICONWARNING))
	{
		
		// 暂存读取出的数据
		CString strNum;
		CString strFullName;
		CString strPay;
		CString strPosition;

		// 打开文件
		CStudentList.Open(_T("StudentList.txt"), CFile::modeReadWrite);

		// 清空链表
		m_StudentList.RemoveAll();	
		
		// 读取文件并将数据储存到 stu 中
		// 一次读一行文件
		int lineCount = 0;
		CString re;
		fseek(CStudentList.m_pStream, sizeof(0xfeff), SEEK_SET);
		while (!feof(CStudentList.m_pStream))
		{
			CStudentList.ReadString(strNum);
			CStudentList.ReadString(strFullName);
			CStudentList.ReadString(strPay);
			CStudentList.ReadString(strPosition);

			// 将暂存数据储存到 stu 类中
			stu.m_strNum = strNum;
			stu.m_strFullName = strFullName;
			stu.m_strPay = strPay;
			stu.m_strPosition = strPosition;

			// 将数据添加到链表尾
			m_StudentList.AddTail(stu);

		}

	}

	CStudentList.Close(); // 关闭文件
	MessageBox(_T("数据导入成功！"));

}




// 主窗口“导出”按钮
void CEmployeManageDlg::OnBnClickedExportButton()
{
	// TODO: 在此添加控件通知处理程序代码

	// 创建或打开信息存储文件
	CFile CStudentList;
	
	if (IDOK == MessageBox(_T("是否要导出数据？"), _T("警告!"), MB_OKCANCEL | MB_ICONWARNING))
	{
		
		// 打开名为“StudentList”的文件
		CStudentList.Open(_T("StudentList.txt"), CFile::modeReadWrite | CFile::modeCreate);
		
		
		// 文件开头写入编码
		WORD flag = 0xfeff;
		CStudentList.Write(&flag, 2);

		/*
		stu.m_strFullName = _T("asd");
		stu.m_strNum = _T("asd");
		stu.m_strPay = _T("asd");
		stu.m_strPosition = _T("asd");

		CStudentList.Write(stu.m_strFullName, sizeof(stu.m_strFullName));
		*/

		CStudent stu;
		POSITION pos = m_StudentList.GetHeadPosition(); // 获得头结点的地址

		/*
		CString strFullName;
		CString strNum;
		CString strPay;
		CString strPosition;
		*/
		
		CString lineFeeds = L"\r\n";
		int listCount = m_StudentList.GetCount(); // 获取链表节点数
		for (int i = 0; i < listCount; i++)
		{
			// 获取 i == 0 开始位置的元素
			stu = m_StudentList.GetAt(m_StudentList.FindIndex(i));
			
			/*
			strFullName = stu.m_strFullName;
			strNum = stu.m_strNum;
			strPay = stu.m_strPay;
			strPosition = stu.m_strPosition;
			*/

			CStudentList.Write((LPCTSTR)stu.m_strNum.GetBuffer(stu.m_strNum.GetLength()), stu.m_strNum.GetLength() * sizeof(TCHAR));
			CStudentList.Write(lineFeeds, lineFeeds.GetLength());
			CStudentList.Write((LPCTSTR)stu.m_strFullName.GetBuffer(stu.m_strFullName.GetLength()), stu.m_strFullName.GetLength() * sizeof(TCHAR));
			CStudentList.Write(lineFeeds, lineFeeds.GetLength());
			CStudentList.Write((LPCTSTR)stu.m_strPay.GetBuffer(stu.m_strPay.GetLength()), stu.m_strPay.GetLength() * sizeof(TCHAR));
			CStudentList.Write(lineFeeds, lineFeeds.GetLength());
			CStudentList.Write((LPCTSTR)stu.m_strPosition.GetBuffer(stu.m_strPosition.GetLength()), stu.m_strPosition.GetLength() * sizeof(TCHAR));

			/*
			// 链表数据写入到文件
			CStudentList.Write(stu.m_strNum, sizeof(stu.m_strNum));
			CStudentList.Write(stu.m_strFullName, sizeof(stu.m_strFullName));
			CStudentList.Write(stu.m_strPay, sizeof(stu.m_strPay));
			CStudentList.Write(stu.m_strPosition, sizeof(stu.m_strPosition));
			*/

			// 换行
			CStudentList.Write(lineFeeds, lineFeeds.GetLength());			
			
		}
		
		CStudentList.Close(); // 关闭文件

		MessageBox(_T("数据导出成功！"));

	}

}

void CAboutDlg::OnBnClickedFindFindButton()
{
	// TODO: 在此添加控件通知处理程序代码
}



// 主窗口“浏览”按钮
void CEmployeManageDlg::OnBnClickedBrowseButton()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CBrowseDlg dlg(this);
	if (IDOK == dlg.DoModal())
	{
		return;
	}
	

}
