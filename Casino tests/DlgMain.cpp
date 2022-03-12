// DlgMain.cpp : implementation file
//

#include "stdafx.h"
#include "Casino tests.h"
#include "DlgMain.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMain

IMPLEMENT_DYNAMIC(CDlgMain, CPropertySheet)

CDlgMain::CDlgMain(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CDlgMain::CDlgMain(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
}

CDlgMain::~CDlgMain()
{
}


BEGIN_MESSAGE_MAP(CDlgMain, CPropertySheet)
	//{{AFX_MSG_MAP(CDlgMain)
	ON_COMMAND(IDOK, OnOK)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMain message handlers

void CDlgMain::OnOK() 
{
	// TODO: Add extra validation here
	pT->PushOK();
	//CPropertySheet::OnOK();
}
