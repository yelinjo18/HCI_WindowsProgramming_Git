
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "ShowCaret.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
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


void CChildView::OnSetFocus(CWnd* pOldWnd)
{
	CreateSolidCaret(20, 20); // ĳ���� �����Ѵ�.
	SetCaretPos(CPoint(50, 50)); // ĳ���� ��ġ�� �����Ѵ�.
	ShowCaret(); // ĳ���� ȭ�鿡 ���δ�.
}


void CChildView::OnKillFocus(CWnd* pNewWnd)
{
	HideCaret(); // ĳ���� �����.
	::DestroyCaret(); // ĳ���� �ı��Ѵ�.
}
