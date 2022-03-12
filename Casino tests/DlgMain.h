#if !defined(AFX_DLGMAIN_H__3F14B295_1942_4DDC_A8DB_04A3D432D217__INCLUDED_)
#define AFX_DLGMAIN_H__3F14B295_1942_4DDC_A8DB_04A3D432D217__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMain.h : header file
//
#include "DlgTime.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgMain

class CDlgMain : public CPropertySheet
{
	DECLARE_DYNAMIC(CDlgMain)

// Construction
public:
	CDlgMain(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CDlgMain(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMain)
	//}}AFX_VIRTUAL

// Implementation
public:
	CDlgTime * pT;
	virtual ~CDlgMain();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDlgMain)
		// NOTE - the ClassWizard will add and remove member functions here.
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMAIN_H__3F14B295_1942_4DDC_A8DB_04A3D432D217__INCLUDED_)
