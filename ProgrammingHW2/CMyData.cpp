#include "pch.h"
#include "CMyData.h"

CMyData::CMyData()
{
	m_mystart = CPoint(0, 0);
	m_myend = CPoint(0, 0);
	m_pencolor = RGB(0, 0, 0);
	m_mystr = CString("");
}

CMyData::CMyData(CPoint st, CPoint ed, COLORREF col, CString str)
{
	m_mystart = st;
	m_myend = ed;
	m_pencolor = col;
	m_mystr = str;
}

CMyData::~CMyData()
{

}


void CMyData::SetStPoint(CPoint st)		{ m_mystart = st; }
void CMyData::SetEdPoint(CPoint ed)		{ m_myend = ed; }
void CMyData::SetPenColor(COLORREF col) { m_pencolor = col; }
void CMyData::SetString(CString str)	{ m_mystr = str; }

CPoint*		CMyData::GetStPoint()	{ return &m_mystart; }
CPoint*		CMyData::GetEdPoint()	{ return &m_myend; }
COLORREF*	CMyData::GetPenColor()	{ return &m_pencolor; }
CString*	CMyData::GetString()	{ return &m_mystr; }