
// MappingMode1.h : MappingMode1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMappingMode1App:
// �� Ŭ������ ������ ���ؼ��� MappingMode1.cpp�� �����Ͻʽÿ�.
//

class CMappingMode1App : public CWinApp
{
public:
	CMappingMode1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMappingMode1App theApp;
