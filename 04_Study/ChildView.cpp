
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "04_Study.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	// 실습 4-4 CMetaFileDC
	CMetaFileDC dc;
	dc.CreateEnhanced(NULL, NULL, NULL, NULL);
	dc.Rectangle(0, 0, 10, 10);
	dc.Ellipse(1, 1, 9, 9);
	m_hmf = dc.CloseEnhanced();
}

CChildView::~CChildView()
{
	::DeleteEnhMetaFile(m_hmf);
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

	// 실습 4-10 배경모드 변경
	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
	//	::LoadCursor(nullptr, IDC_ARROW),(HBRUSH)GetStockObject(GRAY_BRUSH), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	/*
	// 실습 4-1 CPaintDC
	dc.Rectangle(0, 0, 200, 100);
	dc.Ellipse(200, 100, 500, 200);
	*/

	/*
	// 실습 4-5 그리기 - 점
	for (int x = 0; x < 256; x++)
		for (int y = 0; y < 256; y++)
			dc.SetPixelV(x, y, RGB(x, y, 0));
	*/

	/*
	// 실습 4-6 그리기 - 선
	CRect rect;
	GetClientRect(&rect);

	dc.MoveTo(0, rect.bottom / 2);
	dc.LineTo(rect.right, rect.bottom / 2);
	dc.MoveTo(rect.right / 2, 0);
	dc.LineTo(rect.right / 2, rect.bottom);

	POINT points[] = { {rect.right / 2,0}, {rect.right,rect.bottom / 2},
		{rect.right / 2,rect.bottom}, {0, rect.bottom / 2}, {rect.right / 2,0} };
	// m_rect[] = { CPoint(0, 0), CPoint(0, rect.bottom), CPoint(rect.right, rect.bottom), CPoint(rect.right, 0) };
	dc.Polyline(points, 5);
	*/

	/*
	// 실습 4-7 텍스트 출력
	CRect rect;
	GetClientRect(&rect);

	dc.SetTextColor(RGB(255, 0, 0));
	dc.SetBkColor(RGB(255, 255, 0));
	dc.DrawText(CString("DrawText 연습"), &rect, 0);
	dc.DrawText(CString("DrawText 연습"), &rect,
		DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	dc.SetTextAlign(TA_CENTER);
	dc.SetTextColor(RGB(0, 0, 255));
	dc.SetBkColor(RGB(0, 255, 0));
	dc.TextOutW(rect.right / 2, rect.bottom * 3 / 4, CString("TextOut 연습"));
	*/

	/*
	// 실습 4-9 매핑모드
	CRect rect;
	GetClientRect(&rect);
	dc.SetMapMode(MM_ANISOTROPIC);
	dc.SetWindowExt(100, 100);
	dc.SetViewportExt(rect.Width(), rect.Height());
	dc.RoundRect(0, 0, 100, 100, 50, 50);
	dc.DrawEdge(CRect(20, 20, 80, 80), BDR_SUNKENINNER | BDR_RAISEDOUTER, BF_RECT);
	*/

	/*
	// 실습 4-10 배경 모드 변환
	dc.SetBkMode(TRANSPARENT);
	dc.TextOutW(100, 100, CString("TRANSPARENT 모드"));

	dc.SetBkMode(OPAQUE);
	dc.SetBkColor(RGB(0, 255, 0));
	dc.TextOutW(100, 50, CString("OPAQUE 모드"));
	*/

	/*
	// 실습 4-11 CPen
	CPen blackpen(PS_SOLID, 1, RGB(0, 0, 0));
	dc.SelectObject(&blackpen);
	dc.Rectangle(50, 200, 150, 300);

	CPen pen1(PS_SOLID, 20, RGB(255, 0, 0));
	dc.SelectObject(&pen1);
	dc.Ellipse(50, 200, 150, 300);
	*/

	/*
	// 실습 4-12 CBrush
	// 솔리드 브러쉬
	CBrush s_brush(RGB(255, 0, 0));
	dc.SelectObject(&s_brush);
	dc.Rectangle(50, 50, 200, 200);

	// 해치 브러쉬
	CBrush h_brush(HS_DIAGCROSS, RGB(0, 0, 255));
	dc.SelectObject(&h_brush);
	dc.Ellipse(250, 50, 400, 200);

	// 비트맵 브러쉬
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);
	CBrush b_brush(&bitmap);
	dc.SelectObject(&b_brush);
	dc.RoundRect(450, 50, 600, 200, 50, 50);
	*/

	/*
	// 실습 4-13 내장 객체 사용
	CRect rect;
	GetClientRect(&rect);
	CBrush brush(HS_CROSS, RGB(0, 255, 0));
	dc.SelectObject(&brush);
	dc.Rectangle(&rect);

	dc.SelectStockObject(BLACK_PEN);
	dc.SelectStockObject(NULL_BRUSH);
	dc.Ellipse(100, 500, 200, 200);

	dc.SelectStockObject(NULL_PEN);
	dc.SelectStockObject(LTGRAY_BRUSH);
	CPoint points[] = { CPoint(250,50), CPoint(450,150), CPoint(300,200), CPoint(250,150) };
	dc.Polygon(points, 4);
	*/

	/*
	// 실습 4-14 비트맵
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);

	dc.BitBlt(10, 10, bmpinfo.bmWidth, bmpinfo.bmHeight,
		&dcmem, 0, 0, SRCCOPY);
	dc.StretchBlt(10, 100, bmpinfo.bmWidth * 4, bmpinfo.bmHeight * 2,
		&dcmem, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);

	dcmem.Rectangle(5, 5, 15, 15);
	dc.BitBlt(350, 10, bmpinfo.bmWidth, bmpinfo.bmHeight,
		&dcmem, 0, 0, SRCCOPY);
	dc.StretchBlt(350, 100, bmpinfo.bmWidth * 4, bmpinfo.bmHeight * 2,
		&dcmem, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
	*/

	// 예제 Region
	CRgn rgn1, rgn2, rgn3;
	rgn1.CreateRectRgn(0, 0, 1, 1);	// 임의로 만든 리전
	rgn2.CreateRectRgn(10, 10, 100, 100);
	rgn3.CreateEllipticRgn(50, 50, 200, 200);

	rgn1.CombineRgn(&rgn2, &rgn3, RGN_XOR);
	CBrush brush(RGB(0, 0, 255));
	dc.FillRgn(&rgn1, &brush);

	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

	// 실습 4-2 CClientDC
	//dc.Rectangle(point.x - 10, point.y - 10, point.x + 10, point.y + 10);

	// 실습 4-4 CMetaFileDC
	CRect rect(point.x - 20, point.y - 20, point.x + 20, point.y + 20);
	dc.PlayMetaFile(m_hmf, &rect);

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

	// 실습 4-2 CClientDC
	//dc.Ellipse(point.x - 10, point.y - 10, point.x + 10, point.y + 10);

	// 실습 4-4 CMetaFileDC
	CRect rect(point.x - 50, point.y - 20, point.x + 50, point.y + 20);
	dc.PlayMetaFile(m_hmf, &rect);

	CWnd::OnRButtonDown(nFlags, point);
}
