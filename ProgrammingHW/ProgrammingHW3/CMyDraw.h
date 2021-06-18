#pragma once
#include <afx.h>
class CMyDraw :
    public CObject
{
    DECLARE_SERIAL(CMyDraw)
public:
    CMyDraw();
    //CMyDraw(CRect rect, int ty, COLORREF pen, COLORREF bru);
    CMyDraw(const CMyDraw& t);
    ~CMyDraw();
    void Serialize(CArchive& ar);
    CMyDraw& operator=(const CMyDraw& t);

    void SetRect(CRect rect);
    void SetType(int type);
    void SetPenColor(COLORREF pencol);
    void SetBrushColor(COLORREF brushcol);

    CRect* GetRect();
    int GetType();
    COLORREF* GetPenColor();
    COLORREF* GetBrushColor();
        
private:    // 멤버변수 선언
    CRect m_rect;   // start point & end point 저장
    int m_type; // 1 : Rectangle, 2 : Ellipse, 3 : Line
    COLORREF m_pencol, m_brushcol;
};

