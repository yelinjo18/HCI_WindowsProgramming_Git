
// LBoxView.h: CLBoxView 클래스의 인터페이스
//

#pragma once


class CLBoxView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CLBoxView() noexcept;
	DECLARE_DYNCREATE(CLBoxView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_LBOX_FORM };
#endif

// 특성입니다.
public:
	CLBoxDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CLBoxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editadd;
	CListBox m_left;
	CListBox m_right;
	afx_msg void OnBnClickedButtonInsert();
	afx_msg void OnBnClickedButtonDel();
	afx_msg void OnBnClickedButtonToright();
	afx_msg void OnBnClickedButtonToleft();
	afx_msg void OnLbnDblclkListLeft();
	afx_msg void OnLbnDblclkListRight();
	CScrollBar m_red;
	CScrollBar m_green;
	CScrollBar m_blue;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void OnDraw(CDC* /*pDC*/);
};

#ifndef _DEBUG  // LBoxView.cpp의 디버그 버전
inline CLBoxDoc* CLBoxView::GetDocument() const
   { return reinterpret_cast<CLBoxDoc*>(m_pDocument); }
#endif

