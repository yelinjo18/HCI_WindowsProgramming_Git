
// Regions.h : Regions ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CRegionsApp:
// �� Ŭ������ ������ ���ؼ��� Regions.cpp�� �����Ͻʽÿ�.
//

class CRegionsApp : public CWinApp
{
public:
	CRegionsApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRegionsApp theApp;
