// 和太阳肩并肩的计算器Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "和太阳肩并肩的计算器.h"
#include "和太阳肩并肩的计算器Dlg.h"
#include<assert.h>
#include<string.h>
#include<math.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define N 26 

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// C和太阳肩并肩的计算器Dlg 对话框




C和太阳肩并肩的计算器Dlg::C和太阳肩并肩的计算器Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(C和太阳肩并肩的计算器Dlg::IDD, pParent)
	, str_a(_T(""))
	, str_b(_T(""))
	, n(0)
	, res(_T(""))
	, str(_T(""))
	, flag(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C和太阳肩并肩的计算器Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, str_a);
	DDX_Text(pDX, IDC_EDIT2, str_b);
	DDX_Text(pDX, IDC_EDIT3, n);
	DDX_Text(pDX, IDC_EDIT4, res);
	DDX_Text(pDX, IDC_EDIT6, str);
}

BEGIN_MESSAGE_MAP(C和太阳肩并肩的计算器Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &C和太阳肩并肩的计算器Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C和太阳肩并肩的计算器Dlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT3, &C和太阳肩并肩的计算器Dlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON5, &C和太阳肩并肩的计算器Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON3, &C和太阳肩并肩的计算器Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON7, &C和太阳肩并肩的计算器Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON9, &C和太阳肩并肩的计算器Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON8, &C和太阳肩并肩的计算器Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON10, &C和太阳肩并肩的计算器Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &C和太阳肩并肩的计算器Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON4, &C和太阳肩并肩的计算器Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON12, &C和太阳肩并肩的计算器Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &C和太阳肩并肩的计算器Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &C和太阳肩并肩的计算器Dlg::OnBnClickedButton14)
END_MESSAGE_MAP()


// C和太阳肩并肩的计算器Dlg 消息处理程序

BOOL C和太阳肩并肩的计算器Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C和太阳肩并肩的计算器Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C和太阳肩并肩的计算器Dlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C和太阳肩并肩的计算器Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void encode(char *arr,int key)
{

	for(int i=0;arr[i]!='\0';i++)
	{
		if('A'<=arr[i]&&arr[i]<='Z')
		{
			int temp=arr[i]-'A';
			temp=(temp+key)%26;
			arr[i]=temp+'A';
		}
		if('a'<=arr[i]&&arr[i]<='z')
		{
			int temp=arr[i]-'a';
			temp=(temp+key)%26;
			arr[i]=temp+'a';
		}
	}
}
void decode(char *arr,int key)
{

	assert(arr!=NULL);
	for(int i=0;arr[i]!='\0';i++)
	{
		if('A'<=arr[i]&&arr[i]<='Z')
		{
			int temp=arr[i]-'A';
			temp=(temp-key)%26;
			if(temp<0)
			{
				temp+=26;
			}
			arr[i]=temp+'A';
		}
		if('a'<=arr[i]&&arr[i]<='z')
		{
			int temp=arr[i]-'a';
			temp=(temp-key)%26;
			if(temp<0)
			{
				temp+=26;
			}
			arr[i]=temp+'a';
		}
	}
}
//凯撒加密
void C和太阳肩并肩的计算器Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	char *str1=(LPSTR)(LPCTSTR)str;
	char *temp=(char*)malloc(strlen(str1)+1);
	strcpy(temp,str1);
	encode(str1,n);
	res=str;
	str=temp;
	UpdateData(false);
}
//凯撒解密
void C和太阳肩并肩的计算器Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	char *str1=(LPSTR)(LPCTSTR)str;
	char *temp=(char*)malloc(strlen(str1)+1);
	strcpy(temp,str1);
	decode(str1,n);
	res=str;
	str=temp;
	UpdateData(false);
}

void C和太阳肩并肩的计算器Dlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
//大数乘法
void C和太阳肩并肩的计算器Dlg::OnBnClickedButton5()
{
	 //TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	int c[100]={0};
	char c1[100]={0};
	int len1=str_a.GetLength();
	int len2 = str_b.GetLength();
	int len3=len1+len2;
	char *str_1=(LPSTR)(LPCTSTR)str_a;
	char *str_2=(LPSTR)(LPCTSTR)str_b;
	/*strrev(str_1);
	strrev(str_2);*/
	for(int i=0;i<len1;i++)
	{
		for(int j=0;j<len2;j++)
		{
			c[i+j+1]=c[i+j+1]+(str_1[i]-'0')*(str_2[j]-'0');
		}
	}
	for(int i=len1+len2;i>0;--i)
	{
		if(c[i]>=10)
		{
			c[i-1]=c[i-1]+c[i]/10;
			c[i]=c[i]%10;
		}
	}
	for(int i=0;i<len1+len2;i++)
	{
		c1[i]=c[i]+'0';
	}
	CString s;
	res = CA2CT(c1);
	
	UpdateData(false);
}
//大数加法
void C和太阳肩并肩的计算器Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
UpdateData(true); 
	long int len1, len2;
	long int i, j, k;
	int a[100];
	int b[100];
	int up, l;
	char e[100] = { '\0' };
	/*初始化各量*/
	len1 = str_a.GetLength();
	len2 = str_b.GetLength();
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));

	/*注意，必须倒着保存数据*/
	for (i = len1 - 1, k = 0; i != -1; --i)
	{
		a[k] = str_a[i] - '0';
		k++;
	}
	for (j = len2 - 1, k = 0; j != -1; --j)
	{
		b[k] = str_b[j] - '0';
		k++;
	}
	for (i = 0, up = 0; i <100; ++i)
	{
		a[i] = a[i] + b[i] + up;
		up = a[i] / 10;
		a[i] %= 10;
	}
	for (i = 100 - 1; i != -1; --i)
	{
		if (a[i])
		{
			break;
		}
	}
	for (k = i, l = 0; k != -1; --k, l++)
	{
		e[l] = a[k] + 48;
	}
	res=CA2CT(e);

	UpdateData(false); 
}
//s盒
void C和太阳肩并肩的计算器Dlg::OnBnClickedButton7()
{
	int vec6[4][16] = {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13};
	char s[10] = {0} ;
	char s6[5] = {'0','0','0','0','\0'};
	int rest[2] = {0};
	int n = 0;
	int m = 0;
	int i = 3;
	UpdateData(true);
	memcpy(s,str,str.GetLength()+1);
	rest[0] = (s[0] - '0')*pow(2.0,1)+(s[5] - '0')*pow(2.0,0);
	rest[1] = (s[1] - '0')*pow(2.0,3)+(s[2] - '0')*pow(2.0,2)+(s[3] - '0')*pow(2.0,1)+(s[4] - '0')*pow(2.0,0);
	n = vec6[rest[0]][rest[1]];
	while(n != 0)
	{
		m = n%2;
		n = n/2;
		s6[i--] += m;
	}
	CString str(s6);
	res = str;
	UpdateData(false);
	
}

//退出
void C和太阳肩并肩的计算器Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}
//清空
void C和太阳肩并肩的计算器Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	res="";
}

//加密算法  
char *encode(char *c_str, int a, int b, int n);
//解密算法  
char *decode(char *m_str, int a, int b, int n);

//设置数组coprime为存放与n互素的元素  
void setCoprime(int coprime[], int n);
//获取value1,value2的最大公约数  
int getGcd(int value1, int value2);
//在coprime中寻找a的模n可逆元_a  
int get_a(int coprime[], int a, int n);
char *f_encode(char *c_str, int a, int b, int n)
{
	char *p_str = c_str; //减小副作用  
	assert(c_str);  //判断明文字符串c_str是否为NULL  

	while (*c_str)
	{
		if (' ' == *c_str)  //遇到空格就跳过  
		{
			++c_str;
			continue;
		}

		if ((*c_str >='A')&&(*c_str<='Z')) 
		{
			*c_str -= 'A';  //将字符转化为对应数字  
			*c_str = (a*(*c_str) + b) % n;//加密核心算法  
			*c_str += 'A';  //将数字转化为字符  
		}
		if ((*c_str >='a')&&(*c_str <='z')) 
		{
			*c_str -= 'a';  //将字符转化为对应数字  
			*c_str = (a*(*c_str) + b) % n;//加密核心算法  
			*c_str += 'a';  //将数字转化为字符  
		}
		++c_str;
	}

	return p_str;
}
int get_a(int coprime[], int a, int n)
{
	int i = 0;

	for (; coprime[i] != 0; i++)
	if (1 == (a*coprime[i]) % n)
		return coprime[i];

	return 0;
}
int getGcd(int value1, int value2)
{
	int gcd = 0; //最大公约数  
	int divisor = 0; //余数  

	do  //辗转相除法  
	{
		divisor = value1 % value2;

		gcd = value2;

		value1 = value2;
		value2 = divisor;

	} while (divisor);

	return gcd;
}
void setCoprime(int coprime[], int n)
{
	int i = 1;

	for (; i < n; i++)
	if (1 == getGcd(n, i))//判断是否n,i是否互素  
		*(coprime++) = i; //将i存入coprime中  
}
char *f_decode(char *m_str, int a, int b, int n)
{
	char *p_str = m_str; //减小副作用  
	int coprime[32] = { 0 }; //存放小于n并且与n互素的元素  
	int _a = 0; //存放a的模n可逆元  
	int i = 0; //迭代因子  

	assert(m_str);  //判断密文字符串m_str是否为NULL  

	for (; i < 32; i++)  //将数组元素赋为0  
		coprime[i] = 0;

	setCoprime(coprime, n);//设置数组coprime存放与n互素的元素  

	_a = get_a(coprime, a, n);//在coprime中寻找a的逆元_a  


	while (*m_str)
	{
		if (' ' == *m_str)  //遇到空格就跳过  
		{
			++m_str;
			continue;
		}

		if ((*m_str >='A') &&(*m_str <='Z'))
		{
			*m_str -= 'A';  //将字符转化为对应数字  
			*m_str = (_a*(*m_str - b + n)) % n;//解密核心算法  
			*m_str += 'A';  //将数字转化为字符  
		}
		if ((*m_str >='a') &&(*m_str <='z'))
		{
			*m_str -= 'a';  //将字符转化为对应数字  
			*m_str = (_a*(*m_str - b + n)) % n;//解密核心算法  
			*m_str += 'a';  //将数字转化为字符  
		}
		++m_str;
	}
	return p_str;
}
//仿射加密
void C和太阳肩并肩的计算器Dlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	int a=_ttoi(str_a);
	int b=_ttoi(str_b);
	char *str_f=(LPSTR)(LPCTSTR)str;
	char *temp=(char*)malloc(strlen(str_f)+1);
	strcpy(temp,str_f);
	f_encode(str_f, a, b, N);
	res=str_f;
	str=temp;
	UpdateData(false);


}
//仿射解密
void C和太阳肩并肩的计算器Dlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	int a=_ttoi(str_a);
	int b=_ttoi(str_b);
	char *str_f=(LPSTR)(LPCTSTR)str;
	char *temp=(char*)malloc(strlen(str_f)+1);
	strcpy(temp,str_f);
	f_decode(str_f, a, b, N);
	res=str_f;
	str=temp;
	UpdateData(false);
}
//大数比较大小
int compare(char *str_a, char *str_b)
{
	int len_a, len_b;
	len_a = strlen(str_a);          //分别获取大数的位数进行比较
	len_b = strlen(str_b);

	if (strcmp(str_a, str_b) == 0)    //返回比较结果
		return 0;
	if (len_a > len_b)
		return 1;
	else if (len_a == len_b)
		return strcmp(str_a, str_b);
	else
		return -1;
}
//大数相减
void C和太阳肩并肩的计算器Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true); 
	int f, n;
	int i, k, len_a, len_b;
	int num_a[1000] = { 0 };          //初始化大数数组，各位全清0
	int num_b[1000] = { 0 };
	int num_c[1000];
	char *str_1=(LPSTR)(LPCTSTR)str_a;
	char *str_2=(LPSTR)(LPCTSTR)str_b;
	len_a = str_a.GetLength();         //分别获得两个大数的位数
	len_b = str_b.GetLength();
	k = len_a > len_b ? len_a : len_b;                    //获得最大的位数
	num_c[0] = 0;
	f = 0;
	n = compare(str_1, str_2);

	for (i = 0; i<len_a; i++)                   //颠倒存储
		num_a[i] = str_a[len_a - i - 1] - '0';
	for (i = 0; i<len_b; i++)
		num_b[i] = str_b[len_b - i - 1] - '0';

	for (i = 0; i<k; i++)         //逐位进行减法
	{
		if (n >= 0)
		{
			if (num_a[i] >= num_b[i])
				num_c[i] = num_a[i] - num_b[i];
			else
			{
				num_c[i] = num_a[i] - num_b[i] + 10;
				num_a[i + 1]--;
			}
		}
		else
		{
			if (num_b[i] >= num_a[i])
				num_c[i] = num_b[i] - num_a[i];
			else
			{
				num_c[i] = num_b[i] - num_a[i] + 10;
				num_b[i + 1]--;
			}
		}

	}
	char resa[1000]={0};
	for(int j=k-1;j>=0;j--)
	{
		resa[k-j-1]=num_c[j]+'0';
	}
	res=resa;
	UpdateData(false);
}


//大数左移
void C和太阳肩并肩的计算器Dlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	int c[100]={0};
	char c1[100]={0};
	str_b="2";
	int len1=str_a.GetLength();
	int len2 = str_b.GetLength();
	int len3=len1+len2;
	char *str_1=(LPSTR)(LPCTSTR)str_a;
	char *str_2=(LPSTR)(LPCTSTR)str_b;
	
	/*strrev(str_1);
	strrev(str_2);*/
	for(int i=0;i<len1;i++)
	{
		for(int j=0;j<len2;j++)
		{
			c[i+j+1]=c[i+j+1]+(str_1[i]-'0')*(str_2[j]-'0');//空出移位专门给开始的位置留着进位
		}
	}
	for(int i=len1+len2;i>0;--i)
	{
		if(c[i]>=10)
		{
			c[i-1]=c[i-1]+c[i]/10;
			c[i]=c[i]%10;
		}
	}
	for(int i=0;i<len1+len2;i++)
	{
		c1[i]=c[i]+'0';
	}
	CString s;
	res = CA2CT(c1);
	str_b="";
	UpdateData(false);
}
//大数右移
void C和太阳肩并肩的计算器Dlg::OnBnClickedButton13()
{
	UpdateData(true);
	
	char *arr=(LPSTR)(LPCTSTR)str_a;
	int len=str_a.GetLength()+1;
	char *temp=(char*)malloc(strlen(arr)+1);
	strcpy(temp,arr);
	
	for (int i = 0; i < len-1; i++)
	{
		int temp = arr[i];
		arr[i] = (arr[i] - '0') / 2+'0';
		if ((temp-'0') % 2 != 0)
		{
			if (i < len - 2)
			{
				arr[i + 1] = (arr[i + 1] - '0' + 10) + '0';
			}
		}
	}
	res=str_a;
	str_a=temp;
	UpdateData(false);
}

void C和太阳肩并肩的计算器Dlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
		//char *res=mod(arr,brr);*/
	int len=str_a.GetLength()-1;
	int r=0;
	for(int i=0;i<=len;i++)
	{
		if(((str_a[i]-'0')+r*10)>(str_b[0]-'0'))
			r=((str_a[i]-'0')+r*10)%(str_b[0]-'0');
		else
			r=(str_a[i]-'0')+r*10;
	}
	res=char(r+'0');
	UpdateData(false);
}
