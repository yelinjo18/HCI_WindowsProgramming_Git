
// MappingMode2.h : MappingMode2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMappingMode2App:
// �� Ŭ������ ������ ���ؼ��� MappingMode2.cpp�� �����Ͻʽÿ�.
//

class CMappingMode2App : public CWinApp
{
public:
	CMappingMode2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMappingMode2App theApp;
