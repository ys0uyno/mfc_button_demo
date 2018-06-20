// PngButton.cpp : implementation file
//

#include "stdafx.h"
#include "mfc_button0.h"
#include "PngButton.h"

// CPngButton

IMPLEMENT_DYNAMIC(CPngButton, CButton)

CPngButton::CPngButton()
{

}

CPngButton::~CPngButton()
{
}

void CPngButton::set_image_path(const CString &button_image, const CString &bk_image)
{
	m_button_image_path = button_image;
	m_bk_image_path = bk_image;
}

bool CPngButton::init_button(int x, int y, int cx, int cy, bool is_png)
{
	if (m_button_image_path.IsEmpty())
		return false;

	HRESULT hr = 0;
	hr = m_button_image.Load(m_button_image_path);

	if (FAILED(hr))
		return false;

	if (is_png)
	{
		if (m_button_image.GetBPP() == 32)
		{
			int i = 0;
			int j = 0;
			for (i = 0; i < m_button_image.GetWidth(); i++)
			{
				for (j = 0; j < m_button_image.GetHeight(); j++)
				{
					byte * pbyte = (byte *)m_button_image.GetPixelAddress(i, j);
					pbyte[0] = pbyte[0] * pbyte[3] / 255;
					pbyte[1] = pbyte[1] * pbyte[3] / 255;
					pbyte[2] = pbyte[2] * pbyte[3] / 255;
				}
			}
		}
	}

	MoveWindow(x, y, cx, cy);

	return true;
}

void CPngButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	if (!lpDrawItemStruct)
		return;

	HBITMAP bmpMem;
	bmpMem = CreateCompatibleBitmap(
		lpDrawItemStruct->hDC,
		lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left,
		lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top
		);
	if (!bmpMem)
		return;

	HDC hMemDC;
	hMemDC = CreateCompatibleDC(lpDrawItemStruct->hDC);
	if (!hMemDC)
	{
		if (bmpMem)
		{
			::DeleteObject(bmpMem);
			bmpMem = NULL;
		}
		return;
	}

	HGDIOBJ hOldObj;
	hOldObj = ::SelectObject(hMemDC, bmpMem);

	RECT rectTmp = {0};
	rectTmp = lpDrawItemStruct->rcItem;

	MapWindowPoints(GetParent(), &rectTmp);

	int nW = lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left;
	int nH = lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top;

	if (lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		m_button_image.BitBlt(hMemDC, 0, 0, nW, nH, nW * 2, 0, SRCCOPY);
	}
	else if (lpDrawItemStruct->itemState & ODS_FOCUS)
	{
		m_button_image.BitBlt(hMemDC, 0, 0, nW, nH, nW, 0, SRCCOPY);		
	}
	else
	{
		CImage imgParent;
		imgParent.Load(m_bk_image_path);
		imgParent.Draw(hMemDC, 0, 0, nW, nH, rectTmp.left, rectTmp.top, nW, nH);
		m_button_image.AlphaBlend(hMemDC, 0, 0, nW, nH, 0, 0, nW, nH);
		imgParent.Destroy();
	}

	::BitBlt(lpDrawItemStruct->hDC, 0, 0, nW, nH, hMemDC, 0, 0, SRCCOPY);

	SelectObject(hMemDC, hOldObj);

	if (bmpMem)
	{
		::DeleteObject(bmpMem);
		bmpMem = NULL;
	}

	if (hMemDC)
	{
		::DeleteDC(hMemDC);
		hMemDC = NULL;
	}

	return;
}

BEGIN_MESSAGE_MAP(CPngButton, CButton)
END_MESSAGE_MAP()

// CPngButton message handlers
