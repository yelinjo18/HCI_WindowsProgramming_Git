#include "pch.h"
#include "CMyData.h"

CMyData::CMyData()
{
	m_mystart = CPoint(0, 0);
	m_myend = CPoint(0, 0);
	m_pencolor = RGB(0, 0, 0);
	m_fontcolor = RGB(0, 0, 0);
	m_mystr = CString("");
}

CMyData::CMyData(CPoint st, CPoint ed, COLORREF col, COLORREF f_col, CString str)
{
	m_mystart = st;
	m_myend = ed;
	m_pencolor = col;
	m_fontcolor = f_col;
	m_mystr = str;
}

CMyData::~CMyData()
{

}


void CMyData::SetStPoint(CPoint st)			{ m_mystart = st; }
void CMyData::SetEdPoint(CPoint ed)			{ m_myend = ed; }
void CMyData::SetPenColor(COLORREF col)		{ m_pencolor = col; }
void CMyData::SetString(CString str)		{ m_mystr = str; }
void CMyData::SetFontColor(COLORREF f_col)	{ m_fontcolor = f_col; }

CPoint* CMyData::GetStPoint() { return &m_mystart; }
CPoint* CMyData::GetEdPoint() { return &m_myend; }
COLORREF* CMyData::GetPenColor() { return &m_pencolor; }
COLORREF* CMyData::GetFontColor() { return &m_fontcolor; }
CString* CMyData::GetString() { return &m_mystr; }