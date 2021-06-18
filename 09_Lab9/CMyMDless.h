﻿#pragma once


// CMyMDless 대화 상자
class CLab9View;
class CMyMDless : public CDialogEx
{
	DECLARE_DYNAMIC(CMyMDless)

public:
	CMyMDless(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMyMDless();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_str;
	int m_font;
	CLab9View* m_pView;
	afx_msg void OnBnClickedApply();
	virtual void OnCancel();
	virtual void PostNcDestroy();
};
