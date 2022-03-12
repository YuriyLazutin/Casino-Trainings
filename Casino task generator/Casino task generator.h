// Casino task generator.h : main header file for the CASINO TASK GENERATOR application
//

#if !defined(AFX_CASINOTASKGENERATOR_H__5175A226_FE79_40F1_BD30_8B79D7CA9126__INCLUDED_)
#define AFX_CASINOTASKGENERATOR_H__5175A226_FE79_40F1_BD30_8B79D7CA9126__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCasinotaskgeneratorApp:
// See Casino task generator.cpp for the implementation of this class
//

class CCasinotaskgeneratorApp : public CWinApp
{
public:
	CCasinotaskgeneratorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCasinotaskgeneratorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCasinotaskgeneratorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CASINOTASKGENERATOR_H__5175A226_FE79_40F1_BD30_8B79D7CA9126__INCLUDED_)
