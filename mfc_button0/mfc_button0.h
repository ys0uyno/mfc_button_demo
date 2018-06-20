
// mfc_button0.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cmfc_button0App:
// See mfc_button0.cpp for the implementation of this class
//

class Cmfc_button0App : public CWinApp
{
public:
	Cmfc_button0App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cmfc_button0App theApp;