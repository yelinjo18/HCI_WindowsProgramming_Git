// B811181 조예린
// HW3Doc.cpp: CHW3Doc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HW3.h"
#endif

#include "HW3Doc.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHW3Doc

IMPLEMENT_DYNCREATE(CHW3Doc, CDocument)

BEGIN_MESSAGE_MAP(CHW3Doc, CDocument)
	ON_COMMAND(ID_FIGURE_RECTANGLE, &CHW3Doc::OnFigureRectangle)
	ON_UPDATE_COMMAND_UI(ID_FIGURE_RECTANGLE, &CHW3Doc::OnUpdateFigureRectangle)
	ON_COMMAND(ID_FIGURE_ELLIPSE, &CHW3Doc::OnFigureEllipse)
	ON_UPDATE_COMMAND_UI(ID_FIGURE_ELLIPSE, &CHW3Doc::OnUpdateFigureEllipse)
	ON_COMMAND(ID_FIGURE_LINE, &CHW3Doc::OnFigureLine)
	ON_UPDATE_COMMAND_UI(ID_FIGURE_LINE, &CHW3Doc::OnUpdateFigureLine)
	ON_COMMAND(ID_PENCOLOR_SKY, &CHW3Doc::OnPencolSky)
	ON_UPDATE_COMMAND_UI(ID_PENCOLOR_SKY, &CHW3Doc::OnUpdatePencolSky)
	ON_COMMAND(ID_PENCOLOR_FOREST, &CHW3Doc::OnPencolForest)
	ON_UPDATE_COMMAND_UI(ID_PENCOLOR_FOREST, &CHW3Doc::OnUpdatePencolForest)
	ON_COMMAND(ID_PENCOLOR_WOOD, &CHW3Doc::OnPencolWood)
	ON_UPDATE_COMMAND_UI(ID_PENCOLOR_WOOD, &CHW3Doc::OnUpdatePencolWood)
	ON_COMMAND(ID_BRUSHCOLOR_LILAC, &CHW3Doc::OnBrushcolLilac)
	ON_UPDATE_COMMAND_UI(ID_BRUSHCOLOR_LILAC, &CHW3Doc::OnUpdateBrushcolLilac)
	ON_COMMAND(ID_BRUSHCOLOR_NARCISSUS, &CHW3Doc::OnBrushcolNarcissus)
	ON_UPDATE_COMMAND_UI(ID_BRUSHCOLOR_NARCISSUS, &CHW3Doc::OnUpdateBrushcolNarcissus)
	ON_COMMAND(ID_BRUSHCOLOR_CAMELLIA, &CHW3Doc::OnBrushcolCamellia)
	ON_UPDATE_COMMAND_UI(ID_BRUSHCOLOR_CAMELLIA, &CHW3Doc::OnUpdateBrushcolCamellia)
END_MESSAGE_MAP()


// CHW3Doc 생성/소멸

CHW3Doc::CHW3Doc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CHW3Doc::~CHW3Doc()
{
}

BOOL CHW3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.
	m_mylist.RemoveAll();
	m_curDraw.SetType(1);
	m_curDraw.SetPenColor(RGB(0xc7, 0xe6, 0xfe));
	m_curDraw.SetBrushColor(RGB(0xb2, 0x76, 0xa0));
	return TRUE;
}

// CHW3Doc serialization

void CHW3Doc::Serialize(CArchive& ar)
{
	m_mylist.Serialize(ar);
	m_curDraw.Serialize(ar);
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CHW3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CHW3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CHW3Doc::SetSearchContent(const CString& value)
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

// CHW3Doc 진단

#ifdef _DEBUG
void CHW3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHW3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CHW3Doc 명령


void CHW3Doc::OnFigureRectangle()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_curDraw.SetType(1);	// 1은 rectangle
	SetModifiedFlag();
}
void CHW3Doc::OnUpdateFigureRectangle(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_curDraw.GetType() == 1);
}


void CHW3Doc::OnFigureEllipse()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_curDraw.SetType(2);	// 2는 Ellipse
	SetModifiedFlag();
}
void CHW3Doc::OnUpdateFigureEllipse(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_curDraw.GetType() == 2);
}


void CHW3Doc::OnFigureLine()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_curDraw.SetType(3);	// 3은 Line
	SetModifiedFlag();
}
void CHW3Doc::OnUpdateFigureLine(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_curDraw.GetType() == 3);
}


void CHW3Doc::OnPencolSky()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_curDraw.SetPenColor(RGB(0xc7, 0xe6, 0xfe));
	SetModifiedFlag();
}
void CHW3Doc::OnUpdatePencolSky(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(*m_curDraw.GetPenColor() == RGB(0xc7, 0xe6, 0xfe));
}


void CHW3Doc::OnPencolForest()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_curDraw.SetPenColor(RGB(0x86, 0xb0, 0x8a));
	SetModifiedFlag();
}
void CHW3Doc::OnUpdatePencolForest(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(*m_curDraw.GetPenColor() == RGB(0x86, 0xb0, 0x8a));
}


void CHW3Doc::OnPencolWood()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_curDraw.SetPenColor(RGB(0xbe, 0xa5, 0x94));
	SetModifiedFlag();
}
void CHW3Doc::OnUpdatePencolWood(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
		// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(*m_curDraw.GetPenColor() == RGB(0xbe, 0xa5, 0x94));
}


void CHW3Doc::OnBrushcolLilac()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_curDraw.SetBrushColor(RGB(0xb2, 0x76, 0xa0));
	SetModifiedFlag();
}
void CHW3Doc::OnUpdateBrushcolLilac(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(*m_curDraw.GetBrushColor() == RGB(0xb2, 0x76, 0xa0));
}


void CHW3Doc::OnBrushcolNarcissus()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_curDraw.SetBrushColor(RGB(0xfe, 0xda, 0x60));
	SetModifiedFlag();
}
void CHW3Doc::OnUpdateBrushcolNarcissus(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(*m_curDraw.GetBrushColor() == RGB(0xfe, 0xda, 0x60));
}


void CHW3Doc::OnBrushcolCamellia()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_curDraw.SetBrushColor(RGB(0xe0, 0x54, 0x2d));
	SetModifiedFlag();
}
void CHW3Doc::OnUpdateBrushcolCamellia(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(*m_curDraw.GetBrushColor() == RGB(0xe0, 0x54, 0x2d));
}

