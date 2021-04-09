
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "InputCharacter.h"
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
	ON_WM_CHAR()
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
	CPaintDC dc(this);
	
	// ȭ�� ��¿� ��Ʈ�� �����Ѵ�.
	CFont font;
	font.CreatePointFont(150, _T("�ü�"));
	dc.SelectObject(&font);

	// ������� �Էµ� ���ڵ��� ȭ�鿡 ����Ѵ�.
	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(m_str.GetData(), m_str.GetSize(), &rect, DT_LEFT);
}


void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// Backspace �Է� �� �� ������ ���ڸ� �����Ѵ�.
	if(nChar == _T('\b')){
		if(m_str.GetSize() > 0)
			m_str.RemoveAt(m_str.GetSize()-1);
	}
	// �� ���� ��쿡�� ���� �迭�� ���ڸ� �߰��Ѵ�.
	else{
		m_str.Add(nChar);
	}

	// ȭ���� �����Ѵ�.
	Invalidate();
}
