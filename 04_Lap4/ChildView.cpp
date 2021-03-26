// B811181 조예린
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "Lap4_.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_index = -1;
	m_ptrarray.SetSize(20);
}

CChildView::~CChildView()
{
	m_ptrarray.RemoveAll();
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
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
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//dc.Ellipse(100, 100, 200, 200);
	CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
	dc.SelectObject(&pen);
	CBrush br(RGB(255, 255, 0));
	dc.SelectObject(&br);

	for (int i = 0; i <= m_index; i++)
	{
		CPoint pt = m_ptrarray[i];
		dc.Rectangle(pt.x - 50, pt.y - 50, pt.x + 50, pt.y + 50);
	}
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	m_ptrarray[++m_index % 20] = point;
	Invalidate(NULL);

	CWnd::OnLButtonDown(nFlags, point);
	// 코드 작성x
}

void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	CFont font;
	font.CreatePointFont(400, CString("Arial"));
	dc.SelectObject(&font);
	dc.TextOutW(point.x, point.y, CString("Right Clicked!"));

	CWnd::OnRButtonDown(nFlags, point);
}
