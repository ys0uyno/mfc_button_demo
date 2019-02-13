
// mfc_button1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <GdiPlus.h>

// Cmfc_button1App:
// See mfc_button1.cpp for the implementation of this class
//

class Cmfc_button1App : public CWinApp
{
public:
	Cmfc_button1App();

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()

private:
	ULONG_PTR m_gdiplus_token;
};

extern Cmfc_button1App theApp;