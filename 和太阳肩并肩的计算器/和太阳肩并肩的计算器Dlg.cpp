// ��̫���粢��ļ�����Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��̫���粢��ļ�����.h"
#include "��̫���粢��ļ�����Dlg.h"
#include<assert.h>
#include<string.h>
#include<math.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define N 26 

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// C��̫���粢��ļ�����Dlg �Ի���




C��̫���粢��ļ�����Dlg::C��̫���粢��ļ�����Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(C��̫���粢��ļ�����Dlg::IDD, pParent)
	, str_a(_T(""))
	, str_b(_T(""))
	, n(0)
	, res(_T(""))
	, str(_T(""))
	, flag(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C��̫���粢��ļ�����Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, str_a);
	DDX_Text(pDX, IDC_EDIT2, str_b);
	DDX_Text(pDX, IDC_EDIT3, n);
	DDX_Text(pDX, IDC_EDIT4, res);
	DDX_Text(pDX, IDC_EDIT6, str);
}

BEGIN_MESSAGE_MAP(C��̫���粢��ļ�����Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &C��̫���粢��ļ�����Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C��̫���粢��ļ�����Dlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT3, &C��̫���粢��ļ�����Dlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON5, &C��̫���粢��ļ�����Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON3, &C��̫���粢��ļ�����Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON7, &C��̫���粢��ļ�����Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON9, &C��̫���粢��ļ�����Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON8, &C��̫���粢��ļ�����Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON10, &C��̫���粢��ļ�����Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &C��̫���粢��ļ�����Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON4, &C��̫���粢��ļ�����Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON12, &C��̫���粢��ļ�����Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &C��̫���粢��ļ�����Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &C��̫���粢��ļ�����Dlg::OnBnClickedButton14)
END_MESSAGE_MAP()


// C��̫���粢��ļ�����Dlg ��Ϣ�������

BOOL C��̫���粢��ļ�����Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C��̫���粢��ļ�����Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C��̫���粢��ļ�����Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C��̫���粢��ļ�����Dlg::OnQueryDragIcon()
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
//��������
void C��̫���粢��ļ�����Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	char *str1=(LPSTR)(LPCTSTR)str;
	char *temp=(char*)malloc(strlen(str1)+1);
	strcpy(temp,str1);
	encode(str1,n);
	res=str;
	str=temp;
	UpdateData(false);
}
//��������
void C��̫���粢��ļ�����Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	char *str1=(LPSTR)(LPCTSTR)str;
	char *temp=(char*)malloc(strlen(str1)+1);
	strcpy(temp,str1);
	decode(str1,n);
	res=str;
	str=temp;
	UpdateData(false);
}

void C��̫���粢��ļ�����Dlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
//�����˷�
void C��̫���粢��ļ�����Dlg::OnBnClickedButton5()
{
	 //TODO: �ڴ���ӿؼ�֪ͨ����������
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
//�����ӷ�
void C��̫���粢��ļ�����Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
UpdateData(true); 
	long int len1, len2;
	long int i, j, k;
	int a[100];
	int b[100];
	int up, l;
	char e[100] = { '\0' };
	/*��ʼ������*/
	len1 = str_a.GetLength();
	len2 = str_b.GetLength();
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));

	/*ע�⣬���뵹�ű�������*/
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
//s��
void C��̫���粢��ļ�����Dlg::OnBnClickedButton7()
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

//�˳�
void C��̫���粢��ļ�����Dlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}
//���
void C��̫���粢��ļ�����Dlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	res="";
}

//�����㷨  
char *encode(char *c_str, int a, int b, int n);
//�����㷨  
char *decode(char *m_str, int a, int b, int n);

//��������coprimeΪ�����n���ص�Ԫ��  
void setCoprime(int coprime[], int n);
//��ȡvalue1,value2�����Լ��  
int getGcd(int value1, int value2);
//��coprime��Ѱ��a��ģn����Ԫ_a  
int get_a(int coprime[], int a, int n);
char *f_encode(char *c_str, int a, int b, int n)
{
	char *p_str = c_str; //��С������  
	assert(c_str);  //�ж������ַ���c_str�Ƿ�ΪNULL  

	while (*c_str)
	{
		if (' ' == *c_str)  //�����ո������  
		{
			++c_str;
			continue;
		}

		if ((*c_str >='A')&&(*c_str<='Z')) 
		{
			*c_str -= 'A';  //���ַ�ת��Ϊ��Ӧ����  
			*c_str = (a*(*c_str) + b) % n;//���ܺ����㷨  
			*c_str += 'A';  //������ת��Ϊ�ַ�  
		}
		if ((*c_str >='a')&&(*c_str <='z')) 
		{
			*c_str -= 'a';  //���ַ�ת��Ϊ��Ӧ����  
			*c_str = (a*(*c_str) + b) % n;//���ܺ����㷨  
			*c_str += 'a';  //������ת��Ϊ�ַ�  
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
	int gcd = 0; //���Լ��  
	int divisor = 0; //����  

	do  //շת�����  
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
	if (1 == getGcd(n, i))//�ж��Ƿ�n,i�Ƿ���  
		*(coprime++) = i; //��i����coprime��  
}
char *f_decode(char *m_str, int a, int b, int n)
{
	char *p_str = m_str; //��С������  
	int coprime[32] = { 0 }; //���С��n������n���ص�Ԫ��  
	int _a = 0; //���a��ģn����Ԫ  
	int i = 0; //��������  

	assert(m_str);  //�ж������ַ���m_str�Ƿ�ΪNULL  

	for (; i < 32; i++)  //������Ԫ�ظ�Ϊ0  
		coprime[i] = 0;

	setCoprime(coprime, n);//��������coprime�����n���ص�Ԫ��  

	_a = get_a(coprime, a, n);//��coprime��Ѱ��a����Ԫ_a  


	while (*m_str)
	{
		if (' ' == *m_str)  //�����ո������  
		{
			++m_str;
			continue;
		}

		if ((*m_str >='A') &&(*m_str <='Z'))
		{
			*m_str -= 'A';  //���ַ�ת��Ϊ��Ӧ����  
			*m_str = (_a*(*m_str - b + n)) % n;//���ܺ����㷨  
			*m_str += 'A';  //������ת��Ϊ�ַ�  
		}
		if ((*m_str >='a') &&(*m_str <='z'))
		{
			*m_str -= 'a';  //���ַ�ת��Ϊ��Ӧ����  
			*m_str = (_a*(*m_str - b + n)) % n;//���ܺ����㷨  
			*m_str += 'a';  //������ת��Ϊ�ַ�  
		}
		++m_str;
	}
	return p_str;
}
//�������
void C��̫���粢��ļ�����Dlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
//�������
void C��̫���粢��ļ�����Dlg::OnBnClickedButton11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
//�����Ƚϴ�С
int compare(char *str_a, char *str_b)
{
	int len_a, len_b;
	len_a = strlen(str_a);          //�ֱ��ȡ������λ�����бȽ�
	len_b = strlen(str_b);

	if (strcmp(str_a, str_b) == 0)    //���رȽϽ��
		return 0;
	if (len_a > len_b)
		return 1;
	else if (len_a == len_b)
		return strcmp(str_a, str_b);
	else
		return -1;
}
//�������
void C��̫���粢��ļ�����Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true); 
	int f, n;
	int i, k, len_a, len_b;
	int num_a[1000] = { 0 };          //��ʼ���������飬��λȫ��0
	int num_b[1000] = { 0 };
	int num_c[1000];
	char *str_1=(LPSTR)(LPCTSTR)str_a;
	char *str_2=(LPSTR)(LPCTSTR)str_b;
	len_a = str_a.GetLength();         //�ֱ�������������λ��
	len_b = str_b.GetLength();
	k = len_a > len_b ? len_a : len_b;                    //�������λ��
	num_c[0] = 0;
	f = 0;
	n = compare(str_1, str_2);

	for (i = 0; i<len_a; i++)                   //�ߵ��洢
		num_a[i] = str_a[len_a - i - 1] - '0';
	for (i = 0; i<len_b; i++)
		num_b[i] = str_b[len_b - i - 1] - '0';

	for (i = 0; i<k; i++)         //��λ���м���
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


//��������
void C��̫���粢��ļ�����Dlg::OnBnClickedButton12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
			c[i+j+1]=c[i+j+1]+(str_1[i]-'0')*(str_2[j]-'0');//�ճ���λר�Ÿ���ʼ��λ�����Ž�λ
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
//��������
void C��̫���粢��ļ�����Dlg::OnBnClickedButton13()
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

void C��̫���粢��ļ�����Dlg::OnBnClickedButton14()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
