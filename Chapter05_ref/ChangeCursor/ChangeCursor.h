
// ChangeCursor.h : ChangeCursor ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CChangeCursorApp:
// �� Ŭ������ ������ ���ؼ��� ChangeCursor.cpp�� �����Ͻʽÿ�.
//

class CChangeCursorApp : public CWinApp
{
public:
	CChangeCursorApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CChangeCursorApp theApp;
