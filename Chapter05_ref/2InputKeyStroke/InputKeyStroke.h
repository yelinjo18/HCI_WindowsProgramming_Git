
// InputKeyStroke.h : InputKeyStroke ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CInputKeyStrokeApp:
// �� Ŭ������ ������ ���ؼ��� InputKeyStroke.cpp�� �����Ͻʽÿ�.
//

class CInputKeyStrokeApp : public CWinApp
{
public:
	CInputKeyStrokeApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CInputKeyStrokeApp theApp;
