
// Lap7View.cpp: CLap7View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Lap7.h"
#endif

#include "Lap7Doc.h"
#include "Lap7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLap7View

IMPLEMENT_DYNCREATE(CLap7View, CView)

BEGIN_MESSAGE_MAP(CLap7View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CLap7View 생성/소멸

CLap7View::CLap7View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CLap7View::~CLap7View()
{
}

BOOL CLap7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CLap7View 그리기

void CLap7View::OnDraw(CDC* pDC)	// 화면출력 + 프린터 출력 모두 사용
{
	CLap7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// 화면 출력용 폰트를 선택한다.
	CFont font;
	font.CreateFont(30, 0, 0, 0, 0, pDoc->m_myData.m_bItalic,
		pDoc->m_myData.m_bUnder, 0, 0, 0, 0, 0, 0, _T("궁서"));
	pDC->SelectObject(&font);

	// 현재까지 입력된 글자를 화면에 출력한다.
	CRect rect(0, 0, m_cx, m_cy);
	pDC->DrawText(pDoc->m_myData.m_str,
		pDoc->m_myData.m_str.GetLength(), &rect, DT_LEFT);

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

}


// CLap7View 인쇄

BOOL CLap7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CLap7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CLap7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CLap7View 진단

#ifdef _DEBUG
void CLap7View::AssertValid() const
{
	CView::AssertValid();
}

void CLap7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLap7Doc* CLap7View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLap7Doc)));
	return (CLap7Doc*)m_pDocument;
}
#endif //_DEBUG


// CLap7View 메시지 처리기


void CLap7View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CLap7Doc* pDoc = GetDocument();

	// Backspace 입력 시 맨 마지막 글자를 삭제한다.
	if (nChar == _T('\b')) {
		if (pDoc->m_myData.m_str.GetLength() > 0)
			pDoc->m_myData.m_str.Delete(pDoc->m_myData.m_str.GetLength() - 1, 1);
	}
	// 그 밖의 경우에는 동적 배열에 글자를 추가한다.
	else {
		pDoc->m_myData.m_str.AppendChar(nChar);
	}

	// 데이터가 수정되었음을 도큐먼트 객체에 알린다.
	pDoc->SetModifiedFlag();

	// 뷰의 화면을 갱신한다.
	Invalidate();

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CLap7View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_cx = cx;
	m_cy = cy;
}
