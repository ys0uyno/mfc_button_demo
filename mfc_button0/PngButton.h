#pragma once

// CPngButton

class CPngButton : public CButton
{
	DECLARE_DYNAMIC(CPngButton)

public:
	CPngButton();
	virtual ~CPngButton();

protected:
	DECLARE_MESSAGE_MAP()

public:
	void set_image_path(const CString &button_image, const CString &bk_image);
	bool init_button(int x, int y, int cx, int cy, bool is_png);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

public:
	CImage m_button_image;
	CString m_button_image_path;
	CString m_bk_image_path;
};
