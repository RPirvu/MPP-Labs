
// lab4Dlg.h : header file
//

#pragma once


// Clab4Dlg dialog
class Clab4Dlg : public CDialogEx
{
// Construction
public:
	Clab4Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB4_DIALOG };
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
	CListBox Lista;
	afx_msg void OnBnClickedOk();
	CComboBox Zile;
	BOOL Reducere;
	long Pret;
	double Total;
	afx_msg void OnBnClickedCalculeaza();
};
