#include "pch.h"
#include "CMyData.h"

IMPLEMENT_SERIAL(CMyData, CObject, 1)

CMyData::CMyData()
{

}

CMyData::CMyData(CString str, BOOL It, BOOL Under)
{
	m_str = str;
	m_bItalic = It;
	m_bUnder = Under;
}

CMyData::~CMyData()	{}

void CMyData::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << m_bItalic << m_bUnder << m_str;
	}
	else
	{
		ar >> m_bItalic >> m_bUnder >> m_str;
	}
}
