#pragma once


// CMyDialog 대화 상자

class CMyDialog : public CDialog
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMyDialog();

	CComboBox m_combo;
	/* 실습 9-3
	CString m_str;
	int m_font;
	*/

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	// 실습 9-2
	//virtual BOOL OnInitDialog();
	//virtual void OnOK();
	afx_msg void OnBnClickedClear();
	CString m_str;
	int m_font;
};
