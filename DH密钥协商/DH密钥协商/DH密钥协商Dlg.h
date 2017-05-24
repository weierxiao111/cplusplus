
// DH密钥协商Dlg.h : 头文件
//

#pragma once

typedef unsigned long size_long;
// CDH密钥协商Dlg 对话框
class CDH密钥协商Dlg : public CDialogEx
{
// 构造
public:
	CDH密钥协商Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DH_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	size_long _p1;
	size_long _p2;
	size_long _n;
	size_long _pkey;
	size_long _pkey2;
	size_long _ekey;
	size_long _ekey2;
	size_long _k;
	size_long _k2;
	size_long _p3;
	size_long _randx;
	size_long _randy;
	size_long _ka;
	size_long _kb;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton3();
	CString _c;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
};
