#include "pch.h"
#include "CMyDraw.h"

IMPLEMENT_SERIAL(CMyDraw, CObject, 1)

CMyDraw::CMyDraw()
{
	m_rect = CRect(0, 0, 0, 0);
	m_type = 1;
	m_pencol = RGB(0xc7, 0xe6, 0xfe);
	m_brushcol = RGB(0xb2, 0x76, 0xa0);
}

CMyDraw::~CMyDraw()
{
}

CMyDraw::CMyDraw(const CMyDraw& t)
{
	m_rect = t.m_rect;
	m_type = t. m_type;
	m_pencol = t.m_pencol;
	m_brushcol = t.m_brushcol;
}

CMyDraw& CMyDraw::operator= (const CMyDraw& t)
{
	m_rect = t.m_rect;
	m_type = t.m_type;
	m_pencol = t.m_pencol;
	m_brushcol = t.m_brushcol;

	return *this;
}

void CMyDraw::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << m_rect << m_type << m_pencol << m_brushcol;
	}
	else
	{
		ar >> m_rect >> m_type >> m_pencol >> m_brushcol;
	}
}

void CMyDraw::SetRect(CRect rect) { m_rect = rect; }
void CMyDraw::SetType(int type) { m_type = type; }
void CMyDraw::SetPenColor(COLORREF pencol) { m_pencol = pencol; }
void CMyDraw::SetBrushColor(COLORREF brushcol) { m_brushcol = brushcol; }

CRect* CMyDraw::GetRect() { return &m_rect; }
int CMyDraw::GetType() { return m_type; }
COLORREF* CMyDraw::GetPenColor() { return &m_pencol; }
COLORREF* CMyDraw::GetBrushColor() { return &m_brushcol; }
