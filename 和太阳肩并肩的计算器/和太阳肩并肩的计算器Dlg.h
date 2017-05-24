// 和太阳肩并肩的计算器Dlg.h : 头文件
//

#pragma once


// C和太阳肩并肩的计算器Dlg 对话框
class C和太阳肩并肩的计算器Dlg : public CDialog
{
// 构造
public:
	C和太阳肩并肩的计算器Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_DIALOG };

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
	CString str_a;
	CString str_b;
	afx_msg void OnBnClickedButton1();
	int n;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton5();
	CString res;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton10();
	CString str;
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	bool flag;
	afx_msg void OnBnClickedButton14();
};
