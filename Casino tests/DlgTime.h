#if !defined(AFX_DLGTIME_H__76BAEF0B_9A2A_4C78_B6AF_7F97C3231B93__INCLUDED_)
#define AFX_DLGTIME_H__76BAEF0B_9A2A_4C78_B6AF_7F97C3231B93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgTime.h : header file
//
#include "DlgSettings.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgTime dialog

class CDlgTime : public CPropertyPage
{
	DECLARE_DYNCREATE(CDlgTime)

// Construction
public:
	CString tmpSol;
	CString tmpTask;
	void PushOK();
	COleDateTime paused_time;
	COleDateTime begin_time;
	BOOL IsRunF;
	CString m_rez;
	void GenTask();
	BOOL IsRun;
	CDlgSettings * pS;
	CDlgTime();
	~CDlgTime();

	long seconds;
	double avg_task;
	COleDateTime avg_time;
	int good_task;
	COleDateTime last_time;
	int total_task;
	COleDateTime total_time;

// Dialog Data
	//{{AFX_DATA(CDlgTime)
	enum { IDD = IDD_DLG_TIME };
	CEdit	m_sol_ctr;
	CButton	m_btn_OK;
	CButton	m_btn_pause;
	CString	m_avg_task;
	CString	m_avg_time;
	CString	m_good_task;
	CString	m_last_time;
	CString	m_solution;
	CString	m_task;
	CString	m_total_task;
	CString	m_total_time;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDlgTime)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDlgTime)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnPause();
	afx_msg void OnDoubleclickedBtnPause();
	virtual void OnOK();
	afx_msg void OnDoubleclickedOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTIME_H__76BAEF0B_9A2A_4C78_B6AF_7F97C3231B93__INCLUDED_)
