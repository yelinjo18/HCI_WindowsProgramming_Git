
// MetaFileDC.h : MetaFileDC ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMetaFileDCApp:
// �� Ŭ������ ������ ���ؼ��� MetaFileDC.cpp�� �����Ͻʽÿ�.
//

class CMetaFileDCApp : public CWinApp
{
public:
	CMetaFileDCApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMetaFileDCApp theApp;
