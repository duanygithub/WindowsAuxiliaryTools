
// 随机字符生成器Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "随机字符生成器.h"
#include "随机字符生成器Dlg.h"
#include "afxdialogex.h"
#include <Windows.h>
#include <random>
#include <time.h>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
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
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C随机字符生成器Dlg 对话框



C随机字符生成器Dlg::C随机字符生成器Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C随机字符生成器Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, Result);
}

BEGIN_MESSAGE_MAP(C随机字符生成器Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &C随机字符生成器Dlg::OnSelchangeCombo1)
	ON_BN_CLICKED(IDOK, &C随机字符生成器Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK1, &C随机字符生成器Dlg::OnClickedCheck1)
	ON_EN_CHANGE(IDC_EDIT2, &C随机字符生成器Dlg::OnChangeEdit2)
END_MESSAGE_MAP()


// C随机字符生成器Dlg 消息处理程序

BOOL C随机字符生成器Dlg::OnInitDialog()
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
	SetWindowText(L"随机字符生成器");
	GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE);
	((CComboBox*)GetDlgItem(IDC_COMBO2))->EnableWindow(FALSE);
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(TEXT("全是字母"));
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(TEXT("全是数字"));
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(TEXT("默认"));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(TEXT("默认"));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(TEXT("全部大写"));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(TEXT("全部小写"));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C随机字符生成器Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C随机字符生成器Dlg::OnPaint()
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
HCURSOR C随机字符生成器Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C随机字符生成器Dlg::OnSelchangeCombo1()
{
	switch (((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel())
	{
	case 0:
	case 1:((CComboBox*)GetDlgItem(IDC_COMBO2))->EnableWindow(FALSE); ((CComboBox*)GetDlgItem(IDC_COMBO2))->SetWindowTextW(L""); break;
	case 2:((CComboBox*)GetDlgItem(IDC_COMBO2))->EnableWindow(TRUE); break;
	}
}

#define RANDSTRING_NUMBER_ONLY 1
#define RANDSTRING_LETTER_ONLY 2
#define RANDSTRING_DEFAULT 3
#define RANDSTRING_BIGLETTER 4
#define RANDSTRING_SMALLLETTER 5
#define RANDSTRING_ONE_SMALL_LETTER 6
#define RANDSTRING_ONE_BIG_LETTER 7

CString RandString(DWORD dwFlag, DWORD n)
{
	srand(time(NULL));
	CString result, tmp;
	if (dwFlag == RANDSTRING_NUMBER_ONLY)
	{
		for (int i = 0; i < n; i++)
		{
			tmp.Format(TEXT("%d"), rand() % 10);
			result += tmp;
		}
	}
	else if (dwFlag == RANDSTRING_BIGLETTER)
	{
		for (int i = 0; i < n; i++)
		{
			tmp.Format(TEXT("%c"), rand() % 26 + 'A');
			result += tmp;
		}
	}
	else if (dwFlag == RANDSTRING_SMALLLETTER)
	{
		for (int i = 0; i < n; i++)
		{
			tmp.Format(TEXT("%c"), rand() % 26 + 'a');
			result += tmp;
		}
	}
	else if (dwFlag == RANDSTRING_LETTER_ONLY)
	{
		for (int i = 0; i < n; i++)
		{
			DWORD dwRandResult = rand() % 2;
			if (dwRandResult)
			{
				tmp.Format(TEXT("%c"), rand() % 26 + 'a');
				result += tmp;
			}
			else
			{
				tmp.Format(TEXT("%c"), rand() % 26 + 'A');
				result += tmp;
			}
		}
	}
	return result;
}

CString randstr(const int len)
{
	srand(time(NULL));
	CString result, tmp;
	int i;
	for (i = 0; i < len; ++i)
	{
		switch ((rand() % 3))
		{
		case 1:
			tmp.Format(TEXT("%c"), 'A' + rand() % 26);
			break;
		case 2:
			tmp.Format(TEXT("%c"), 'a' + rand() % 26);
			break;
		default:
			tmp.Format(TEXT("%c"), '0' + rand() % 10);
			break;
		}
		result += tmp;
	}
	return result;
}

void C随机字符生成器Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	DWORD dwCur1 = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	DWORD dwCur2 = ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetCurSel();
	DWORD dwNum = GetDlgItemInt(IDC_EDIT2);
	CString res;
	if (!((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
	{
		if (dwCur1 == 2)
		{
			switch (dwCur2)
			{
			case 0:res = RandString(RANDSTRING_LETTER_ONLY, dwNum); break;
			case 1:res = RandString(RANDSTRING_BIGLETTER, dwNum); break;
			case 2:res = RandString(RANDSTRING_SMALLLETTER, dwNum); break;
			}
		}
		else if (dwCur1 == 0)
		{
			res = randstr(dwNum);
		}
		else if (dwCur1 == 1)
		{
			res = RandString(RANDSTRING_NUMBER_ONLY, dwNum);
		}
	}
	else
	{
		DWORD n = GetDlgItemInt(IDC_EDIT5), m = GetDlgItemInt(IDC_EDIT4);
		CString str;
		GetDlgItemText(IDC_EDIT3, str);
		for (int i = 0; i < n; i++)
		{
			if (dwCur1 == 2)
			{
				switch (dwCur2)
				{
				case 0:res += RandString(RANDSTRING_LETTER_ONLY, m); break;
				case 1:res += RandString(RANDSTRING_BIGLETTER, m); break;
				case 2:res += RandString(RANDSTRING_SMALLLETTER, m); break;
				}
			}
			else if (dwCur1 == 0)
			{
				res += randstr(m);
			}
			else if (dwCur1 == 1)
			{
				res += RandString(RANDSTRING_NUMBER_ONLY, m);
			}
			res += str;
			Sleep(1000);
		}
	}
	
	res += "\r\n";
	SetDlgItemTextW(IDC_EDIT1, res);
}

void C随机字符生成器Dlg::OnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
	{
		SetDlgItemTextW(IDC_EDIT2, TEXT(""));
		GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
	}
	else
	{
		GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE);
	}
}


void C随机字符生成器Dlg::OnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString text;
	GetDlgItemText(IDC_EDIT2, text);
	if (text != "")((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(FALSE);
}
