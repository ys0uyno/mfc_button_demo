
// mfc_button0Dlg.h : header file
//

#pragma once


// Cmfc_button0Dlg dialog
class Cmfc_button0Dlg : public CDialogEx
{
// Construction
public:
	Cmfc_button0Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFC_BUTTON0_DIALOG };

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
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

public:
	CBrush m_brush;
	afx_msg LRESULT OnNcHitTest(CPoint point);
};
