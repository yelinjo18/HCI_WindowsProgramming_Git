
// ShowCaret.h : ShowCaret ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CShowCaretApp:
// �� Ŭ������ ������ ���ؼ��� ShowCaret.cpp�� �����Ͻʽÿ�.
//

class CShowCaretApp : public CWinApp
{
public:
	CShowCaretApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CShowCaretApp theApp;
