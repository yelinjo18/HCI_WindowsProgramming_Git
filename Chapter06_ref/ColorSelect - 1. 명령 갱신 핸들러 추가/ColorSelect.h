
// ColorSelect.h : ColorSelect ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CColorSelectApp:
// �� Ŭ������ ������ ���ؼ��� ColorSelect.cpp�� �����Ͻʽÿ�.
//

class CColorSelectApp : public CWinApp
{
public:
	CColorSelectApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CColorSelectApp theApp;
