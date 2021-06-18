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

	// 확장 메타파일 객체를 생성하고 초기화한다.
	CMetaFileDC dc;
	dc.CreateEnhanced(NULL, NULL, NULL, NULL);
	// 멤버 함수를 호출하여 출력한다.
	dc.Rectangle(0, 0, 10, 10);
	dc.Ellipse(1, 1, 9, 9);
	// 확장 메타파일 핸들을 얻는다.
	m_hmf = dc.CloseEnhanced();
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

	CRect rect;
	GetClientRect(&rect);
	dc.SetMapMode(MM_ANISOTROPIC);		// MM_ISOTROPIC 과 비교
	dc.SetWindowExt(100, 100);
	dc.SetViewportExt(rect.Width(), rect.Height());
	dc.RoundRect(0, 0, 100, 100, 50, 50);
	dc.DrawEdge(CRect(20, 20, 80, 80),
		BDR_SUNKENINNER | BDR_RAISEDOUTER, BF_RECT);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	/*
	CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
	dc.SelectObject(&pen);
	CBrush br(RGB(255, 255, 0));
	dc.SelectObject(&br);

	for (int i = 0; i <= m_index; i++)
	{
		CPoint pt = m_ptrarray[i];
		dc.Rectangle(pt.x - 50, pt.y - 50, pt.x + 50, pt.y + 50);
	}
	*/
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	m_ptrarray[++m_index % 20] = point;

	CPoint pts[4] = { CPoint(point.x, point.y - 50),CPoint(point.x+50, point.y) ,
		CPoint(point.x, point.y + 50) ,CPoint(point.x-50, point.y) };

	//dc.SelectStockObject(LTGRAY_BRUSH);
	//dc.Polygon(pts, 4);
	//dc.Polyline(pts, 4);


	CBrush br(HS_DIAGCROSS, RGB(255, 0, 0));
	dc.SelectObject(&br);
	//dc.Ellipse(point.x - 100, point.y - 100, point.x + 100, point.y + 100);
	/*
	dc.MoveTo(point.x - 100, point.y - 100);
	dc.LineTo(point.x + 100, point.y + 100);
	dc.MoveTo(point.x + 100, point.y - 100);
	dc.LineTo(point.x - 100, point.y + 100);
	*/

	/*
	CRect rect(point.x - 100, point.y - 100, point.x + 100, point.y + 100);
	dc.PlayMetaFile(m_hmf, &rect);
	*/

	//Invalidate(NULL);	// 무효영역 WM_PAINT 발생 --> OnPaint() 화면 출력
	//Invalidate();		// 다 지우고 OnPaint() 화면 출력

	CWnd::OnLButtonDown(nFlags, point);
	// 코드 작성x
}

void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	/*
	CFont font;
	font.CreatePointFont(200, CString("Arial"));
	dc.SelectObject(&font);
	dc.SetTextColor(RGB(255, 0, 0));
	dc.SetBkColor(RGB(200, 200, 200));
	//dc.TextOutW(point.x, point.y, CString("Right Clicked!"));

	dc.SetBkMode(TRANSPARENT);
	CRect rect(point.x - 100, point.y - 100, point.x + 100, point.y + 100);
	dc.SelectStockObject(NULL_BRUSH);	// NULL_BRUSH : 바탕을 투명하게 해주는 BRUSH
	dc.Rectangle(rect);					// default 바탕색이 흰색임
	dc.DrawText(CString("Hello HCI!"), rect, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	*/

	/*
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);
	CBrush brush(&bitmap);
	dc.SelectObject(&brush);
	CRect rect(point.x - 100, point.y - 100, point.x + 100, point.y + 100);
	dc.Ellipse(rect);
	*/

	CRect rect(point.x - 20, point.y - 20, point.x + 20, point.y + 20);
	dc.PlayMetaFile(m_hmf, &rect);


	CWnd::OnRButtonDown(nFlags, point);
}
