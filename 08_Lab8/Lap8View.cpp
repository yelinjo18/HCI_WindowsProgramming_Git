
// Lap8View.cpp: CLap8View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Lap8.h"
#endif

#include "Lap8Doc.h"
#include "Lap8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLap8View

IMPLEMENT_DYNCREATE(CLap8View, CFormView)

BEGIN_MESSAGE_MAP(CLap8View, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_CHECK1, &CLap8View::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON1, &CLap8View::OnBnClickedButton1)
	ON_STN_DBLCLK(IDC_METAFILE, &CLap8View::OnStnDblclickMetafile)
END_MESSAGE_MAP()

// CLap8View 생성/소멸

CLap8View::CLap8View() noexcept
	: CFormView(IDD_LAP8_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CLap8View::~CLap8View()
{
}

void CLap8View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_check);
	DDX_Control(pDX, IDC_CHECK2, m_3state);
	DDX_Control(pDX, IDC_RADIO1, m_radio1);
	DDX_Control(pDX, IDC_RADIO2, m_radio2);
	DDX_Control(pDX, IDC_METAFILE, m_metafile);
}

BOOL CLap8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CLap8View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_check.SetCheck(1);
	m_3state.SetCheck(2);
	m_radio1.SetCheck(1);

	m_metafile.SetEnhMetaFile(::GetEnhMetaFile(CString("test.emf")));
	// CLap8View 인쇄
}

BOOL CLap8View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CLap8View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CLap8View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CLap8View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CLap8View 진단

#ifdef _DEBUG
void CLap8View::AssertValid() const
{
	CFormView::AssertValid();
}

void CLap8View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CLap8Doc* CLap8View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLap8Doc)));
	return (CLap8Doc*)m_pDocument;
}
#endif //_DEBUG


// CLap8View 메시지 처리기


void CLap8View::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int state_checkbox = m_check.GetCheck();
	int state_3state = m_3state.GetCheck();
	int state_radio1 = m_radio1.GetCheck();
	int state_radio2 = m_radio2.GetCheck();

	CString str;
	str.Format(CString(""));
	//MessageBox
}

void CLap8View::OnBnClickedCheck1()
{

}


void CLap8View::OnStnDblclickMetafile()
{
	MessageBox(CString("Double Clicked"));
}