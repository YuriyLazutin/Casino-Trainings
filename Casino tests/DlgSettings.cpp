// DlgSettings.cpp : implementation file
//

#include "stdafx.h"
#include "Casino tests.h"
#include "DlgSettings.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSettings property page

IMPLEMENT_DYNCREATE(CDlgSettings, CPropertyPage)

CDlgSettings::CDlgSettings() : CPropertyPage(CDlgSettings::IDD)
{
	//{{AFX_DATA_INIT(CDlgSettings)
	m_sum = FALSE;
	m_min = FALSE;
	m_mul = TRUE;
	m_div = FALSE;
	m_fmin = 0.0;
	m_fmax = 100.0;
	m_fstep = 1.0;
	m_smin = 0.0;
	m_smax = 100.0;
	m_sstep = 1.0;
	m_ffrac = 0;
	m_sfrac = 0;
	//}}AFX_DATA_INIT
}

CDlgSettings::~CDlgSettings()
{
}

void CDlgSettings::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSettings)
	DDX_Check(pDX, IDC_CHECK1, m_sum);
	DDX_Check(pDX, IDC_CHECK2, m_min);
	DDX_Check(pDX, IDC_CHECK3, m_mul);
	DDX_Check(pDX, IDC_CHECK4, m_div);
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


BEGIN_MESSAGE_MAP(CDlgSettings, CPropertyPage)
	//{{AFX_MSG_MAP(CDlgSettings)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_DOUBLECLICKED(IDC_CHECK1, OnDoubleclickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_BN_DOUBLECLICKED(IDC_CHECK2, OnDoubleclickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_BN_DOUBLECLICKED(IDC_CHECK3, OnDoubleclickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	ON_BN_DOUBLECLICKED(IDC_CHECK4, OnDoubleclickedCheck4)
	ON_BN_DOUBLECLICKED(IDOK, OnDoubleclickedOk)
	ON_BN_DOUBLECLICKED(IDCANCEL, OnDoubleclickedCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSettings message handlers

void CDlgSettings::OnCheck1() 
{
	// TODO: Add your control notification handler code here
	m_sum = TRUE;
	m_min = FALSE;
	m_mul = FALSE;
	m_div = FALSE;
	UpdateData(FALSE);
}

void CDlgSettings::OnDoubleclickedCheck1() 
{
	// TODO: Add your control notification handler code here
	OnCheck1();
}

void CDlgSettings::OnCheck2() 
{
	// TODO: Add your control notification handler code here
	m_sum = FALSE;
	m_min = TRUE;
	m_mul = FALSE;
	m_div = FALSE;
	UpdateData(FALSE);
}

void CDlgSettings::OnDoubleclickedCheck2() 
{
	// TODO: Add your control notification handler code here
	OnCheck2();
}

void CDlgSettings::OnCheck3() 
{
	// TODO: Add your control notification handler code here
	m_sum = FALSE;
	m_min = FALSE;
	m_mul = TRUE;
	m_div = FALSE;
	UpdateData(FALSE);
}

void CDlgSettings::OnDoubleclickedCheck3() 
{
	// TODO: Add your control notification handler code here
	OnCheck3();
}

void CDlgSettings::OnCheck4() 
{
	// TODO: Add your control notification handler code here
	m_sum = FALSE;
	m_min = FALSE;
	m_mul = FALSE;
	m_div = TRUE;
	UpdateData(FALSE);
}

void CDlgSettings::OnDoubleclickedCheck4() 
{
	// TODO: Add your control notification handler code here
	OnCheck4();
}


void CDlgSettings::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	CPropertyPage::OnOK();
}

void CDlgSettings::OnDoubleclickedOk() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CDlgSettings::OnCancel() 
{
	// TODO: Add extra cleanup here
	UpdateData(FALSE);
	CPropertyPage::OnCancel();
}

void CDlgSettings::OnDoubleclickedCancel() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}
