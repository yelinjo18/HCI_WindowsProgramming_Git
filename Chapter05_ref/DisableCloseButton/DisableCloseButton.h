
// DisableCloseButton.h : DisableCloseButton ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CDisableCloseButtonApp:
// �� Ŭ������ ������ ���ؼ��� DisableCloseButton.cpp�� �����Ͻʽÿ�.
//

class CDisableCloseButtonApp : public CWinApp
{
public:
	CDisableCloseButtonApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDisableCloseButtonApp theApp;
