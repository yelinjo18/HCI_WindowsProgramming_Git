
// PaintDC.h : PaintDC ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CPaintDCApp:
// �� Ŭ������ ������ ���ؼ��� PaintDC.cpp�� �����Ͻʽÿ�.
//

class CPaintDCApp : public CWinApp
{
public:
	CPaintDCApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPaintDCApp theApp;
