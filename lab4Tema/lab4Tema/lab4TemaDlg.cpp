
// lab4TemaDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "lab4Tema.h"
#include "lab4TemaDlg.h"
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


// Clab4TemaDlg dialog



Clab4TemaDlg::Clab4TemaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB4TEMA_DIALOG, pParent)
	, Reducere(FALSE)
	, Pret(0)
	, Total(0)
	, Calitate(0)
	, Tip(0)
	, GET(0)
	, Numar(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clab4TemaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, Lista);
	DDX_Control(pDX, IDC_COMBO, Zile);
	DDX_Check(pDX, IDC_REDUCERE, Reducere);
	DDX_Text(pDX, IDC_PRET, Pret);
	DDX_Text(pDX, IDC_TOTAL, Total);
	DDX_Radio(pDX, IDC_Calitate1, Calitate);
	DDX_Radio(pDX, IDC_TIP1, Tip);
	DDX_Text(pDX, IDC_GET, GET);
	DDX_Text(pDX, IDC_Numar, Numar);
}

BEGIN_MESSAGE_MAP(Clab4TemaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CALCULEAZA, &Clab4TemaDlg::OnBnClickedCalculeaza)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST, &Clab4TemaDlg::OnLvnItemchangedList)
END_MESSAGE_MAP()


// Clab4TemaDlg message handlers

BOOL Clab4TemaDlg::OnInitDialog()
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
	CRect rect;
	Lista.GetClientRect(&rect);
	int nColInterval = rect.Width() / 5;

	Lista.InsertColumn(0, _T("Titlu"), LVCFMT_LEFT, nColInterval * 3);
	Lista.InsertColumn(1, _T("Anul"), LVCFMT_LEFT, nColInterval);
	Lista.InsertColumn(2, _T("Durata"), LVCFMT_LEFT, rect.Width() - 4 * nColInterval);

	LVITEM lvi;
	CString strItem;

	// Inserare subitem0 (titlu) -> primul DVD
	lvi.mask = LVIF_IMAGE | LVIF_TEXT;
	strItem.Format(_T("Arizona Dream"));
	lvi.iItem = 0;
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.InsertItem(&lvi);
	// Setare subitem1 (anul) -> primul DVD
	strItem.Format(_T("1992"));
	lvi.iSubItem = 1;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);
	// Setare subitem2 (Durata) -> primul DVD
	strItem.Format(_T("142 min"));
	lvi.iSubItem = 2;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);

	// Inserare subitem0 -> al II-lea DVD
	lvi.mask = LVIF_IMAGE | LVIF_TEXT;
	strItem.Format(_T("Matrix"));
	lvi.iItem = 1;
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.InsertItem(&lvi);
	// Setare subitem1 -> al II-lea DVD
	strItem.Format(_T("1999"));
	lvi.iSubItem = 1;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);
	// Settare subitem2 -> al II-lea DVD
	strItem.Format(_T("136 min"));
	lvi.iSubItem = 2;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);

	//Inserare subitem0 -> al III-lea DVD	
	lvi.mask = LVIF_IMAGE | LVIF_TEXT;
	strItem.Format(_T("Al saselea simt"));
	lvi.iItem = 2;
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.InsertItem(&lvi);
	// Setare subitem1
	strItem.Format(_T("1999"));
	lvi.iSubItem = 1;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);
	// Setare subitem2
	strItem.Format(_T("106 min"));
	lvi.iSubItem = 2;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);

	//Inserare subitem0 -> al IV-lea DVD	
	lvi.mask = LVIF_IMAGE | LVIF_TEXT;
	strItem.Format(_T("Winx"));
	lvi.iItem = 2;
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.InsertItem(&lvi);
	// Setare subitem1
	strItem.Format(_T("2004"));
	lvi.iSubItem = 1;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);
	// Setare subitem2
	strItem.Format(_T("133 episoade"));
	lvi.iSubItem = 2;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);

	//Inserare subitem0 -> al V-lea DVD	
	lvi.mask = LVIF_IMAGE | LVIF_TEXT;
	strItem.Format(_T("H2O"));
	lvi.iItem = 2;
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.InsertItem(&lvi);
	// Setare subitem1
	strItem.Format(_T("2002"));
	lvi.iSubItem = 1;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);
	// Setare subitem2
	strItem.Format(_T("113 min"));
	lvi.iSubItem = 2;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);

	//Inserare subitem0 -> al VI-lea DVD	
	lvi.mask = LVIF_IMAGE | LVIF_TEXT;
	strItem.Format(_T("Spiderman"));
	lvi.iItem = 2;
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.InsertItem(&lvi);
	// Setare subitem1
	strItem.Format(_T("2012"));
	lvi.iSubItem = 1;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);
	// Setare subitem2
	strItem.Format(_T("136"));
	lvi.iSubItem = 2;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);

	//Inserare subitem0 -> al VII-lea DVD	
	lvi.mask = LVIF_IMAGE | LVIF_TEXT;
	strItem.Format(_T("Mumia"));
	lvi.iItem = 2;
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.InsertItem(&lvi);
	// Setare subitem1
	strItem.Format(_T("1999"));
	lvi.iSubItem = 1;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);
	// Setare subitem2
	strItem.Format(_T("125 min"));
	lvi.iSubItem = 2;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);

	//Inserare subitem0 -> al VIII-lea DVD	
	lvi.mask = LVIF_IMAGE | LVIF_TEXT;
	strItem.Format(_T("24"));
	lvi.iItem = 2;
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.InsertItem(&lvi);
	// Setare subitem1
	strItem.Format(_T("2008"));
	lvi.iSubItem = 1;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);
	// Setare subitem2
	strItem.Format(_T("84 min"));
	lvi.iSubItem = 2;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);

	//Inserare subitem0 -> al IX-lea DVD	
	lvi.mask = LVIF_IMAGE | LVIF_TEXT;
	strItem.Format(_T("Stargate"));
	lvi.iItem = 2;
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.InsertItem(&lvi);
	// Setare subitem1
	strItem.Format(_T("1994"));
	lvi.iSubItem = 1;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);
	// Setare subitem2
	strItem.Format(_T("121 min"));
	lvi.iSubItem = 2;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);

	//Inserare subitem0 -> al X-lea DVD	
	lvi.mask = LVIF_IMAGE | LVIF_TEXT;
	strItem.Format(_T("Star Trek"));
	lvi.iItem = 2;
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.InsertItem(&lvi);
	// Setare subitem1
	strItem.Format(_T("2013"));
	lvi.iSubItem = 1;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);
	// Setare subitem2
	strItem.Format(_T("132 min"));
	lvi.iSubItem = 2;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);

	//Inserare subitem0 -> al XI-lea DVD	
	lvi.mask = LVIF_IMAGE | LVIF_TEXT;
	strItem.Format(_T("Two Week Notice"));
	lvi.iItem = 2;
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.InsertItem(&lvi);
	// Setare subitem1
	strItem.Format(_T("2002"));
	lvi.iSubItem = 1;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);
	// Setare subitem2
	strItem.Format(_T("101 min"));
	lvi.iSubItem = 2;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);

	//Inserare subitem0 -> al XII-lea DVD	
	lvi.mask = LVIF_IMAGE | LVIF_TEXT;
	strItem.Format(_T("Miss Congeniality"));
	lvi.iItem = 2;
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.InsertItem(&lvi);
	// Setare subitem1
	strItem.Format(_T("2000"));
	lvi.iSubItem = 1;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);
	// Setare subitem2
	strItem.Format(_T("109 min"));
	lvi.iSubItem = 2;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	Lista.SetItem(&lvi);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Clab4TemaDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Clab4TemaDlg::OnPaint()
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
HCURSOR Clab4TemaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Clab4TemaDlg::OnBnClickedCalculeaza()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	double red;
	double calitate = 1;
	double tip = 1;
	if (Lista.GetSelectedCount() == 0)
		AfxMessageBox((LPCWSTR)L"Selectati cel putin un DVD!");
	else if (Zile.GetCurSel() == -1)
		AfxMessageBox((LPCWSTR)L"Selectati Numarul de zile!");
	else if (Pret == 0)
		AfxMessageBox((LPCWSTR)L"Pretul este 0!");
	else {
		if ((Zile.GetCurSel() + 1) <= 3)
			red = 1;
		else if ((Zile.GetCurSel() + 1) > 3 && (Zile.GetCurSel() + 1) <= 6)
			red = 0.95;
		else red = 0.80;

		if (Calitate == 0)
			calitate = 0.15;
		else if (Calitate == 1)
			calitate =  0.35;
		else calitate =  0.75;

		if (Tip == 0)
			tip = tip - 0.55;
		else tip = tip - 0.25;

		Total = (Zile.GetCurSel() + 1) * Pret * Lista.GetSelectedCount() * red * (Reducere ? 0.75 : 1) * calitate * tip ;
		
		
		//Total = Pret * Lista.GetSelectedCount() * (Reducere ? red : 1);
	}
	UpdateData(FALSE);

	


}


void Clab4TemaDlg::OnLvnItemchangedList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	UpdateData();
	Numar = Lista.GetSelectedCount();
	UpdateData(FALSE);
	*pResult = 0;
}
