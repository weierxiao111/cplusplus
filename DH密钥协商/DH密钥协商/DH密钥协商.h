
// DH��ԿЭ��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDH��ԿЭ��App: 
// �йش����ʵ�֣������ DH��ԿЭ��.cpp
//

class CDH��ԿЭ��App : public CWinApp
{
public:
	CDH��ԿЭ��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDH��ԿЭ��App theApp;