
// DrawCircles.h : DrawCircles ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CDrawCirclesApp:
// �� Ŭ������ ������ ���ؼ��� DrawCircles.cpp�� �����Ͻʽÿ�.
//

class CDrawCirclesApp : public CWinApp
{
public:
	CDrawCirclesApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawCirclesApp theApp;
