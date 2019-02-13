// ColorButton.cpp : implementation file
//

#include "stdafx.h"
#include "mfc_button1.h"
#include "ColorButton.h"


// ColorButton

IMPLEMENT_DYNAMIC(ColorButton, CButton)

ColorButton::ColorButton()
{
	m_bmouse_track = true;
	m_bhover = false;
}

ColorButton::~ColorButton()
{
}


BEGIN_MESSAGE_MAP(ColorButton, CButton)
	ON_WM_MOUSELEAVE()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEHOVER()
END_MESSAGE_MAP()



// ColorButton message handlers




void ColorButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO:  Add your code to draw the specified item
	if (m_bhover)
	{
		OutputDebugString(L"hover");
	}
	else
	{
		OutputDebugString(L"no hover");
	}

	CDC *pdc = CDC::FromHandle(lpDrawItemStruct->hDC);
	CRect rect;

	rect.CopyRect(&lpDrawItemStruct->rcItem);
	DrawFocusRect(lpDrawItemStruct->hDC, &rect);
	pdc->Draw3dRect(rect,
		GetSysColor(COLOR_BTNHIGHLIGHT),
		GetSysColor(COLOR_BTNSHADOW)
		);

	CBrush brush;
	if (lpDrawItemStruct->itemState &ODS_SELECTED)
	{
		brush.CreateSolidBrush(RGB(100, 0, 0));
	}
	else if (m_bhover)
	{
		brush.CreateSolidBrush(RGB(0, 100, 0));
	}
	else
	{
		brush.CreateSolidBrush(RGB(0, 0, 100));
	}

	FillRect(lpDrawItemStruct->hDC, &rect, (HBRUSH)brush.m_hObject);
	SetBkMode(lpDrawItemStruct->hDC, TRANSPARENT);

	CString button_text;
	GetWindowText(button_text);

	COLORREF orig_text_color =
		SetTextColor(lpDrawItemStruct->hDC,RGB(255, 0, 0));

	DrawText(lpDrawItemStruct->hDC,
		button_text,
		button_text.GetLength(),
		&lpDrawItemStruct->rcItem,
		DT_SINGLELINE | DT_VCENTER | DT_CENTER
		);

	SetTextColor(lpDrawItemStruct->hDC, orig_text_color);
}


void ColorButton::OnMouseLeave()
{
	// TODO: Add your message handler code here and/or call default
	m_bmouse_track = true;
	m_bhover = false;
	Invalidate();

	CButton::OnMouseLeave();
}


void ColorButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_bmouse_track)
	{
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(tme);
		tme.dwFlags = TME_LEAVE | TME_HOVER;
		tme.hwndTrack = GetSafeHwnd();
		tme.dwHoverTime = 10;
		_TrackMouseEvent(&tme);

		m_bmouse_track = false;
	}

	CButton::OnMouseMove(nFlags, point);
}


void ColorButton::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_bhover = true;
	Invalidate();

	CButton::OnMouseHover(nFlags, point);
}
