
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "Pens.h"
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

	// �پ��� �� ������ �����Ѵ�.
	int nPenStyle[] = {PS_SOLID, PS_DASH,
		PS_DOT, PS_DASHDOT, PS_DASHDOTDOT,
		PS_NULL, PS_INSIDEFRAME};
	TCHAR *PenStyle[] = {_T("PS_SOLID"), _T("PS_DASH"),
		_T("PS_DOT"), _T("PS_DASHDOT"), _T("PS_DASHDOTDOT"),
		_T("PS_NULL"), _T("PS_INSIDEFRAME")};
	dc.SetTextAlign(TA_BASELINE);
	for(int i=0; i<sizeof(nPenStyle)/sizeof(nPenStyle[0]); i++){
		CPen pen(nPenStyle[i], 1, RGB(0, 0, 255));
		dc.SelectObject(&pen);
		dc.TextOut(50, 25+i*25, PenStyle[i], lstrlen(PenStyle[i]));
		dc.MoveTo(200, 25+i*25);
		dc.LineTo(500, 25+i*25);
	}

	CPen blackpen(PS_SOLID, 1, RGB(0, 0, 0)); // �� 1, ������ PS_SOLID ��

	dc.SelectObject(&blackpen);
	dc.Rectangle(50, 200, 150, 300); // ���� ���̰� 100�� ���簢��
	CPen pen1(PS_SOLID, 20, RGB(255, 0, 0)); // �� 20, PS_SOLID ��
	dc.SelectObject(&pen1);
	dc.Ellipse(50, 200, 150, 300); // ������ 100�� ��

	dc.SelectObject(&blackpen);
	dc.Rectangle(250, 200, 350, 300); // ���� ���̰� 100�� ���簢��
	CPen pen2(PS_INSIDEFRAME, 20, RGB(255, 0, 0)); // �� 20, PS_INSIDEFRAME ��
	dc.SelectObject(&pen2);
	dc.Ellipse(250, 200, 350, 300); // ������ 100�� ��
}

