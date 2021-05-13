
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "Lap6.h"
#include "ChildView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_color = RGB(255, 0, 0);
	m_bgcolor = RGB(255, 255, 255);
	m_Light = false;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_COLOR_RED, &CChildView::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CChildView::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CChildView::OnColorBlue)
	ON_COMMAND(ID_COLOR_LIGHT, &CChildView::OnColorLight)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CChildView::OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CChildView::OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CChildView::OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_LIGHT, &CChildView::OnUpdateColorLight)
	ON_WM_CONTEXTMENU()
	ON_WM_MOUSEMOVE()
	ON_WM_SIZE()
	ON_COMMAND(201, &CChildView::On201)
	ON_UPDATE_COMMAND_UI(201, &CChildView::OnUpdate201)
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	CFont font;
	font.CreatePointFont(300, _T("궁서"));
	dc.SelectObject(&font);
	dc.SetTextColor(m_color);
	dc.SetBkColor(m_bgcolor);

	CRect rect;
	GetClientRect(&rect);
	CString str = _T("메뉴 테스트");
	dc.DrawText(str, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	
	CString str2;
	str2.Format(CString("(%d, %d)"), m_cx, m_cy);
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();	// type casting 필수
	//pMainFrame->m_wndStatusBar.SetPaneText(0, str2);
	//AfxGetApp()->GetMainWnd()->SetWindowTextW(str2);
	AfxGetApp()->m_pMainWnd->SetWindowTextW(str2);

	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnColorRed()
{
	m_color = RGB(255, 0, 0);
	Invalidate();
}


void CChildView::OnColorGreen()
{
	m_color = RGB(0, 255, 0);
	Invalidate();
}


void CChildView::OnColorBlue()
{
	m_color = RGB(0, 0, 255);
	Invalidate();
}


void CChildView::OnColorLight()
{
	m_Light = !m_Light;	//토글

	if (m_Light)
		m_bgcolor = RGB(255, 255, 0);
	else
		m_bgcolor = RGB(255, 255, 255);

	Invalidate();
}


void CChildView::OnUpdateColorRed(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_color == RGB(255, 0, 0));
}


void CChildView::OnUpdateColorGreen(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_color == RGB(0, 255, 0));
}


void CChildView::OnUpdateColorBlue(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_color == RGB(0, 0, 255));
}


void CChildView::OnUpdateColorLight(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(m_Light);
	if (m_Light)
		pCmdUI->SetText(CString("Light On"));
	else
		pCmdUI->SetText(CString("Light Off"));
}


void CChildView::OnContextMenu(CWnd* pWnd, CPoint  point)
{
	CMenu menu;
	menu.LoadMenuW(IDR_MAINFRAME);
	CMenu* pMenu = menu.GetSubMenu(4);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, 
		point.x, point.y, AfxGetMainWnd());
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	CString str;
	str.Format(CString("(%d, %d)"), point.x, point.y);
	CMainFrame* pMainFrame = (CMainFrame*) AfxGetMainWnd();	// type casting 필수
	pMainFrame->m_wndStatusBar.SetPaneText(1, str);

	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	m_cx = cx;
	m_cy = cy;
}

void CChildView::On201()
{
	MessageBox(CString("201 menu item enabled"));
}

void CChildView::OnUpdate201(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(true);
}
