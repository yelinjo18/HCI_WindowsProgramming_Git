
// DrawPoints.h : DrawPoints ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CDrawPointsApp:
// �� Ŭ������ ������ ���ؼ��� DrawPoints.cpp�� �����Ͻʽÿ�.
//

class CDrawPointsApp : public CWinApp
{
public:
	CDrawPointsApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawPointsApp theApp;
