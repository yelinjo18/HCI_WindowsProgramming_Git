// CMyMDless.cpp: 구현 파일
//

#include "pch.h"
#include "Lab9.h"
#include "CMyMDless.h"
#include "afxdialogex.h"
#include "Lab9Doc.h"
#include "Lab9View.h"

// CMyMDless 대화 상자

IMPLEMENT_DYNAMIC(CMyMDless, CDialogEx)

CMyMDless::CMyMDless(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_str(_T(""))
	, m_font(0)
{

}

CMyMDless::~CMyMDless()
{
}

void CMyMDless::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STR, m_str);
	DDV_MaxChars(pDX, m_str, 20);
	DDX_CBIndex(pDX, IDC_FONT, m_font);
	DDV_MinMaxInt(pDX, m_font, 0, 2);
}


BEGIN_MESSAGE_MAP(CMyMDless, CDialogEx)
	ON_BN_CLICKED(IDAPPLY, &CMyMDless::OnBnClickedApply)
END_MESSAGE_MAP()


// CMyMDless 메시지 처리기


void CMyMDless::OnBnClickedApply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_pView->m_str = m_str;
	m_pView->m_font = m_font;
	m_pView->Invalidate();
}


void CMyMDless::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	DestroyWindow();
}


void CMyMDless::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pView->m_pDlg = NULL;
	delete this;
}
