
// SystemMenu.h : SystemMenu ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSystemMenuApp:
// �� Ŭ������ ������ ���ؼ��� SystemMenu.cpp�� �����Ͻʽÿ�.
//

class CSystemMenuApp : public CWinApp
{
public:
	CSystemMenuApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSystemMenuApp theApp;
