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
	m_mylist.RemoveAll();
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
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
	font.CreatePointFont(150, _T("궁서"));
	dc.SelectObject(&font);
	
	if (m_mylist.GetSize() > 0)
	{
		dc.SelectStockObject(NULL_BRUSH);

		POSITION pos = m_mylist.GetHeadPosition();
		while (pos != NULL)
		{
			m_curData = m_mylist.GetNext(pos);
			m_start = *m_curData.GetStartPoint();
			m_end = *m_curData.GetEndPoint();
			COLORREF col = *m_curData.GetPenColor();
			CPen pen(PS_SOLID, 1, col);
			dc.SelectObject(&pen);

			CRect rect(m_start.x, m_start.y, m_end.x, m_end.y);
			dc.Rectangle(rect);
			
			//dc.DrawText(m_str, &rect,0);
			
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
	m_curData.SetStr(CString(""));
	//m_curData.SetPenColor(RGB(0, 0, 0));
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
			m_foundpos = pos;
			m_curData = m_mylist.GetNext(pos);
			m_start = *m_curData.GetStartPoint();
			m_end = *m_curData.GetEndPoint();
			CRect rect(m_start.x, m_start.y, m_end.x, m_end.y);
			if (rect.PtInRect(point))
			{
				// 사각형 발견, 주소 foundpos 저장
				m_mylist.GetAt(m_foundpos).SetPenColor(RGB(255, 0, 0));
				pos = NULL;

			}
			else
				m_foundpos = NULL;

		}
	}

	/*
	CClientDC dc(this);
	CRect rect(10, 10, 300, 300);
	dc.Rectangle(rect);
	ClientToScreen(rect);
	ClipCursor(rect);
	*/

	CWnd::OnRButtonDown(nFlags, point);
}


void CChildView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_foundpos != NULL)
	{
		//m_mylist.GetAt(m_foundpos).SetPencolor(RGB(255, 0, 0));
		m_foundpos = NULL;

	}
		
	
	// 초기화
	// ClipCursor(NULL);
	CWnd::OnRButtonDblClk(nFlags, point);
}


void CChildView::OnSetFocus(CWnd* pOldWnd)
{
	CWnd::OnSetFocus(pOldWnd);
	CreateSolidCaret(20, 20);
	SetCaretPos(CPoint(50, 50));
	ShowCaret();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CChildView::OnKillFocus(CWnd* pNewWnd)
{
	CWnd::OnKillFocus(pNewWnd);

	HideCaret();
	::DestroyCaret();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_foundpos != NULL)
	{
		m_curData = m_mylist.GetAt(m_foundpos);
		m_start = *m_curData.GetStartPoint();
		m_end = *m_curData.GetEndPoint();
		
		switch (nChar) {
		case VK_LEFT:
			m_start.x -= 20;
			m_end.x -= 20;
			break;
		case VK_RIGHT:
			m_start.x += 20;
			m_end.x += 20;
			break;
		case VK_UP:
			m_start.y -= 20;
			m_end.y -= 20;
			break;
		case VK_DOWN:
			m_start.y += 20;
			m_end.y += 20;
			break;
		
		}

		m_mylist.GetAt(m_foundpos).SetStartPoint(m_start);
		m_mylist.GetAt(m_foundpos).SetEndPoint(m_end);
		
		Invalidate();
	}

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// Backspace 입력 시 맨 마지막 글자를 삭제한다.
	if (m_foundpos != NULL)
	{
		//CString str = m_mylist.GetAt(m_foundpos).GetStr();
		if (nChar == _T('\b')) {
			if (m_str.GetLength() > 0)
				m_str.Delete(m_str.GetLength() - 1, 1);
		}
		// 그 밖의 경우에는 동적 배열에 글자를 추가한다.
		else {
			m_str.AppendChar(nChar);
		}

		// 화면을 갱신한다.
		Invalidate();
	}
	CWnd::OnChar(nChar, nRepCnt, nFlags);
}
