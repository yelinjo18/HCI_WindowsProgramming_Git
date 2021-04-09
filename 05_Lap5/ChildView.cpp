// B811181 조예린
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "Lap5.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_bDrawMode = false;
	m_found = false;
	m_foundpos = NULL;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONDBLCLK()
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
	if (m_mylist.GetSize() > 0)
	{
		dc.SelectStockObject(NULL_BRUSH);
		POSITION pos = m_mylist.GetHeadPosition();
		while (pos != NULL)
		{
			m_curData = m_mylist.GetNext(pos);
			m_start = *m_curData.GetStartPoint();
			m_end = *m_curData.GetEndPoint();
			dc.Rectangle(m_start.x, m_start.y, m_end.x, m_end.y);
		}
	}
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDrawMode = true;
	m_start = m_end = point;
	SetCapture();
	::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDrawMode = false;
	ReleaseCapture();

	m_end = point;
	// min max point 정렬
	CRect rect(m_start.x, m_start.y, m_end.x, m_end.y);
	rect.NormalizeRect();
	m_start.x = rect.left;
	m_start.y = rect.top;
	m_end.x = rect.right;
	m_end.y = rect.bottom;
	// 리스트에 CMyData 추가
	m_curData.SetStartPoint(m_start);
	m_curData.SetEndPoint(m_end);
	m_mylist.AddTail(m_curData);

	Invalidate();
	
	/*
	CClientDC dc(this);

	dc.SetMapMode(MM_LOMETRIC);
	CPoint pt = point;
	dc.DPtoLP(&pt);
	dc.Rectangle(pt.x - 100, pt.y + 100, pt.x + 100, pt.y - 100);
	*/

	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrawMode)
	{
		CClientDC dc(this);

		dc.SelectStockObject(NULL_BRUSH);

		dc.SetROP2(R2_NOT);
		dc.Rectangle(m_start.x, m_start.y, m_end.x, m_end.y);;

		dc.SetROP2(R2_NOT);
		m_end = point;
		dc.Rectangle(m_start.x, m_start.y, m_end.x, m_end.y);
	}

	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_found = false;
	if (m_mylist.GetSize() > 0)
	{
		POSITION pos = m_mylist.GetHeadPosition();
		while (pos != NULL)
		{
			m_curData = m_mylist.GetNext(pos);
			m_start = *m_curData.GetStartPoint();
			m_end = *m_curData.GetEndPoint();
			CRect rect(m_start.x, m_start.y, m_end.x, m_end.y);
			if (rect.PtInRect(point))
			{
				// 사각형 발견, 주소 foundpos 저장
			}
		}
	}

	/*
	CClientDC dc(this);
	CRect rect(10, 10, 300, 300);
	dc.Rectangle(rect);
	ClientToScreen(rect);
	ClipCursor(rect
	*/

	CWnd::OnRButtonDown(nFlags, point);
}


void CChildView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_foundpos != NULL)
		// 빨간색->
	
	// 초기화
	// ClipCursor(NULL);
	CWnd::OnRButtonDblClk(nFlags, point);
}
