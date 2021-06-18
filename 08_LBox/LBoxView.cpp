
// LBoxView.cpp: CLBoxView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "LBox.h"
#endif

#include "LBoxDoc.h"
#include "LBoxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLBoxView

IMPLEMENT_DYNCREATE(CLBoxView, CFormView)

BEGIN_MESSAGE_MAP(CLBoxView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CLBoxView::OnBnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CLBoxView::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_ToRight, &CLBoxView::OnBnClickedButtonToright)
	ON_BN_CLICKED(IDC_BUTTON_ToLeft, &CLBoxView::OnBnClickedButtonToleft)
	ON_LBN_DBLCLK(IDC_LIST_LEFT, &CLBoxView::OnLbnDblclkListLeft)
	ON_LBN_DBLCLK(IDC_LIST_RIGHT, &CLBoxView::OnLbnDblclkListRight)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()

// CLBoxView 생성/소멸

CLBoxView::CLBoxView() noexcept
	: CFormView(IDD_LBOX_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CLBoxView::~CLBoxView()
{
}

void CLBoxView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ADD, m_editadd);
	DDX_Control(pDX, IDC_LIST_LEFT, m_left);
	DDX_Control(pDX, IDC_LIST_RIGHT, m_right);
	DDX_Control(pDX, IDC_SCROLLBAR_RED, m_red);
	DDX_Control(pDX, IDC_SCROLLBAR_GREEN, m_green);
	DDX_Control(pDX, IDC_SCROLLBAR_BLUE, m_blue);
}

BOOL CLBoxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CLBoxView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_left.ResetContent();
	m_right.ResetContent();

	CLBoxDoc* pDoc = GetDocument();
	int num = pDoc->m_leftstring.GetSize();
	for(int i=0;i<num;i++)
	{
		m_left.AddString(pDoc->m_leftstring[i]);
	}


	//m_left.AddString(CString("사과"));
	//m_left.AddString(CString("파인애플"));
	//m_left.AddString(CString("딸기"));
	//m_left.AddString(CString("복숭아"));

	m_red.SetScrollRange(0, 255, FALSE);
	m_green.SetScrollRange(0, 255, FALSE);
	m_blue.SetScrollRange(0, 255, FALSE);

	m_red.SetScrollPos(200);
	m_green.SetScrollPos(200);
	m_blue.SetScrollPos(200);
}


// CLBoxView 진단

#ifdef _DEBUG
void CLBoxView::AssertValid() const
{
	CFormView::AssertValid();
}

void CLBoxView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CLBoxDoc* CLBoxView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLBoxDoc)));
	return (CLBoxDoc*)m_pDocument;
}
#endif //_DEBUG


// CLBoxView 메시지 처리기


void CLBoxView::OnBnClickedButtonInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CLBoxDoc* pDoc = GetDocument();
	CString str;
	m_editadd.GetWindowTextW(str);
	m_left.AddString(str);
	pDoc->m_leftstring.Add(str);
	pDoc->SetModifiedFlag();
	m_editadd.SetWindowTextW(CString(""));
	AfxGetMainWnd()->SetWindowText(_T("추가"));
}


void CLBoxView::OnBnClickedButtonDel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CLBoxDoc* pDoc = GetDocument();
	int nIndex = m_left.GetCurSel();
	if (nIndex != LB_ERR)
	{
		m_left.DeleteString(nIndex);
		pDoc->m_leftstring.RemoveAt(nIndex);
		pDoc->SetModifiedFlag();
	}
	AfxGetMainWnd()->SetWindowText(_T("삭제"));
}


void CLBoxView::OnBnClickedButtonToright()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CLBoxDoc* pDoc = GetDocument();
	int nIndex = m_left.GetCurSel();
	if (nIndex != LB_ERR) {
		CString str;
		m_left.GetText(nIndex, str);
		m_left.DeleteString(nIndex);
		pDoc->m_leftstring.RemoveAt(nIndex);
		pDoc->SetModifiedFlag();
		m_left.SetCurSel(nIndex); // 삭제된 다음 위치의 항목이 자동 선택됨
		m_right.AddString(str);
		AfxGetMainWnd()->SetWindowText(_T("왼쪽에서 오른쪽으로"));
	}
}


void CLBoxView::OnBnClickedButtonToleft()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CLBoxDoc* pDoc = GetDocument();
	int nIndex = m_right.GetCurSel();
	if (nIndex != LB_ERR) {
		CString str;
		m_right.GetText(nIndex, str);
		m_right.DeleteString(nIndex);
		pDoc->m_leftstring.Add(str);
		pDoc->SetModifiedFlag();
		m_right.SetCurSel(nIndex); // 삭제된 다음 위치의 항목이 자동 선택됨
		m_left.AddString(str);
		AfxGetMainWnd()->SetWindowText(_T("오른쪽에서 왼쪽으로"));
	}
}


void CLBoxView::OnLbnDblclkListLeft()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CLBoxDoc* pDoc = GetDocument();
	int nIndex = m_left.GetCurSel();
	if (nIndex != LB_ERR) {
		CString str;
		m_left.GetText(nIndex, str);
		m_left.DeleteString(nIndex);
		pDoc->m_leftstring.RemoveAt(nIndex);
		pDoc->SetModifiedFlag();
		m_left.SetCurSel(nIndex); // 삭제된 다음 위치의 항목이 자동 선택됨
		m_right.AddString(str);
		AfxGetMainWnd()->SetWindowText(_T("왼쪽에서 오른쪽으로"));
	}
}


void CLBoxView::OnLbnDblclkListRight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CLBoxDoc* pDoc = GetDocument();
	int nIndex = m_right.GetCurSel();
	if (nIndex != LB_ERR) {
		CString str;
		m_right.GetText(nIndex, str);
		m_right.DeleteString(nIndex);
		pDoc->m_leftstring.Add(str);
		pDoc->SetModifiedFlag();
		m_right.SetCurSel(nIndex); // 삭제된 다음 위치의 항목이 자동 선택됨
		m_left.AddString(str);
		AfxGetMainWnd()->SetWindowText(_T("오른쪽에서 왼쪽으로"));
	}
}


void CLBoxView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int pos;
	int delta = 0;

	if (pScrollBar != NULL) { // 스크롤 바 컨트롤이 발생시킨 메시지면...
		// RED
		if (pScrollBar->GetSafeHwnd() == m_red.GetSafeHwnd()) {
			switch (nSBCode) {
			case SB_THUMBTRACK:
				pScrollBar->SetScrollPos(nPos);
				break;
			case SB_PAGELEFT:	delta -= 20;	break;
			case SB_PAGERIGHT:	delta += 20;	break;
			case SB_LINELEFT:	delta -= 4;	break;
			case SB_LINERIGHT:	delta += 4;	break;
			}
			if (delta != 0)
			{
				pos = pScrollBar->GetScrollPos();
				pScrollBar->SetScrollPos(pos + delta);
			}
			Invalidate();	// 화면 출력 OnDraw()
		}
		// GREEN
		if (pScrollBar->GetSafeHwnd() == m_green.GetSafeHwnd()) {
			switch (nSBCode) {
			case SB_THUMBTRACK:
				pScrollBar->SetScrollPos(nPos);
				break;
			case SB_PAGELEFT:	delta -= 20;	break;
			case SB_PAGERIGHT:	delta += 20;	break;
			case SB_LINELEFT:	delta -= 4;	break;
			case SB_LINERIGHT:	delta += 4;	break;
			}
			if (delta != 0)
			{
				pos = pScrollBar->GetScrollPos();
				pScrollBar->SetScrollPos(pos + delta);
			}
			Invalidate();	// 화면 출력 OnDraw()
		}
		// BLUE
		if (pScrollBar->GetSafeHwnd() == m_blue.GetSafeHwnd()) {
			switch (nSBCode) {
			case SB_THUMBTRACK:
				pScrollBar->SetScrollPos(nPos);
				break;
			case SB_PAGELEFT:	delta -= 20;	break;
			case SB_PAGERIGHT:	delta += 20;	break;
			case SB_LINELEFT:	delta -= 4;	break;
			case SB_LINERIGHT:	delta += 4;	break;
			}
			if (delta != 0)
			{
				pos = pScrollBar->GetScrollPos();
				pScrollBar->SetScrollPos(pos + delta);
			}
			Invalidate();	// 화면 출력 OnDraw()
		}
	}
	else // 윈도우 스크롤 바가 발생시킨 메시지면...
		CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CLBoxView::OnDraw(CDC* pDC)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	int r = m_red.GetScrollPos();
	int g = m_green.GetScrollPos();
	int b = m_blue.GetScrollPos();

	CBrush br(RGB(r, g, b));
	pDC->SelectObject(&br);
	pDC->SelectStockObject(NULL_PEN);
	CRect m_rect;
	GetClientRect(&m_rect);
	pDC->Rectangle(m_rect);
}
