// B811181 조예린
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "HW2.h"
#include "ChildView.h"
#include <math.h>
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	isDrawMode = false;

	found_pos = NULL;
	isfound = false;
}

CChildView::~CChildView()
{
	my_lst.RemoveAll();
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONDBLCLK()
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
	
	if (my_lst.GetSize() > 0)
	{
		dc.SelectStockObject(NULL_BRUSH);
		CFont font;
		font.CreatePointFont(200, _T("궁서"));
		dc.SelectObject(&font);

		POSITION pos = my_lst.GetHeadPosition();
		while (pos != NULL)
		{
			m_curData = my_lst.GetNext(pos);
			m_st = *m_curData.GetStPoint();
			m_ed = *m_curData.GetEdPoint();
			COLORREF col = *m_curData.GetPenColor();
			COLORREF f_col = *m_curData.GetFontColor();
			CString str = *m_curData.GetString();

			CPen pen(PS_SOLID, 1, col);
			dc.SelectObject(&pen);

			dc.Rectangle(m_st.x, m_st.y, m_ed.x, m_ed.y);

			dc.SetTextColor(f_col);
			CRect rect(m_st.x, m_st.y + 5, m_ed.x, m_ed.y);
			dc.DrawText(str, &rect, DT_CENTER);
		}
	}
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	isDrawMode = true;
	m_st = m_ed = point;
	SetCapture();

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (isDrawMode)
	{
		CClientDC dc(this);

		dc.SelectStockObject(NULL_BRUSH);

		dc.SetROP2(R2_NOT);
		dc.Rectangle(m_st.x, m_st.y, m_ed.x, m_ed.y);;

		dc.SetROP2(R2_NOT);
		m_ed = point;
		dc.Rectangle(m_st.x, m_st.y, m_ed.x, m_ed.y);
	}

	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	isDrawMode = false;
	ReleaseCapture();

	m_ed = point;

	CRect rect(m_st.x, m_st.y, m_ed.x, m_ed.y);
	rect.NormalizeRect();
	m_st.x = rect.left;
	m_st.y = rect.top;
	m_ed.x = rect.right;
	m_ed.y = rect.bottom;

	m_curData.SetStPoint(m_st);
	m_curData.SetEdPoint(m_ed);
	m_curData.SetPenColor(RGB(0, 0, 0));
	m_curData.SetString(CString(""));
	// 랜덤 색상
	srand((unsigned int)(time(NULL)));
	COLORREF ran_col = RGB((rand()*3) % 257, rand() % 257, (rand()*7) % 257);
	m_curData.SetFontColor(ran_col);

	my_lst.AddTail(m_curData);

	Invalidate();

	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	if (my_lst.GetSize() > 0)
	{
		POSITION pos = my_lst.GetHeadPosition();
		while (pos != NULL)
		{
			POSITION tmp_pos = pos;

			m_curData = my_lst.GetNext(pos);
			m_st = *m_curData.GetStPoint();
			m_ed = *m_curData.GetEdPoint();
			CRect rect(m_st.x, m_st.y, m_ed.x, m_ed.y);
			
			if (rect.PtInRect(point))
			{
				isfound = true;
				if (found_pos != NULL)
					my_lst.GetAt(found_pos).SetPenColor(RGB(0, 0, 0));
				found_pos = tmp_pos;

				my_lst.GetAt(found_pos).SetPenColor(RGB(255, 0, 0));

				pos = NULL;
			}
		}
		Invalidate();
	}

	CWnd::OnRButtonDown(nFlags, point);
}


void CChildView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	if (found_pos != NULL)
	{
		my_lst.GetAt(found_pos).SetPenColor(RGB(0, 0, 0));
		found_pos = NULL;
		isfound = false;
	}

	Invalidate();

	CWnd::OnRButtonDblClk(nFlags, point);
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (found_pos != NULL)
	{
		m_curData = my_lst.GetAt(found_pos);
		m_st = *m_curData.GetStPoint();
		m_ed = *m_curData.GetEdPoint();

		switch (nChar)
		{
		case VK_LEFT:
			m_st.x -= 20;
			m_ed.x -= 20;
			break;
		case VK_RIGHT:
			m_st.x += 20;
			m_ed.x += 20;
			break;
		case VK_UP:
			m_st.y -= 20;
			m_ed.y -= 20;
			break;
		case VK_DOWN:
			m_st.y += 20;
			m_ed.y += 20;
			break;
		}

		my_lst.GetAt(found_pos).SetStPoint(m_st);
		my_lst.GetAt(found_pos).SetEdPoint(m_ed);
	}

	Invalidate();

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (found_pos != NULL)
	{
		m_curData = my_lst.GetAt(found_pos);
		CString str = *m_curData.GetString();

		if (nChar == _T('\b')) {
			if (str.GetLength() > 0)
				str.Delete(str.GetLength() - 1, 1);
		}
		// 그 밖의 경우에는 동적 배열에 글자를 추가한다.
		else {
			str.AppendChar(nChar);
		}

		my_lst.GetAt(found_pos).SetString(str);
	}

	Invalidate();

	CWnd::OnChar(nChar, nRepCnt, nFlags);
}
