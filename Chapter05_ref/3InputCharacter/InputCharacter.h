
// InputCharacter.h : InputCharacter ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CInputCharacterApp:
// �� Ŭ������ ������ ���ؼ��� InputCharacter.cpp�� �����Ͻʽÿ�.
//

class CInputCharacterApp : public CWinApp
{
public:
	CInputCharacterApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CInputCharacterApp theApp;
