
// DrawLines.h : DrawLines ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CDrawLinesApp:
// �� Ŭ������ ������ ���ؼ��� DrawLines.cpp�� �����Ͻʽÿ�.
//

class CDrawLinesApp : public CWinApp
{
public:
	CDrawLinesApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawLinesApp theApp;
