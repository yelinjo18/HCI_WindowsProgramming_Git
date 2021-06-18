﻿
// 07_StudyDoc.cpp: CMy07StudyDoc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "07_Study.h"
#endif

#include "07_StudyDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy07StudyDoc

IMPLEMENT_DYNCREATE(CMy07StudyDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy07StudyDoc, CDocument)
	ON_COMMAND(ID_STYLE_ITALIC, &CMy07StudyDoc::OnStyleItalic)
	ON_UPDATE_COMMAND_UI(ID_STYLE_ITALIC, &CMy07StudyDoc::OnUpdateStyleItalic)
	ON_COMMAND(ID_STYLE_UNDERLINE, &CMy07StudyDoc::OnStyleUnderline)
	ON_UPDATE_COMMAND_UI(ID_STYLE_UNDERLINE, &CMy07StudyDoc::OnUpdateStyleUnderline)
END_MESSAGE_MAP()


// CMy07StudyDoc 생성/소멸

CMy07StudyDoc::CMy07StudyDoc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CMy07StudyDoc::~CMy07StudyDoc()
{
}

BOOL CMy07StudyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	m_str.RemoveAll();
	m_bItalic = m_bUnderline = false;

	return TRUE;
}




// CMy07StudyDoc serialization

void CMy07StudyDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
		ar << m_bItalic << m_bUnderline;
		m_str.Serialize(ar);
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
		ar >> m_bItalic >> m_bUnderline;
		m_str.Serialize(ar);
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CMy07StudyDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CMy07StudyDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy07StudyDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy07StudyDoc 진단

#ifdef _DEBUG
void CMy07StudyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy07StudyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy07StudyDoc 명령


void CMy07StudyDoc::OnStyleItalic()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_bItalic = !m_bItalic;
	SetModifiedFlag();
	UpdateAllViews(NULL);
}


void CMy07StudyDoc::OnUpdateStyleItalic(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_bItalic);
}


void CMy07StudyDoc::OnStyleUnderline()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_bUnderline = !m_bUnderline;
	SetModifiedFlag();
	UpdateAllViews(NULL);
}


void CMy07StudyDoc::OnUpdateStyleUnderline(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_bUnderline);
}
