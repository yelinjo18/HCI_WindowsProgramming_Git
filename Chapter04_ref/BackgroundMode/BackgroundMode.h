
// BackgroundMode.h : BackgroundMode ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CBackgroundModeApp:
// �� Ŭ������ ������ ���ؼ��� BackgroundMode.cpp�� �����Ͻʽÿ�.
//

class CBackgroundModeApp : public CWinApp
{
public:
	CBackgroundModeApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBackgroundModeApp theApp;
