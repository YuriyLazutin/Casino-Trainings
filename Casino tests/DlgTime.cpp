// DlgTime.cpp : implementation file
//

#include "stdafx.h"
#include "Casino tests.h"
#include "DlgTime.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgTime property page

IMPLEMENT_DYNCREATE(CDlgTime, CPropertyPage)

CDlgTime::CDlgTime() : CPropertyPage(CDlgTime::IDD)
{
	//{{AFX_DATA_INIT(CDlgTime)
	m_avg_task = _T("100 %");
	m_avg_time = _T("0");
	m_good_task = _T("0");
	m_last_time = _T("0");
	m_solution = _T("");
	m_task = _T("");
	m_total_task = _T("0");
	m_total_time = _T("0");
	//}}AFX_DATA_INIT
	avg_task = 100;
	avg_time.SetTime(0,0,0);
	good_task = 0;
	last_time.SetTime(0,0,0);
	total_task = 0;
	total_time.SetTime(0,0,0);
	begin_time.SetTime(0,0,0);
	paused_time.SetTime(0,0,0);
	IsRun = FALSE;
	IsRunF = FALSE;
}

CDlgTime::~CDlgTime()
{
}

void CDlgTime::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgTime)
	DDX_Control(pDX, IDC_SOLUTION, m_sol_ctr);
	DDX_Control(pDX, IDOK, m_btn_OK);
	DDX_Control(pDX, IDC_BTN_PAUSE, m_btn_pause);
	DDX_Text(pDX, IDC_AVG_TASK, m_avg_task);
	DDX_Text(pDX, IDC_AVG_TIME, m_avg_time);
	DDX_Text(pDX, IDC_GOOD_TASK, m_good_task);
	DDX_Text(pDX, IDC_LAST_TIME, m_last_time);
	DDX_Text(pDX, IDC_SOLUTION, m_solution);
	DDX_Text(pDX, IDC_TASK, m_task);
	DDX_Text(pDX, IDC_TOTAL_TASK, m_total_task);
	DDX_Text(pDX, IDC_TOTAL_TIME, m_total_time);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgTime, CPropertyPage)
	//{{AFX_MSG_MAP(CDlgTime)
	ON_BN_CLICKED(IDC_BTN_PAUSE, OnBtnPause)
	ON_BN_DOUBLECLICKED(IDC_BTN_PAUSE, OnDoubleclickedBtnPause)
	ON_BN_DOUBLECLICKED(IDOK, OnDoubleclickedOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgTime message handlers

BOOL CDlgTime::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	/* Seed the random-number generator with current time so that
    * the numbers will be different every time we run.
    */
    srand( (unsigned)time( NULL ) );

	if (IsRun)
	{
		m_btn_pause.SetWindowText("Пауза");
		m_btn_OK.EnableWindow(TRUE);
	}
	else
	{
		m_btn_pause.SetWindowText("Старт");
		m_btn_OK.EnableWindow(FALSE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgTime::OnBtnPause() 
{
	UpdateData();
	// TODO: Add your control notification handler code here
	if (IsRun)
	{
		last_time += COleDateTime::GetCurrentTime() - paused_time;
		tmpTask = m_task;
		tmpSol = m_solution;
		m_task = m_solution = "";
		m_btn_pause.SetWindowText("Старт");
		IsRun = FALSE;
		IsRunF = TRUE; // Поставили на паузу уже запущенную программу
		m_btn_OK.EnableWindow(FALSE);
	}
	else // Запускаются вычисления
	{
		m_btn_pause.SetWindowText("Пауза");
		IsRun = TRUE;
		m_btn_OK.EnableWindow(TRUE);
		if (!IsRunF)
		{
			// Запустили программу в первый раз
			total_task--;
			GenTask();
			begin_time = COleDateTime::GetCurrentTime();
			paused_time = begin_time;
			last_time.SetTime(0,0,0); 
			
		}
		else
		{
			// Сняли программу с паузы, нужно восстановить пример
			m_task = tmpTask;
			m_solution = tmpSol;

			// И запустить время
			paused_time = COleDateTime::GetCurrentTime();
		}
	}
	UpdateData(FALSE);
}

void CDlgTime::OnDoubleclickedBtnPause() 
{
	// TODO: Add your control notification handler code here
	OnBtnPause();
}

void CDlgTime::GenTask()
{
	UpdateData();
	CString tmp, op;
	double n1, n2;

	total_task++;
	m_total_task.Format("%d",total_task);

	if (pS->m_sum) op = _T(" + ");
	else if (pS->m_min) op = _T(" - ");
	else if (pS->m_mul) op = _T(" * ");
	else op = _T(" / ");
		
    char buf[64];

	m_task = ""; 
		 
	tmp.Format("%.0f",((double)rand()/RAND_MAX)*((pS->m_fmax-pS->m_fmin)/pS->m_fstep));
	strcpy(buf,tmp);
		
	switch (pS->m_ffrac)
	{
		case 1:
			tmp.Format("%.1f",pS->m_fmin+atoi(buf)*pS->m_fstep);
			break;
		case 2:
			tmp.Format("%.2f",pS->m_fmin+atoi(buf)*pS->m_fstep);
			break;
		case 3:
			tmp.Format("%.3f",pS->m_fmin+atoi(buf)*pS->m_fstep);
			break;
		default:
			tmp.Format("%.0f",pS->m_fmin+atoi(buf)*pS->m_fstep);
	}
		
	m_task += tmp+op;
	
	strcpy(buf,tmp);
	n1 = atof(buf);

	
	tmp.Format("%.0f",((double)rand()/RAND_MAX)*((pS->m_smax-pS->m_smin)/pS->m_sstep));
	strcpy(buf,tmp);
		
	switch (pS->m_sfrac)
	{
		case 1:
			tmp.Format("%.1f",pS->m_smin+atoi(buf)*pS->m_sstep);
			break;
		case 2:
			tmp.Format("%.2f",pS->m_smin+atoi(buf)*pS->m_sstep);
			break;
		case 3:
			tmp.Format("%.3f",pS->m_smin+atoi(buf)*pS->m_sstep);
			break;
		default:
			tmp.Format("%.0f",pS->m_smin+atoi(buf)*pS->m_sstep);
	}
		
	m_task += tmp;
	strcpy(buf,tmp);
	n2 = atof(buf);
		
	if (pS->m_sum) tmp.Format("%f", n1+n2);
	else if (pS->m_min) tmp.Format("%f", n1-n2);
	else if (pS->m_mul) tmp.Format("%f", n1*n2);
	else if (pS->m_div && n2 != 0) tmp.Format("%f", n1/n2);
	else tmp = "Х";
	m_rez = tmp;
	UpdateData(FALSE);
}

void CDlgTime::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	// Остановить время
	last_time += COleDateTime::GetCurrentTime() - paused_time;
	total_time = total_time + last_time;	
	m_total_time.Format("%d ч. %d мин. %d сек.", total_time.GetHour(), total_time.GetMinute(), total_time.GetSecond());
	m_last_time.Format("%d ч. %d мин. %d сек.", last_time.GetHour(), last_time.GetMinute(), last_time.GetSecond());
	last_time.SetTime(0,0,0);
	seconds = 3600*total_time.GetHour() + 60*total_time.GetMinute() + total_time.GetSecond();
	m_avg_time.Format("%.2f сек.", (double)seconds/(total_task+1));

	// Проверить ответ пользователя
	char buf[64], rez[64];
	strcpy(buf,m_solution);
	strcpy(rez,m_rez);
	
	if (atof(buf) != atof(rez))
	{
		// Ответ неверный
		AfxMessageBox("Неправильный ответ! Будь внимательней!", MB_ICONSTOP);
	}
	else
	{
		// Ответ правильный
		good_task++;
		m_good_task.Format("%d",good_task);
	}
	
	avg_task = ((double)good_task/(total_task+1))*100;
	m_avg_task.Format("%.2f %%",avg_task);

	// Удалить старый ответ пользователя и установить курсор
	m_solution = "";
	m_sol_ctr.SetFocus();
	
	UpdateData(FALSE);
	// Создать новый пример
	GenTask();
	
	// Запустить время
	begin_time = COleDateTime::GetCurrentTime();
	paused_time = begin_time;
	
	CPropertyPage::OnOK();
}

void CDlgTime::OnDoubleclickedOk() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CDlgTime::PushOK()
{
	OnOK();
}
