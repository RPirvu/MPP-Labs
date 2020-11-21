
// lab3Dlg.h : header file
//

#pragma once


// Clab3Dlg dialog
class Clab3Dlg : public CDialogEx
{
// Construction
public:
	Clab3Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB3_DIALOG };
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
	int A;
	int B;
	int OPERATIE;
	double Rezultat;
	afx_msg void OnBnClickedCalculeaza();
	CString Text;
	afx_msg void OnBnClickedReset();
	double C;
	double D;
	double Rezultat2;
	CString Text2;
	int X;
	int Y;
	int MOD;
	double Rezultat3;
	CString Text3;
};
