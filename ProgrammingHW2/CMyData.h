#pragma once
class CMyData
{
public:
	CMyData();
	CMyData(CPoint st, CPoint ed, COLORREF col, COLORREF f_col, CString str);
	~CMyData();

private:
	CPoint m_mystart, m_myend;
	COLORREF m_pencolor, m_fontcolor;
	CString m_mystr;

public:
	void SetStPoint(CPoint st);
	void SetEdPoint(CPoint ed);
	void SetPenColor(COLORREF col);
	void SetFontColor(COLORREF f_col);
	void SetString(CString str);

	CPoint* GetStPoint();
	CPoint* GetEdPoint();
	COLORREF* GetPenColor();
	COLORREF* GetFontColor();
	CString* GetString();
};

