// ��̫���粢��ļ�����Dlg.h : ͷ�ļ�
//

#pragma once


// C��̫���粢��ļ�����Dlg �Ի���
class C��̫���粢��ļ�����Dlg : public CDialog
{
// ����
public:
	C��̫���粢��ļ�����Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
