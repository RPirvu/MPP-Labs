
// lab3.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clab3App:
// See lab3.cpp for the implementation of this class
//

class Clab3App : public CWinApp
{
public:
	Clab3App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedReset();
};

extern Clab3App theApp;
