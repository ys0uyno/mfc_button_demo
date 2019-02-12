
// mfc_button1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


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

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cmfc_button1App theApp;