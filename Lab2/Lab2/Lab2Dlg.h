
// Lab2Dlg.h : header file
//

#pragma once


// CLab2Dlg dialog
class CLab2Dlg : public CDialogEx
{
// Construction
public:
	CLab2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB2_DIALOG };
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
	int cmmdc;
	int cmmmc;
	afx_msg void OnBnClickedCalculeaza();
	afx_msg void OnStnClickedStatica();
	afx_msg void OnStnClickedStaticcmmdc();
	afx_msg void OnStnClickedStaticb();
	afx_msg void OnBnClickedReset();
	int ListaCMMMC;
	CString Lista;
	afx_msg void OnBnClickedCalculeazalista();
	int nr;
	int ListCMMDC;
	afx_msg void OnBnClickedCalculeazalista2();

	int ListaCMMDC;
};
