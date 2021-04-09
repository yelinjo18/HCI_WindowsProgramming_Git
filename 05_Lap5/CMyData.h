#pragma once
class CMyData
{
public:
	CMyData();
	CMyData(CPoint st, CPoint end, COLORREF col, CString str);
	~CMyData();
	// Set �Լ�
	void SetStartPoint(CPoint pt);
	void SetEndPoint(CPoint pt);
	void SetStr(CString str);
	//...
	CPoint* GetStartPoint();
	CPoint* GetEndPoint();
	CString* GetStr();

private:
	CPoint m_mystart;
	CPoint m_myend;
	COLORREF m_pencolor;
	CString m_mystr;
};

