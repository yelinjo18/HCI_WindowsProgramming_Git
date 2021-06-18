﻿
// Lap7View.h: CLap7View 클래스의 인터페이스
//

#pragma once


class CLap7View : public CView
{
protected: // serialization에서만 만들어집니다.
	CLap7View() noexcept;
	DECLARE_DYNCREATE(CLap7View)

// 특성입니다.
public:
	CLap7Doc* GetDocument() const;	// GetDocument()->...
	int m_cx, m_cy;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CLap7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // Lap7View.cpp의 디버그 버전
inline CLap7Doc* CLap7View::GetDocument() const
   { return reinterpret_cast<CLap7Doc*>(m_pDocument); }
#endif

