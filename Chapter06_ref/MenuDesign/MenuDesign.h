
// MenuDesign.h : MenuDesign ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMenuDesignApp:
// �� Ŭ������ ������ ���ؼ��� MenuDesign.cpp�� �����Ͻʽÿ�.
//

class CMenuDesignApp : public CWinApp
{
public:
	CMenuDesignApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMenuDesignApp theApp;
