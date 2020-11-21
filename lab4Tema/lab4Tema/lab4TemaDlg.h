
// lab4TemaDlg.h : header file
//

#pragma once


// Clab4TemaDlg dialog
class Clab4TemaDlg : public CDialogEx
{
// Construction
public:
	Clab4TemaDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB4TEMA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl Lista;
	CComboBox Zile;
	BOOL Reducere;
	int Pret;
	double Total;
	int Calitate;
	int Tip;
	afx_msg void OnBnClickedCalculeaza();
	double GET;
	int Numar;
	afx_msg void OnLvnItemchangedList(NMHDR* pNMHDR, LRESULT* pResult);
};
