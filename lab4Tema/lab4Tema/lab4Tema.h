
// lab4Tema.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clab4TemaApp:
// See lab4Tema.cpp for the implementation of this class
//

class Clab4TemaApp : public CWinApp
{
public:
	Clab4TemaApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Clab4TemaApp theApp;
