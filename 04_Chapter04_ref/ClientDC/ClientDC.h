
// ClientDC.h : ClientDC ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CClientDCApp:
// �� Ŭ������ ������ ���ؼ��� ClientDC.cpp�� �����Ͻʽÿ�.
//

class CClientDCApp : public CWinApp
{
public:
	CClientDCApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CClientDCApp theApp;
