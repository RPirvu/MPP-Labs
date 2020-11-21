
// TemaLab2Dlg.h : header file
//

#pragma once


// CTemaLab2Dlg dialog
class CTemaLab2Dlg : public CDialogEx
{
// Construction
public:
	CTemaLab2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEMALAB2_DIALOG };
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
	int nr;
	int cmmdc;
	int cmmmc;
	afx_msg void OnBnClickedCalculeaza();
};
