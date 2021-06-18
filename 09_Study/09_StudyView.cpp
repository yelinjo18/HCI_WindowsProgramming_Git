
// 09_StudyView.cpp: CMy09StudyView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "09_Study.h"
#endif

#include "09_StudyDoc.h"
#include "09_StudyView.h"
#include "CMyDialog.h"
#include "CMyMlessDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy09StudyView
static UINT WM_FINDREPLACE = ::RegisterWindowMessage(FINDMSGSTRING);

IMPLEMENT_DYNCREATE(CMy09StudyView, CView)

BEGIN_MESSAGE_MAP(CMy09StudyView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_REGISTERED_MESSAGE(WM_FINDREPLACE, OnFindReplaceView)
END_MESSAGE_MAP()

// CMy09StudyView 생성/소멸

CMy09StudyView::CMy09StudyView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_str = _T("");
	m_font = 0;

	// 실습 9-4
	m_pDlg = NULL;

	// 실습 9-6
	pDlg = NULL;
}

CMy09StudyView::~CMy09StudyView()
{
}

BOOL CMy09StudyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy09StudyView 그리기

void CMy09StudyView::OnDraw(CDC* pDC)
{
	CMy09StudyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CFont font;
	CString fontname;

	if (m_font == 0)	fontname = _T("굴림");
	else if (m_font == 1)	fontname = _T("궁서");
	else if (m_font == 2)	fontname = _T("바탕");
	font.CreatePointFont(400, fontname);

	pDC->SelectObject(&font);
	pDC->TextOutW(10, 10, m_str);

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy09StudyView 인쇄

BOOL CMy09StudyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy09StudyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy09StudyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy09StudyView 진단

#ifdef _DEBUG
void CMy09StudyView::AssertValid() const
{
	CView::AssertValid();
}

void CMy09StudyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy09StudyDoc* CMy09StudyView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy09StudyDoc)));
	return (CMy09StudyDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy09StudyView 메시지 처리기


void CMy09StudyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	/* 실습 9-1
	CDialog dlg(IDD_DIALOG1);
	if (dlg.DoModal() == IDOK)
		MessageBox(_T("확인버튼 누름"));
	else
		MessageBox(_T("취소 버튼 누름"));
		*/

	/*
	// 실습 9-2
	CMyDialog dlg;
	dlg.m_str = m_str;
	dlg.m_font = m_font;

	int result = dlg.DoModal();
	if (result == IDOK)
	{
		m_str = dlg.m_str;
		m_font = dlg.m_font;
		Invalidate();
	}
	else if (result == IDCLEAR)
	{
		m_str = _T("");
		Invalidate();
	}
	*/


	// 실습 9-6
	if (pDlg != NULL)
		pDlg->SetFocus();
	else
	{
		pDlg = new CFindReplaceDialog();
		pDlg->Create(FALSE, _T(""), _T(""), FR_DOWN, this);
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMy09StudyView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_pDlg != NULL)
		m_pDlg->SetFocus();
	else {
		m_pDlg = new CMyMlessDialog();
		m_pDlg->m_pView = this;

		m_pDlg->m_str = m_str;
		m_pDlg->m_font = m_font;

		m_pDlg->Create(IDD_DIALOG2);
		m_pDlg->ShowWindow(SW_SHOW);
	}

	CView::OnRButtonDown(nFlags, point);
}


void CMy09StudyView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CView::OnLButtonDblClk(nFlags, point);
}


LRESULT CMy09StudyView::OnFindReplaceView(WPARAM wParam, LPARAM lParam)
{
	// TODO: 여기에 구현 코드 추가.
	return LRESULT();
	CString str;

	if (pDlg->IsTerminating())
	{
		pDlg = NULL;
		return 0;
	}
	else if (pDlg->FindNext())
	{
		str.Format(_T("찾을 문자열 : %s"), pDlg->GetFindString());
		MessageBox(str);
	}
	else if (pDlg->ReplaceCurrent())
	{
		str.Format(_T("찾을 문자열 : %s\n\r바꿀 문자열 : %s"),
			pDlg->GetFindString(), pDlg->GetReplaceString());
		MessageBox(str);
	}
	else if (pDlg->ReplaceAll())
	{
		str.Format(_T("찾을 문자열 :  %s\n\r바꿀 문자열 : %s"),
			pDlg->GetFindString(), pDlg->GetReplaceString());
		MessageBox(str);
	}
}
