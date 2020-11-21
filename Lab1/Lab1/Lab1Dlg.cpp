
// Lab1Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Lab1.h"
#include "Lab1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLab1Dlg dialog



CLab1Dlg::CLab1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB1_DIALOG, pParent)
	, Nr(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Numar, Nr);
}

BEGIN_MESSAGE_MAP(CLab1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_Reset, &CLab1Dlg::OnBnClickedReset)

	ON_BN_CLICKED(IDC_Verifica, &CLab1Dlg::OnBnClickedVerifica)
END_MESSAGE_MAP()


// CLab1Dlg message handlers

BOOL CLab1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLab1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLab1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLab1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

bool isPrime(int n)
{
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)     
			return false;
	}

	return true;
}

int NextPrime(int n)
{
	int nextPrime = n;
	bool found = false;

	
	while (!found)
	{
		nextPrime++;
		if (isPrime(nextPrime))
			found = true;
	}

	return nextPrime;
}

int LastPrime(int n) {
	int lastPrime = n;
	bool found = false;
	while (!found)
	{
		lastPrime--;
		if (isPrime(lastPrime))
			found = true;
	}

	return lastPrime;
}

int SumaDivizori(int n) {
	int sum = 0;
	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0)
		{
			sum = sum + i;
		}
	return sum;
}


void CLab1Dlg::OnBnClickedReset(){
{
	Nr = 0;
	UpdateData(FALSE);
}}


void CLab1Dlg::OnBnClickedVerifica()
{
	UpdateData();
	CString text;
	int n;
	n = Nr;

	if(isPrime(n) == true)

		text.Format((LPCWSTR)L"Numarul %d este prim\nUrmatorul: %d\nAnteriorul: %d", n, NextPrime(n), LastPrime(n) );
		
	else
		text.Format((LPCWSTR)L"Numarul %d nu este prim\nSuma: %d\nUrmatorul: %d\nAnteriorul: %d", n , SumaDivizori(n), NextPrime(n), LastPrime(n));
	AfxMessageBox(text);
	
	UpdateData(FALSE);
}
