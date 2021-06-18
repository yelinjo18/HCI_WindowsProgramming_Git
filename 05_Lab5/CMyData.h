#pragma once
class CMyData
{
public:
	CMyData();
	CMyData(CPoint st, CPoint end, COLORREF col, CString str);
	~CMyData();
	// Set ÇÔ¼ö
	void SetStartPoint(CPoint pt);
	void SetEndPoint(CPoint pt);
	void SetStr(CString str);
	void SetPenColor(COLORREF col);
	//...
	CPoint* GetStartPoint();
	CPoint* GetEndPoint();
	CString* GetStr();
	COLORREF* GetPenColor();

private:
	CPoint m_mystart;
	CPoint m_myend;
	COLORREF m_pencolor;
	CString m_mystr;
};

