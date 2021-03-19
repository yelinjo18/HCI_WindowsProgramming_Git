
// ChildView.h: CChildView 클래스의 인터페이스
//


#pragma once

#include <afxtempl.h>

// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:
	int m_width, m_height;
	CList <CPoint, CPoint&> m_ptlist;
	CArray <CPoint, CPoint&> m_ptarray;		// SetSize를 어디서? ChildView 생성자에서
	int m_index;

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();	//WM_PAINT 화면 출력
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

