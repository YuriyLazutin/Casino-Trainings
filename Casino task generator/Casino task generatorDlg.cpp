// Casino task generatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Casino task generator.h"
#include "Casino task generatorDlg.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCasinotaskgeneratorDlg dialog

CCasinotaskgeneratorDlg::CCasinotaskgeneratorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCasinotaskgeneratorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCasinotaskgeneratorDlg)
	m_min = FALSE;
	m_sum = FALSE;
	m_mul = TRUE;
	m_div = FALSE;
	m_tests = 1000;
	m_fmin = 0.0;
	m_fmax = 100.0;
	m_fstep = 1.0;
	m_smin = 0.0;
	m_smax = 100.0;
	m_sstep = 1.0;
	m_ffrac = 0;
	m_sfrac = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCasinotaskgeneratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCasinotaskgeneratorDlg)
	DDX_Check(pDX, IDC_CHECK2, m_min);
	DDX_Check(pDX, IDC_CHECK1, m_sum);
	DDX_Check(pDX, IDC_CHECK3, m_mul);
	DDX_Check(pDX, IDC_CHECK4, m_div);
	DDX_Text(pDX, IDC_EDIT7, m_tests);
	DDV_MinMaxUInt(pDX, m_tests, 1, 50000);
	DDX_Text(pDX, IDC_EDIT1, m_fmin);
	DDX_Text(pDX, IDC_EDIT2, m_fmax);
	DDX_Text(pDX, IDC_EDIT3, m_fstep);
	DDX_Text(pDX, IDC_EDIT4, m_smin);
	DDX_Text(pDX, IDC_EDIT5, m_smax);
	DDX_Text(pDX, IDC_EDIT6, m_sstep);
	DDX_Text(pDX, IDC_EDIT8, m_ffrac);
	DDV_MinMaxUInt(pDX, m_ffrac, 0, 3);
	DDX_Text(pDX, IDC_EDIT9, m_sfrac);
	DDV_MinMaxUInt(pDX, m_sfrac, 0, 3);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCasinotaskgeneratorDlg, CDialog)
	//{{AFX_MSG_MAP(CCasinotaskgeneratorDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_DOUBLECLICKED(IDC_CHECK1, OnDoubleclickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_BN_DOUBLECLICKED(IDC_CHECK2, OnDoubleclickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_BN_DOUBLECLICKED(IDC_CHECK3, OnDoubleclickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	ON_BN_DOUBLECLICKED(IDC_CHECK4, OnDoubleclickedCheck4)
	ON_BN_DOUBLECLICKED(IDOK, OnDoubleclickedOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCasinotaskgeneratorDlg message handlers

BOOL CCasinotaskgeneratorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	//UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCasinotaskgeneratorDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCasinotaskgeneratorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCasinotaskgeneratorDlg::OnCheck1() 
{
	// TODO: Add your control notification handler code here
	m_sum = TRUE;
	m_min = FALSE;
	m_mul = FALSE;
	m_div = FALSE;
	UpdateData(FALSE);
}

void CCasinotaskgeneratorDlg::OnDoubleclickedCheck1() 
{
	// TODO: Add your control notification handler code here
	OnCheck1();
}

void CCasinotaskgeneratorDlg::OnCheck2() 
{
	// TODO: Add your control notification handler code here
	m_sum = FALSE;
	m_min = TRUE;
	m_mul = FALSE;
	m_div = FALSE;
	UpdateData(FALSE);
}

void CCasinotaskgeneratorDlg::OnDoubleclickedCheck2() 
{
	// TODO: Add your control notification handler code here
	OnCheck2();
}

void CCasinotaskgeneratorDlg::OnCheck3() 
{
	// TODO: Add your control notification handler code here
	m_sum = FALSE;
	m_min = FALSE;
	m_mul = TRUE;
	m_div = FALSE;
	UpdateData(FALSE);
}

void CCasinotaskgeneratorDlg::OnDoubleclickedCheck3() 
{
	// TODO: Add your control notification handler code here
	OnCheck3();
}

void CCasinotaskgeneratorDlg::OnCheck4() 
{
	// TODO: Add your control notification handler code here
	m_sum = FALSE;
	m_min = FALSE;
	m_mul = FALSE;
	m_div = TRUE;
	UpdateData(FALSE);
}

void CCasinotaskgeneratorDlg::OnDoubleclickedCheck4() 
{
	// TODO: Add your control notification handler code here
	OnCheck4();
}

void CCasinotaskgeneratorDlg::OnOK() 
{
	UpdateData();
	// TODO: Add extra validation here
	CFile task, solution;
	CString taskfn, solutionfn;
	CFileException fEx;	
	BOOL bOpenOK;
	CFileStatus status;

	taskfn = _T("T:\\task.csv");

	// Open file for task
	if( CFile::GetStatus(taskfn , status ) )
	{
		// Open the file without the Create flag
		bOpenOK = task.Open( taskfn, CFile::modeReadWrite, &fEx );
	}
	else
	{
		// Open the file with the Create flag
		bOpenOK = task.Open( taskfn, CFile::modeCreate | CFile::modeWrite, &fEx );
	}

	if ( !bOpenOK )
	{
		TRACE( "Can't open file %s, error = %u\n", taskfn, fEx.m_cause );
	}
	
	solutionfn = _T("T:\\solution.csv");
	
	// Open file for solution
	if( CFile::GetStatus(solutionfn , status ) )
	{
		// Open the file without the Create flag
		bOpenOK = solution.Open( solutionfn, CFile::modeReadWrite, &fEx );
	}
	else
	{
		// Open the file with the Create flag
		bOpenOK = solution.Open( solutionfn, CFile::modeCreate | CFile::modeWrite, &fEx );
	}

	if ( !bOpenOK )
	{
		TRACE( "Can't open file %s, error = %u\n", solutionfn, fEx.m_cause );
	}

	try
	{
		task.Seek( 0, CFile::begin );
		task.SetLength(0);
	}
	catch(CFileException *fe)
	{
		fe->Delete();
	}

	try
	{
		solution.Seek( 0, CFile::begin );
		solution.SetLength(0);
	}
	catch(CFileException *fe)
	{
		fe->Delete();
	}

	CString tsk, sol, tmp, op;
	int f=0;
	double n1, n2;
	if (m_sum) op = _T(" + ");
	else if (m_min) op = _T(" - ");
	else if (m_mul) op = _T(" * ");
	else op = _T(" / ");
	
	/* Seed the random-number generator with current time so that
    * the numbers will be different every time we run.
    */
   srand( (unsigned)time( NULL ) );
   char buf[64];

	for (UINT i = 0; i < m_tests; i++)
	{
		tsk = ""; sol = "";
		// Генерируем первое число
		tmp.Format("%.0f",((double)rand()/RAND_MAX)*((m_fmax-m_fmin)/m_fstep));
		strcpy(buf,tmp);
		
		switch (m_ffrac)
		{
			case 1:
				tmp.Format("%.1f",m_fmin+atoi(buf)*m_fstep);
				break;
			case 2:
				tmp.Format("%.2f",m_fmin+atoi(buf)*m_fstep);
				break;
			case 3:
				tmp.Format("%.3f",m_fmin+atoi(buf)*m_fstep);
				break;
			default:
				tmp.Format("%.0f",m_fmin+atoi(buf)*m_fstep);
		}
		
		tsk += tmp+","+op+",";
		sol += tmp+","+op+",";

		strcpy(buf,tmp);
		n1 = atof(buf);

		// Генерируем второе число
		tmp.Format("%.0f",((double)rand()/RAND_MAX)*((m_smax-m_smin)/m_sstep));
		strcpy(buf,tmp);
		
		switch (m_sfrac)
		{
			case 1:
				tmp.Format("%.1f",m_smin+atoi(buf)*m_sstep);
				break;
			case 2:
				tmp.Format("%.2f",m_smin+atoi(buf)*m_sstep);
				break;
			case 3:
				tmp.Format("%.3f",m_smin+atoi(buf)*m_sstep);
				break;
			default:
				tmp.Format("%.0f",m_smin+atoi(buf)*m_sstep);
		}
		
		tsk += tmp+","+" = ,,";
		sol += tmp+","+" = ,";
		strcpy(buf,tmp);
		n2 = atof(buf);
		
		if (m_sum) tmp.Format("%f,", n1+n2);
		else if (m_min) tmp.Format("%f,", n1-n2);
			else if (m_mul) tmp.Format("%f,", n1*n2);
			else if (m_div && n2 != 0) tmp.Format("%f,", n1/n2);
			else tmp = "неопр.,";
		sol += tmp;
		
		f++;
		if (f == 3)
		{ 
			tmp.Format("\n");
			tsk += tmp;
			sol += tmp;
			f = 0;
		}
		else
		{
			tsk += ",";
			sol += ",";
		}

		try
		{
			task.Write(tsk, tsk.GetLength());
		}
		catch(CFileException *fe)
		{
			fe->Delete();
		}
		
		try
		{
			solution.Write(sol, sol.GetLength());
		}
		catch(CFileException *fe)
		{
			fe->Delete();
		}
	}


	task.Close();
	solution.Close();

	CDialog::OnOK();
}

void CCasinotaskgeneratorDlg::OnDoubleclickedOk() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}
