
// StockObjects.h : StockObjects ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CStockObjectsApp:
// �� Ŭ������ ������ ���ؼ��� StockObjects.cpp�� �����Ͻʽÿ�.
//

class CStockObjectsApp : public CWinApp
{
public:
	CStockObjectsApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CStockObjectsApp theApp;
