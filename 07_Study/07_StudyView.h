
// 07_StudyView.h: CMy07StudyView 클래스의 인터페이스
//

#pragma once


class CMy07StudyView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy07StudyView() noexcept;
	DECLARE_DYNCREATE(CMy07StudyView)

// 특성입니다.
public:
	CMy07StudyDoc* GetDocument() const;

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
	virtual ~CMy07StudyView();
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
};

#ifndef _DEBUG  // 07_StudyView.cpp의 디버그 버전
inline CMy07StudyDoc* CMy07StudyView::GetDocument() const
   { return reinterpret_cast<CMy07StudyDoc*>(m_pDocument); }
#endif

