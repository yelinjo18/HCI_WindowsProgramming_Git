
// ChildView.h: CChildView 클래스의 인터페이스
//


#pragma once
#include <afxtempl.h>
#include "CMyData.h"

// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:
	CList <CMyData, CMyData&> m_mylist;
	CMyData m_curData;
	BOOL m_bDrawMode;	// 그리기 작업이 진행 중임들 나타냄
	CPoint m_start, m_end;
	BOOL m_found;
	POSITION m_foundpos;


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
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
};

