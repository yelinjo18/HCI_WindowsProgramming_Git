
// Bitmaps.h : Bitmaps ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CBitmapsApp:
// �� Ŭ������ ������ ���ؼ��� Bitmaps.cpp�� �����Ͻʽÿ�.
//

class CBitmapsApp : public CWinApp
{
public:
	CBitmapsApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBitmapsApp theApp;
