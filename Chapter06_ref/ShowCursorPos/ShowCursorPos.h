
// ShowCursorPos.h : ShowCursorPos ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CShowCursorPosApp:
// �� Ŭ������ ������ ���ؼ��� ShowCursorPos.cpp�� �����Ͻʽÿ�.
//

class CShowCursorPosApp : public CWinApp
{
public:
	CShowCursorPosApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CShowCursorPosApp theApp;
