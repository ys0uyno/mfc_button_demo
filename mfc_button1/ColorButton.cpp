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



void FillPathRoundRect(Gdiplus::Graphics *pGraphics, Gdiplus::Rect r, Gdiplus::Color color, int radius)
{
	int dia = 2 * radius;

	Gdiplus::Rect Corner(r.X, r.Y, dia, dia);

	Gdiplus::GraphicsPath path;

	// top left
	path.AddArc(Corner, 180, 90);

	// top right
	Corner.X += (int)(r.Width - dia - 1);
	path.AddArc(Corner, 270, 90);

	// bottom right
	Corner.Y += (int)(r.Height - dia - 1);
	path.AddArc(Corner, 0, 90);

	// bottom left
	Corner.X -= (int)(r.Width - dia - 1);
	path.AddArc(Corner, 90, 90);

	path.CloseFigure();

	Gdiplus::SolidBrush br(color);
	pGraphics->FillPath(&br, &path);
}


void DrawPathRoundRect(Gdiplus::Graphics *pGraphics, Gdiplus::Rect r, Gdiplus::Color color, int radius, int width)
{
	int dia = 2 * radius;

	Gdiplus::Rect Corner(r.X, r.Y, dia, dia);

	Gdiplus::GraphicsPath path;

	// top left
	path.AddArc(Corner, 180, 90);

	// top right
	Corner.X += (int)(r.Width - dia - 1);
	path.AddArc(Corner, 270, 90);

	// bottom right
	Corner.Y += (int)(r.Height - dia - 1);
	path.AddArc(Corner, 0, 90);

	// bottom left
	Corner.X -= (int)(r.Width - dia - 1);
	path.AddArc(Corner, 90, 90);

	path.CloseFigure();

	Gdiplus::Pen pen(color, (Gdiplus::REAL)width);
	pen.SetAlignment(Gdiplus::PenAlignmentInset);
	pGraphics->DrawPath(&pen, &path);
}


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

	Gdiplus::Graphics gdi_graphics(lpDrawItemStruct->hDC);
	Gdiplus::Rect gdi_rect(0, 0,
		lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left,
		lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top
		);

	gdi_graphics.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);

	rect.CopyRect(&lpDrawItemStruct->rcItem);
	// DrawFocusRect(lpDrawItemStruct->hDC, &rect);

	CBrush brush;
	if (lpDrawItemStruct->itemState &ODS_SELECTED)
	{
		// brush.CreateSolidBrush(RGB(100, 100, 100));
		DrawPathRoundRect(&gdi_graphics,
			gdi_rect,
			Gdiplus::Color(255, 100, 100, 100),
			rect.Height() / 2,
			1
			);
		FillPathRoundRect(&gdi_graphics,
			gdi_rect,
			Gdiplus::Color(255, 100, 100, 100),
			rect.Height() / 2
			);
	}
	else if (m_bhover)
	{
		// brush.CreateSolidBrush(RGB(150, 150, 150));
		DrawPathRoundRect(&gdi_graphics,
			gdi_rect,
			Gdiplus::Color(255, 150, 150, 150),
			rect.Height() / 2,
			1
			);
		FillPathRoundRect(&gdi_graphics,
			gdi_rect,
			Gdiplus::Color(255, 150, 150, 150),
			rect.Height() / 2
			);
	}
	else
	{
		// brush.CreateSolidBrush(RGB(200, 200, 200));
		DrawPathRoundRect(&gdi_graphics,
			gdi_rect,
			Gdiplus::Color(255, 200, 200, 200),
			rect.Height() / 2,
			1
			);
		FillPathRoundRect(&gdi_graphics,
			gdi_rect,
			Gdiplus::Color(255, 200, 200, 200),
			rect.Height() / 2
			);
	}

	SetBkMode(lpDrawItemStruct->hDC, TRANSPARENT);
	// FillRect(lpDrawItemStruct->hDC, &rect, (HBRUSH)brush.m_hObject);
	// pdc->Draw3dRect(rect, RGB(0, 0, 0), RGB(0, 0, 0));

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
