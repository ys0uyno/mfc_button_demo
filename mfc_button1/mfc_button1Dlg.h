
// mfc_button1Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "ColorButton.h"

// Cmfc_button1Dlg dialog
class Cmfc_button1Dlg : public CDialogEx
{
// Construction
public:
	Cmfc_button1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFC_BUTTON1_DIALOG };

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
	ColorButton m_button1;
};
