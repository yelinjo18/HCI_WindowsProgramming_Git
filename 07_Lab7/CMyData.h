#pragma once
#include <afx.h>
class CMyData :
    public CObject
{
    DECLARE_SERIAL(CMyData)

public:
    CString m_str;
    BOOL m_bItalic, m_bUnder;

    CMyData();
    CMyData(CString str, BOOL It, BOOL Under);
    ~CMyData();
    void Serialize(CArchive& ar);

};

