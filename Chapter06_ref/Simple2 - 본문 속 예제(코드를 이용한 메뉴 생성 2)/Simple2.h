
// Simple2.h : Simple2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSimple2App:
// �� Ŭ������ ������ ���ؼ��� Simple2.cpp�� �����Ͻʽÿ�.
//

class CSimple2App : public CWinApp
{
public:
	CSimple2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSimple2App theApp;
