
// lab3Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "lab3.h"
#include "lab3Dlg.h"
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


// Clab3Dlg dialog



Clab3Dlg::Clab3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB3_DIALOG, pParent)
	, A(0)
	, B(0)
	, OPERATIE(0)
	, Rezultat(0)
	, Text(_T(""))
	, C(0)
	, D(0)
	, Rezultat2(0)
	, Text2(_T(""))
	, X(0)
	, Y(0)
	, MOD(0)
	, Rezultat3(0)
	, Text3(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clab3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_A, A);
	DDX_Text(pDX, IDC_B, B);
	DDX_Radio(pDX, IDC_OPERATIE1, OPERATIE);
	DDX_Text(pDX, IDC_REZULTAT, Rezultat);
	DDX_Text(pDX, IDC_STATIC1, Text);
	DDX_Text(pDX, IDC_C, C);
	DDX_Text(pDX, IDC_D, D);
	DDX_Text(pDX, IDC_REZULTAT2, Rezultat2);
	DDX_Text(pDX, IDC_STATIC2, Text2);
	DDX_Text(pDX, IDC_X, X);
	DDX_Text(pDX, IDC_Y, Y);
	DDX_Text(pDX, IDC_MOD, MOD);
	DDX_Text(pDX, IDC_REZULTAT3, Rezultat3);
	DDX_Text(pDX, IDC_STATIC3, Text3);
}

BEGIN_MESSAGE_MAP(Clab3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CALCULEAZA, &Clab3Dlg::OnBnClickedCalculeaza)
	ON_BN_CLICKED(IDC_RESET, &Clab3Dlg::OnBnClickedReset)
END_MESSAGE_MAP()


// Clab3Dlg message handlers

BOOL Clab3Dlg::OnInitDialog()
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

void Clab3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Clab3Dlg::OnPaint()
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
HCURSOR Clab3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Clab3Dlg::OnBnClickedCalculeaza()
{
	UpdateData();
	switch (OPERATIE) {
	case 0:

		Rezultat = A + B;
		Rezultat2 = C + D;
		Rezultat3 = (X + Y) % MOD;
		Text = "A+B=";
		Text2 = "C+D=";
		Text3 = "(X+Y)%N=";
		break;

	case 1:
		Rezultat = A - B;
		Text = "A-B=";
		Rezultat2 = C - D;
		Text2 = "C-D=";
		break;
	case 2:
		Rezultat = A * B;
		Text = "A*B=";
		Rezultat2 = C * D;
		Text2 = "C*D=";
		Rezultat3 = (X * Y) % MOD;
		Text3 = "(X*Y)%N=";
		break;
	case 3:
		if (!B)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat = (double)A / B;
		Text = "A/B=";

		if (!D)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat2 = C / D;
		Text2 = "C/D=";
		break;

	case 4:
		if (!B)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat = (double)A / B - A / B;
		Text = "{A/B}=";

		if (!C)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat2 = (C / D) - floor(C / D);
		Text2 = "{C/D}=";
		break;
	case 5:
		if (!B)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat = A / B;
		Text = "[A/B]=";

		if (!D)
		{
			AfxMessageBox((LPCWSTR)L"Impartire la 0!");
			return;
		}
		Rezultat2 = int(C / D);
		Text2 = "[C/D]=";
		break;
	case 6:
		Rezultat = A % B;
		Text = "A%B=";

		double mod;
		// Handling negative values 
		if (C < 0)
			mod = -C;
		else
			mod = C;
		if (D < 0)
			D = -D;

		// Finding mod by repeated subtraction 

		while (mod >= D)
			mod = mod - D;

		// Sign of result typically depends 
		// on sign of a. 
		if (C < 0)
			mod = -mod;

		Rezultat2 = mod;
		Text2 = "A%B=";
		break;

	default: AfxMessageBox((LPCWSTR)L"Nu s-a optat pentru o operatie");
	}
	UpdateData(FALSE);
}


void Clab3Dlg::OnBnClickedReset()
{
	A = B = 0;
	UpdateData(FALSE);

}
