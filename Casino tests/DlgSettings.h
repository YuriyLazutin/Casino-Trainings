#if !defined(AFX_DLGSETTINGS_H__DF467F11_4593_40BC_9C8E_099715E77AB3__INCLUDED_)
#define AFX_DLGSETTINGS_H__DF467F11_4593_40BC_9C8E_099715E77AB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSettings.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSettings dialog

class CDlgSettings : public CPropertyPage
{
	DECLARE_DYNCREATE(CDlgSettings)

// Construction
public:
	CDlgSettings();
	~CDlgSettings();

// Dialog Data
	//{{AFX_DATA(CDlgSettings)
	enum { IDD = IDD_DIALOG_SETTINGS };
	BOOL	m_sum;
	BOOL	m_min;
	BOOL	m_mul;
	BOOL	m_div;
	double	m_fmin;
	double	m_fmax;
	double	m_fstep;
	double	m_smin;
	double	m_smax;
	double	m_sstep;
	UINT	m_ffrac;
	UINT	m_sfrac;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDlgSettings)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDlgSettings)
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
	virtual void OnCancel();
	afx_msg void OnDoubleclickedCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSETTINGS_H__DF467F11_4593_40BC_9C8E_099715E77AB3__INCLUDED_)
