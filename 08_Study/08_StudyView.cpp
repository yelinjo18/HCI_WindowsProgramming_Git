
// 08_StudyView.cpp: CMy08StudyView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "08_Study.h"
#endif

#include "08_StudyDoc.h"
#include "08_StudyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy08StudyView

IMPLEMENT_DYNCREATE(CMy08StudyView, CFormView)

BEGIN_MESSAGE_MAP(CMy08StudyView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy08StudyView::OnBnClickedButton1)
	ON_STN_CLICKED(ID_METAFILE, &CMy08StudyView::OnStnClickedMetafile)
	ON_EN_CHANGE(IDC_MYEDIT, &CMy08StudyView::OnEnChangeMyedit)
	ON_EN_MAXTEXT(IDC_MYEDIT, &CMy08StudyView::OnEnMaxtextMyedit)
	ON_BN_CLICKED(IDC_LEFT, &CMy08StudyView::OnBnClickedLeft)
	ON_BN_CLICKED(IDC_RIGHT, &CMy08StudyView::OnBnClickedRight)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
END_MESSAGE_MAP()

// CMy08StudyView 생성/소멸

CMy08StudyView::CMy08StudyView() noexcept
	: CFormView(IDD_MY08_STUDY_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy08StudyView::~CMy08StudyView()
{
}

void CMy08StudyView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_checkbox);
	DDX_Control(pDX, IDC_CHECK2, m_3state);
	DDX_Control(pDX, IDC_RADIO1, m_radio1);
	DDX_Control(pDX, IDC_RADIO2, m_radio2);
	DDX_Control(pDX, ID_METAFILE, m_metafile);
	DDX_Control(pDX, IDC_MYEDIT, m_edit);
	DDX_Control(pDX, IDC_MYSTATIC, m_static);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_LEFT, m_left);
	DDX_Control(pDX, IDC_RIGHT, m_right);
	DDX_Control(pDX, IDC_STATUS, m_status);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_hsb);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_vsb);
}

BOOL CMy08StudyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMy08StudyView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	// 실습 8-2 
	m_checkbox.SetCheck(1);
	m_3state.SetCheck(2);
	m_radio2.SetCheck(1);

	// 실습 8-3
	m_metafile.SetEnhMetaFile(::GetEnhMetaFile(_T("test.emf")));

	// 실습 8-4
	m_edit.SetLimitText(20);

	// 실습 8-5
	m_list1.AddString(_T("사과"));
	m_list1.AddString(_T("딸기"));
	m_list1.AddString(_T("파인애플"));
	m_list1.AddString(_T("복숭아"));

	// 실습 8-6
	m_hsb.SetScrollRange(0, 360, false);
	m_hsb.SetScrollPos(0);
	m_vsb.SetScrollRange(0, 255, false);
	m_vsb.SetScrollPos(128);
}


// CMy08StudyView 인쇄

BOOL CMy08StudyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy08StudyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy08StudyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMy08StudyView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CMy08StudyView 진단

#ifdef _DEBUG
void CMy08StudyView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy08StudyView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy08StudyDoc* CMy08StudyView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy08StudyDoc)));
	return (CMy08StudyDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy08StudyView 메시지 처리기

// 실습 8-6
void CMy08StudyView::OnDraw(CDC* pDC)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	int hpos = m_hsb.GetScrollPos();
	int vpos = m_vsb.GetScrollPos();

	CFont font;
	LOGFONT lf = { 0 };
	lf.lfHeight = vpos / 3 + 1;
	lf.lfEscapement = 10 * hpos;
	font.CreateFontIndirectW(&lf);

	pDC->SelectObject(&font);
	pDC->SetTextColor(RGB(0, 0, vpos));
	pDC->TextOutW(1000, 200, CString("실습 6"));

	CString str;
	str.Format(_T("글자 크기 : %d, 회전각 : %d, 농도 : %d"),
		lf.lfHeight, hpos, vpos);
	m_status.SetWindowTextW(str);
}

// 실습 8-2
void CMy08StudyView::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int s_check = m_checkbox.GetCheck();
	int s_3st = m_3state.GetCheck();
	int s_r1 = m_radio1.GetCheck();
	int s_r2 = m_radio2.GetCheck();

	CString str;
	str.Format(_T("버튼 상태: %d %d %d %d"),
		s_check, s_3st, s_r1, s_r2);
	MessageBox(str, _T("예제"), MB_ICONINFORMATION);
}



// 실습 8-3
void CMy08StudyView::OnStnClickedMetafile()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MessageBox(_T("확장 메타파일 그림 클릭!"));
}



// 실습 8-4
void CMy08StudyView::OnEnChangeMyedit()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.
	CString str;
	m_edit.GetWindowTextW(str);
	m_static.SetWindowTextW(str);

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMy08StudyView::OnEnMaxtextMyedit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MessageBox(_T("최대 길이 도달!"), _T("오류"), MB_ICONERROR);
}



// 실습 8-5
void CMy08StudyView::OnBnClickedLeft()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nIndex = m_list1.GetCurSel();
	if (nIndex != LB_ERR) 
	{
		CString str;
		m_list1.GetText(nIndex, str);
		m_list1.DeleteString(nIndex);
		m_list1.SetCurSel(nIndex);
		m_list2.AddString(str);
		AfxGetMainWnd()->SetWindowTextW(_T("왼쪽에서 오른쪽으로"));
	}
}

void CMy08StudyView::OnBnClickedRight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nIndex = m_list2.GetCurSel();
	if (nIndex != LB_ERR)
	{
		CString str;
		m_list2.GetText(nIndex, str);
		m_list2.DeleteString(nIndex);
		m_list2.SetCurSel(nIndex);
		m_list1.AddString(str);
		AfxGetMainWnd()->SetWindowTextW(_T("오른쪽에서 왼쪽으로"));
	}
}




// 실습 8-5
void CMy08StudyView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (pScrollBar != NULL)
	{
		if (pScrollBar->GetSafeHwnd() == m_hsb.GetSafeHwnd())
		{
			switch (nSBCode)
			{
			case SB_THUMBTRACK:
				pScrollBar->SetScrollPos(nPos);
				break;
			}
			Invalidate();
		}
	}
	else
		CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CMy08StudyView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int delta = 0;
	if (pScrollBar != NULL)
	{
		if (pScrollBar->GetSafeHwnd() == m_vsb.GetSafeHwnd())
		{
			switch (nSBCode)
			{
			case SB_THUMBTRACK:
				pScrollBar->SetScrollPos(nPos);
				break;
			case SB_LINEUP:
				delta = -4;
				break;
			case SB_LINEDOWN:
				delta = +4;
				break;
			case SB_PAGEUP:
				delta = -20;
				break;
			case SB_PAGEDOWN:
				delta = +20;
				break;
			}

			if (delta != 0)
			{
				int pos = pScrollBar->GetScrollPos();
				pScrollBar->SetScrollPos(pos + delta);
			}

			Invalidate();
		}
	}
	else
		CFormView::OnVScroll(nSBCode, nPos, pScrollBar);

}


