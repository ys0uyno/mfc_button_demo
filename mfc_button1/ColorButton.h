#pragma once


// ColorButton

class ColorButton : public CButton
{
	DECLARE_DYNAMIC(ColorButton)

public:
	ColorButton();
	virtual ~ColorButton();

protected:
	DECLARE_MESSAGE_MAP()

public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	afx_msg void OnMouseLeave();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);

private:
	bool m_bmouse_track;
	bool m_bhover;
};
