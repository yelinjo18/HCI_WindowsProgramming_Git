// CMyMlessDialog.cpp: 구현 파일
//

#include "pch.h"
#include "09_Study.h"
#include "CMyMlessDialog.h"
#include "afxdialogex.h"
#include "09_StudyDoc.h"
#include "09_StudyView.h"


// CMyMlessDialog 대화 상자

IMPLEMENT_DYNAMIC(CMyMlessDialog, CDialog)

CMyMlessDialog::CMyMlessDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, m_str(_T(""))
	, m_font(0)
{

}

CMyMlessDialog::~CMyMlessDialog()
{
}

void CMyMlessDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STR, m_str);
	DDV_MaxChars(pDX, m_str, 20);
	DDX_CBIndex(pDX, IDC_FONT, m_font);
	DDV_MinMaxInt(pDX, m_font, 0, 2);
}


BEGIN_MESSAGE_MAP(CMyMlessDialog, CDialog)
	ON_BN_CLICKED(IDAPPLY, &CMyMlessDialog::OnBnClickedApply)
END_MESSAGE_MAP()


// CMyMlessDialog 메시지 처리기


void CMyMlessDialog::OnBnClickedApply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_pView->m_str = m_str;
	m_pView->m_font = m_font;
	m_pView->Invalidate();
}


void CMyMlessDialog::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	DestroyWindow();
}


void CMyMlessDialog::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pView->m_pDlg = NULL;
	delete this;
	CDialog::PostNcDestroy();
}
