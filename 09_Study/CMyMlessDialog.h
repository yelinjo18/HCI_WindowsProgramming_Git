#pragma once


// CMyMlessDialog 대화 상자
class CMy09StudyView;

class CMyMlessDialog : public CDialog
{
	DECLARE_DYNAMIC(CMyMlessDialog)

public:
	CMyMlessDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMyMlessDialog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CMy09StudyView* m_pView;
	CString m_str;
	int m_font;
	afx_msg void OnBnClickedApply();
	virtual void OnCancel();
	virtual void PostNcDestroy();
};
