
// DrawTexts.h : DrawTexts ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CDrawTextsApp:
// �� Ŭ������ ������ ���ؼ��� DrawTexts.cpp�� �����Ͻʽÿ�.
//

class CDrawTextsApp : public CWinApp
{
public:
	CDrawTextsApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawTextsApp theApp;
