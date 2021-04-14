
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "TrackMouse.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_bMouseIn = FALSE;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()



// CChildView �޽��� ó����

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(m_bMouseIn == FALSE){
		// ���콺 Ŀ�� ������ ��û�Ѵ�.
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(tme);
		tme.dwFlags = TME_LEAVE;
		tme.hwndTrack = this->m_hWnd;
		tme.dwHoverTime = HOVER_DEFAULT;
		::TrackMouseEvent(&tme);

		// ���� ������ ũ�⸦ 300*150���� �����Ѵ�.
		CWnd *pMainWnd = AfxGetMainWnd();
		CRect rect;
		pMainWnd->GetWindowRect(&rect);
		rect.right = rect.left + 300;
		rect.bottom = rect.top + 150;
		pMainWnd->MoveWindow(&rect);

		// ���콺 Ŀ���� Ŭ���̾�Ʈ ���� �ȿ� ������ ǥ���Ѵ�.
		m_bMouseIn = TRUE;
	}
}


void CChildView::OnMouseLeave()
{
	// ���콺 Ŀ���� Ŭ���̾�Ʈ ���� �ۿ� ������ ǥ���Ѵ�.
	m_bMouseIn = FALSE;

	// ���� ������ ũ�⸦ 200*100���� �����Ѵ�.
	CWnd *pMainWnd = AfxGetMainWnd();
	CRect rect;
	pMainWnd->GetWindowRect(&rect);
	rect.right = rect.left + 200;
	rect.bottom = rect.top + 100;
	pMainWnd->MoveWindow(&rect);
}
