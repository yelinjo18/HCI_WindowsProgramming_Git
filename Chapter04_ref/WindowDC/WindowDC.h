
// WindowDC.h : WindowDC ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CWindowDCApp:
// �� Ŭ������ ������ ���ؼ��� WindowDC.cpp�� �����Ͻʽÿ�.
//

class CWindowDCApp : public CWinApp
{
public:
	CWindowDCApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWindowDCApp theApp;
