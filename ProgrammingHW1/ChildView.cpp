﻿// B811181 조예린
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "ProgrammingHW1.h"
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
	m_ptrlist.RemoveAll();
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

	POSITION pos = m_ptrlist.GetHeadPosition();
	while (pos != NULL)
	{
		CPoint pt = m_ptrlist.GetNext(pos);

		dc.SelectStockObject(LTGRAY_BRUSH);
		dc.Rectangle(pt.x - 50, pt.y - 50, pt.x + 50, pt.y + 50);

		CBrush br(RGB(255, 0, 0));
		dc.SelectObject(&br);
		CPoint tript[3] = { CPoint(pt.x, pt.y - 50), CPoint(pt.x - 50, pt.y + 50),CPoint(pt.x + 50, pt.y + 50) };
		dc.Polygon(tript, 3);
	}
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO
	CClientDC dc(this);

	CPen pen(PS_SOLID, 2, RGB(255, 0, 255));
	dc.SelectObject(&pen);
	dc.Ellipse(point.x - 50, point.y - 50, point.x + 50, point.y + 50);

	CFont font;
	font.CreatePointFont(150, CString("Arial"));
	dc.SelectObject(&font);
	dc.SetBkColor(RGB(255, 255, 0));
	dc.SetTextColor(RGB(0, 0, 255));

	CRect rect(point.x - 25, point.y - 25, point.x + 25, point.y + 25);
	dc.DrawText(CString("HCI"), rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO
	m_ptrlist.AddTail(point);

	Invalidate(NULL);

	CWnd::OnRButtonDown(nFlags, point);
}
