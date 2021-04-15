#pragma once
class CMyData
{
	CMyData();
	CMyData(CPoint st, CPoint ed, COLORREF col, CString str);
	~CMyData();

private:
	CPoint m_mystart, m_myend;
	COLORREF m_pencolor;
	CString m_mystr;

public:
	void SetStPoint(CPoint st);
	void SetEdPoint(CPoint ed);
	void SetPenColor(COLORREF col);
	void SetString(CString str);

	CPoint* GetStPoint();
	CPoint* GetEdPoint();
	COLORREF* GetPenColor();
	CString* GetString();
};

