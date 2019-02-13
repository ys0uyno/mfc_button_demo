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
