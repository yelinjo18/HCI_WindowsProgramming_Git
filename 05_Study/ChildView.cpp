
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "05_Study.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	// 실습 5-1 클라이언트 영역 마우스 메시지 처리
	m_bDrawMode = FALSE;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
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
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// 실습 5-2 마우스 캡처
	SetCapture();

	// 실습 5-1 클라이언트 영역 마우스 메시지 처리
	m_bDrawMode = TRUE;
	x1 = x2 = point.x;
	y1 = y2 = point.y;

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// 실습 5-1 클라이언트 영역 마우스 메시지 처리
	if (m_bDrawMode)
	{
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);

		dc.SetROP2(R2_NOT);
		dc.Ellipse(x1, y1, x2, y2);

		dc.SetROP2(R2_NOT);
		x2 = point.x;
		y2 = point.y;
		dc.Ellipse(x1, y1, x2, y2);
	}

	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// 실습 5-1 클라이언트 영역 마우스 메시지 처리
	CClientDC dc(this);
	dc.SelectStockObject(NULL_BRUSH);

	dc.SetROP2(R2_COPYPEN);
	x2 = point.x;
	y2 = point.y;
	dc.Ellipse(x1, y1, x2, y2);

	m_bDrawMode = FALSE;

	// 실습 5-2 마우스 캡처
	::ReleaseCapture();

	CWnd::OnLButtonUp(nFlags, point);
}
