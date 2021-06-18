
// HW3Doc.h: CHW3Doc 클래스의 인터페이스
//

#pragma once
#include <afxtempl.h>
#include "CMyDraw.h"



class CHW3Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CHW3Doc() noexcept;
	DECLARE_DYNCREATE(CHW3Doc)

// 특성입니다.
public:
	CList <CMyDraw, CMyDraw&> m_mylist;
	CMyDraw m_curDraw;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CHW3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnFigureRectangle();
	afx_msg void OnUpdateFigureRectangle(CCmdUI* pCmdUI);
	afx_msg void OnFigureEllipse();
	afx_msg void OnUpdateFigureEllipse(CCmdUI* pCmdUI);
	afx_msg void OnFigureLine();
	afx_msg void OnUpdateFigureLine(CCmdUI* pCmdUI);
	afx_msg void OnPencolSky();
	afx_msg void OnUpdatePencolSky(CCmdUI* pCmdUI);
	afx_msg void OnPencolForest();
	afx_msg void OnUpdatePencolForest(CCmdUI* pCmdUI);
	afx_msg void OnPencolWood();
	afx_msg void OnUpdatePencolWood(CCmdUI* pCmdUI);
	afx_msg void OnBrushcolLilac();
	afx_msg void OnUpdateBrushcolLilac(CCmdUI* pCmdUI);
	afx_msg void OnBrushcolNarcissus();
	afx_msg void OnUpdateBrushcolNarcissus(CCmdUI* pCmdUI);
	afx_msg void OnBrushcolCamellia();
	afx_msg void OnUpdateBrushcolCamellia(CCmdUI* pCmdUI);
};
