
// Lab2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Lab2.h"
#include "Lab2Dlg.h"
#include "afxdialogex.h"
#include "numeric"
#include "vector"

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
public:
	afx_msg void OnBnClickedCalculeazalista();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CalculeazaLista, &CAboutDlg::OnBnClickedCalculeazalista)
END_MESSAGE_MAP()


// CLab2Dlg dialog



CLab2Dlg::CLab2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB2_DIALOG, pParent)
	, A(0)
	, B(0)
	, cmmdc(0)
	, cmmmc(0)
	, ListaCMMMC(0)
	, nr(0)
	, ListaCMMDC(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_A, A);
	DDX_Text(pDX, IDC_B, B);
	DDX_Text(pDX, IDC_CMMDC, cmmdc);
	DDX_Text(pDX, IDC_CMMMC, cmmmc);
	DDX_Text(pDX, IDC_ListaCMMMC, ListaCMMMC);
	DDX_Text(pDX, IDC_ListNr, nr);
	DDX_Text(pDX, IDC_ListCMMDC, ListaCMMDC);
}

BEGIN_MESSAGE_MAP(CLab2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Calculeaza, &CLab2Dlg::OnBnClickedCalculeaza)
	ON_BN_CLICKED(IDC_CalculeazaLista2, &CLab2Dlg::OnBnClickedCalculeazalista2)
	
	ON_BN_CLICKED(IDC_Reset, &CLab2Dlg::OnBnClickedReset)
	
	
END_MESSAGE_MAP()


// CLab2Dlg message handlers

BOOL CLab2Dlg::OnInitDialog()
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

void CLab2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLab2Dlg::OnPaint()
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
HCURSOR CLab2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLab2Dlg::OnBnClickedCalculeaza()
{
	UpdateData(TRUE);
	CString text;
	int x, y, r;
	x = A;
	y = B;
	if (x == y && y == 0)
	{
		AfxMessageBox((LPCWSTR)L"A și B nu pot fi simultan nule!");
		return;
	}

	if (y != 0)
		do
		{

			r = x % y;

			x = y;
			y = r;
		} while (r != 0);
		cmmdc = x;
		cmmmc = A * B / cmmdc;
		text.Format((LPCWSTR)L"Fractia redusa: %d/%d", A / x, B / x);
		AfxMessageBox(text);
		UpdateData(FALSE);
}






void CLab2Dlg::OnBnClickedReset()
{
	A = B = cmmdc = cmmmc = ListaCMMDC = ListaCMMMC = 0;
	Lista = "";
	UpdateData(FALSE);
}



int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

 int findlcm(std::vector<int> myvector, int n)
{
	// Initialize result 
	int ans = myvector[0];

	// ans contains LCM of arr[0], ..arr[i] 
	// after i'th iteration, 
	for (int i = 1; i < n; i++)
		ans = (((myvector[i] * ans)) /
			(gcd(myvector[i], ans)));

	return ans;
}



void CLab2Dlg::OnBnClickedCalculeazalista2()
{
	UpdateData(TRUE);
	std::vector<int> myvector;
	int number= nr;

	myvector.push_back(number);

	int size = myvector.size();

	int n = sizeof(myvector) / sizeof(myvector[0]);

	ListaCMMMC = findlcm(myvector, n);
	UpdateData(FALSE);
}
