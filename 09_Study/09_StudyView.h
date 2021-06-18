
// 09_StudyView.h: CMy09StudyView 클래스의 인터페이스
//

#pragma once
class CMyMlessDialog;

class CMy09StudyView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy09StudyView() noexcept;
	DECLARE_DYNCREATE(CMy09StudyView)

// 특성입니다.
public:
	CMy09StudyDoc* GetDocument() const;
	CString m_str;
	int m_font;

	// 실습 9-4
	CMyMlessDialog* m_pDlg;

	// 실습 9-6
	CFindReplaceDialog* pDlg;

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
	virtual ~CMy09StudyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
protected:
	LRESULT OnFindReplaceView(WPARAM wParam, LPARAM lParam);
};

#ifndef _DEBUG  // 09_StudyView.cpp의 디버그 버전
inline CMy09StudyDoc* CMy09StudyView::GetDocument() const
   { return reinterpret_cast<CMy09StudyDoc*>(m_pDocument); }
#endif

