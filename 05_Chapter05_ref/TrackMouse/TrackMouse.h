
// TrackMouse.h : TrackMouse ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CTrackMouseApp:
// �� Ŭ������ ������ ���ؼ��� TrackMouse.cpp�� �����Ͻʽÿ�.
//

class CTrackMouseApp : public CWinApp
{
public:
	CTrackMouseApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTrackMouseApp theApp;
