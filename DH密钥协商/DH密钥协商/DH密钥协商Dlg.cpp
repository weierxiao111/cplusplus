
// DH密钥协商Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DH密钥协商.h"
#include "DH密钥协商Dlg.h"
#include "afxdialogex.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

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


// CDH密钥协商Dlg 对话框



CDH密钥协商Dlg::CDH密钥协商Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DH_DIALOG, pParent)
	, _p1(0)
	, _p2(0)
	, _n(0)
	, _pkey(0)
	, _pkey2(0)
	, _ekey(0)
	, _ekey2(0)
	, _k(0)
	, _k2(0)
	, _p3(0)
	, _randx(0)
	, _randy(0)
	, _ka(0)
	, _kb(0)
	, _c(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDH密钥协商Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, _p1);
	DDX_Text(pDX, IDC_EDIT2, _p2);
	DDX_Text(pDX, IDC_EDIT3, _n);
	DDX_Text(pDX, IDC_EDIT4, _pkey);
	DDX_Text(pDX, IDC_EDIT5, _pkey2);
	DDX_Text(pDX, IDC_EDIT6, _ekey);
	DDX_Text(pDX, IDC_EDIT7, _ekey2);
	DDX_Text(pDX, IDC_EDIT8, _k);
	DDX_Text(pDX, IDC_EDIT10, _k2);
	DDX_Text(pDX, IDC_EDIT11, _p3);
	DDX_Text(pDX, IDC_EDIT12, _randx);
	DDX_Text(pDX, IDC_EDIT13, _randy);
	DDX_Text(pDX, IDC_EDIT14, _ka);
	DDX_Text(pDX, IDC_EDIT15, _kb);
	DDX_Text(pDX, IDC_EDIT9, _c);
}

BEGIN_MESSAGE_MAP(CDH密钥协商Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CDH密钥协商Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CDH密钥协商Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON7, &CDH密钥协商Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CDH密钥协商Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON3, &CDH密钥协商Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDH密钥协商Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDH密钥协商Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CDH密钥协商Dlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CDH密钥协商Dlg 消息处理程序

BOOL CDH密钥协商Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

void CDH密钥协商Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDH密钥协商Dlg::OnPaint()
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

size_long  repeatMod(size_long base, size_long n, size_long mod);
bool rabinmiller(size_long n, size_long k);
size_long extendGcd(size_long a, size_long b, size_long &x, size_long &y)
{
	if (a == 0 && b == 0)
	{
		return 0;  //  无最大公约数
	}
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	size_long d = extendGcd(b, a%b, y, x);
	y -= a / b * x;
	return d;
}

//  求逆元 ax = 1(mod n)
size_long inv(size_long a, size_long n)
{
	size_long x, y;
	size_long d = extendGcd(a, n, x, y);
	if (d == 1)
	{
		return (x % n + n) % n;
	}
	else
	{
		return 0;  //  无逆元
	}
}

//求最大公约数
size_long gcd(size_long num1, size_long num2)
{

	assert(num1 && num2);

	if (num2 > num1)
		std::swap(num1, num2);
	size_long ret = 0;
	while (ret = num1%num2)
	{
		num1 = num2;
		num2 = ret;
	}
	return num2;
}


// 生成伪素数
const int MAX_ROW = 50;

size_long Pseudoprime()
{
	bool ifprime = false;
	size_t a = 0;
	int arr[MAX_ROW];   //数组arr为{3，4，5，6...52}
	for (int i = 0; i<MAX_ROW; ++i)
	{
		arr[i] = i + 3;
	}

	do {

		while (!ifprime)
		{
			ifprime = true;
			a = (rand() % 1000) * 2 + 3; //生成一个范围在3到2003里的奇数
			for (int j = 0; j<MAX_ROW; ++j)
			{
				if (a%arr[j] == 0)
				{
					ifprime = false;
					break;
				}
			}
		}

	} while (!rabinmiller(a, 10));

	return a;
}

//模重复平方算法求(b^n)%m
size_long  repeatMod(size_long base, size_long n, size_long mod)
{
	size_long a = 1;
	while (n)
	{
		if (n & 1)
		{
			a = (a*base) % mod;
		}
		base = (base*base) % mod;
		n = n >> 1;
	}
	return a;
}

//Miller-Rabin素数检测
bool rabinmiller(size_long n, size_long k)
{

	int s = 0;
	int temp = n - 1;
	while ((temp & 0x1) == 0 && temp)
	{
		temp = temp >> 1;
		s++;
	}   //将n-1表示为(2^s)*t
	size_long t = temp;

	while (k--)  //判断k轮误判概率不大于(1/4)^k
	{
		size_long b = rand() % (n - 2) + 2; //生成一个b(2≤a ≤n-2)

		size_long y = repeatMod(b, t, n);
		if (y == 1 || y == (n - 1))
			return true;
		for (int j = 1; j <= (s - 1) && y != (n - 1); ++j)
		{
			y = repeatMod(y, 2, n);
			if (y == 1)
				return false;
		}
		if (y != (n - 1))
			return false;
	}
	return true;
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDH密钥协商Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDH密钥协商Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	srand((unsigned)time(0));
	_p1 = Pseudoprime();
	_p2 = Pseudoprime();
	_n = _p1*_p2;
	UpdateData(false);
}


void CDH密钥协商Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	srand((unsigned)time(0));

	size_long r = (_p1 - 1)*(_p2 - 1);
	do {
		_pkey = rand() % 1000;
	} while (gcd(_pkey, r) != 1 || _pkey>r);

	_ekey = inv(_pkey, r);

	do {
		_pkey2 = rand() % 1000;
	} while (gcd(_pkey2, r) != 1 || _pkey2>r || _pkey == _pkey2);

	_ekey2 = inv(_pkey2, r);

	UpdateData(false);
}


void CDH密钥协商Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	srand((unsigned)time(0));

	_k = rand() % 10000;
	UpdateData(false);

}


void CDH密钥协商Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	srand((unsigned)time(0));

	_p3 = Pseudoprime();

	size_long _a = 5;
	_randx = rand() % 99 *2+ 1;
	_randy = rand() % 99 *2+ 1;


	size_t ya = repeatMod(_a, _randx, _p3);
	size_t yb = repeatMod(_a, _randy, _p3);

	_ka = repeatMod(yb, _randx, _p3);
	_kb = repeatMod(ya, _randy, _p3);
	UpdateData(false);

}


void CDH密钥协商Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	_p1 = 0;
	_p2 = 0;
	 _n = 0;
	 _pkey = 0;
	 _pkey2 = 0;
	 _ekey = 0;
	_ekey2 = 0;
	_k = 0;
	_k2 = 0;
		_p3 = 0;
	 _randx = 0;
	 _randy = 0;
	 _ka = 0;
	 _kb = 0;
	 _c = "";
	 UpdateData(false);

}


void CDH密钥协商Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);

	size_long temp = _pkey;
	int num = 0;
	int i = 0;
	char str[64];
	memset(str, 0, 64 * sizeof(char));
	while (temp)
	{
		num = temp % 10;
		str[i++] = 'a' + num;
		temp = temp / 10;
	}
	temp = _k;
	while (temp)
	{
		num = temp % 10;
		str[i++] = 'a' + num;
		temp = temp / 10;
	}
	_c.Format("%s", str);
	UpdateData(false);
}


void CDH密钥协商Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	_k2 = _k;
	UpdateData(false);
}


void CDH密钥协商Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(1);
}
