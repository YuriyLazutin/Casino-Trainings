// Casino tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Casino tests.h"
#include "DlgTime.h"
#include "DlgSettings.h"
#include "DlgMain.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		// TODO: Add your command handler code here
		CDlgMain PropSheet("");
		CDlgTime p1;
		CDlgSettings p3;
		p1.pS = &p3;
		PropSheet.pT= &p1;
			
		PropSheet.AddPage(&p1);
		PropSheet.AddPage(&p3);

		PropSheet.SetTitle("Тестировщик крупье.");
		PropSheet.DoModal();

	}

	return nRetCode;
}


