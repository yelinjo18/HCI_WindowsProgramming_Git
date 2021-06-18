
// 08_StudyView.h: CMy08StudyView 클래스의 인터페이스
//

#pragma once


class CMy08StudyView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CMy08StudyView() noexcept;
	DECLARE_DYNCREATE(CMy08StudyView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY08_STUDY_FORM };
#endif

// 특성입니다.
public:
	CMy08StudyDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy08StudyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CButton m_checkbox;
	CButton m_3state;
	CButton m_radio1;
	CButton m_radio2;
	afx_msg void OnBnClickedButton1();
	CStatic m_metafile;
	afx_msg void OnStnClickedMetafile();
	CEdit m_edit;
	CStatic m_static;
	afx_msg void OnEnChangeMyedit();
	afx_msg void OnEnMaxtextMyedit();
	CListBox m_list1;
	CListBox m_list2;
	CButton m_left;
	CButton m_right;
	afx_msg void OnBnClickedLeft();
	afx_msg void OnBnClickedRight();
	CStatic m_status;
	CScrollBar m_hsb;
	CScrollBar m_vsb;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void OnDraw(CDC* /*pDC*/);
};

#ifndef _DEBUG  // 08_StudyView.cpp의 디버그 버전
inline CMy08StudyDoc* CMy08StudyView::GetDocument() const
   { return reinterpret_cast<CMy08StudyDoc*>(m_pDocument); }
#endif

