// ��̫���粢��ļ�����.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��̫���粢��ļ�����App:
// �йش����ʵ�֣������ ��̫���粢��ļ�����.cpp
//

class C��̫���粢��ļ�����App : public CWinApp
{
public:
	C��̫���粢��ļ�����App();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��̫���粢��ļ�����App theApp;