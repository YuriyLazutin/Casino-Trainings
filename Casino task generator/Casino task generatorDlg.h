// Casino task generatorDlg.h : header file
//

#if !defined(AFX_CASINOTASKGENERATORDLG_H__359C9AB2_E7EF_41FD_8CBA_C4CE1C622758__INCLUDED_)
#define AFX_CASINOTASKGENERATORDLG_H__359C9AB2_E7EF_41FD_8CBA_C4CE1C622758__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCasinotaskgeneratorDlg dialog

class CCasinotaskgeneratorDlg : public CDialog
{
// Construction
public:
	CCasinotaskgeneratorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCasinotaskgeneratorDlg)
	enum { IDD = IDD_CASINOTASKGENERATOR_DIALOG };
	BOOL	m_min;
	BOOL	m_sum;
	BOOL	m_mul;
	BOOL	m_div;
	UINT	m_tests;
	double	m_fmin;
	double	m_fmax;
	double	m_fstep;
	double	m_smin;
	double	m_smax;
	double	m_sstep;
	UINT	m_ffrac;
	UINT	m_sfrac;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCasinotaskgeneratorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCasinotaskgeneratorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCheck1();
	afx_msg void OnDoubleclickedCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnDoubleclickedCheck2();
	afx_msg void OnCheck3();
	afx_msg void OnDoubleclickedCheck3();
	afx_msg void OnCheck4();
	afx_msg void OnDoubleclickedCheck4();
	virtual void OnOK();
	afx_msg void OnDoubleclickedOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CASINOTASKGENERATORDLG_H__359C9AB2_E7EF_41FD_8CBA_C4CE1C622758__INCLUDED_)
