// B811181 조예린
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "Simple.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_ptarray.SetSize(20);
	m_index = -1;
	m_width = m_height = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_SIZE()
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
	dc.TextOutW(50, 200, CString("HCI Windows Programming"));
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_ptarray[++m_index % 20] = point;
	m_ptlist.AddTail(point);

	CString str, str2;
	str.Format(CString("왼쪽 마우스 클릭 위치: (%d, %d)\n"), point.x, point.y);
	str2.Format(CString("윈도우 폭 = %d, 높이 = %d \n"), m_width, m_height);
	str += str2;
	MessageBox(str, CString("Left Mouse"), MB_OK);

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CString str;

	/* 
	// m_ptlist 출력
	if (m_ptlist.GetSize() > 0)
	{
		str.Format(CString("왼쪽 클릭 수 : %d\n"), m_ptlist.GetCount());
		POSITION pos = m_ptlist.GetHeadPosition();
		while (pos != NULL)
		{
			CPoint pt = m_ptlist.GetNext(pos);
			CString str1;
			str1.Format(CString("(%d, %d) \n"), pt.x, pt.y);
			str += str1;
		}
	}
	*/

	// m_ptarray 출력
	if (!m_ptarray.IsEmpty())
	{
		str.Format(CString("왼쪽 클릭 수 : %d\n"), m_index + 1);
		for (int i = 0; i < ((m_index+1) % 20); i++)
		{
			CPoint pt = m_ptarray[i];
			CString str1;
			str1.Format(CString("(%d, %d) \n"), pt.x, pt.y);
			str += str1;
		}
	}

	MessageBox(str);

	CWnd::OnRButtonDown(nFlags, point);
}


void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	m_width = cx, m_height = cy;

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
