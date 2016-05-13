// wg_groupbox.h
//
// CGroupBox interface
//
//
// Copyright (c) 2002-2004 Rob Wiskow
// rob-dev@boxedchaos.com
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//


#ifndef _WG_GROUPBOX_H_
#define _WG_GROUPBOX_H_

#include "wg_window.h"
#include "wg_painter.h"
#include "wg_renderedstring.h"
#include "wg_application.h"
#include <string>
#include <memory>


namespace wGui
{

//! A GroupBox is really just a fancier label that includes a box

class CGroupBox : public CWindow
{
public:
	//! Construct a new group box
  	//! \param WindowRect A CRect that defines the outer limits of the control
	//! \param pParent A pointer to the parent window
	//! \param sText The label text
	//! \param FontColor The color of the label text
	//! \param pFontEngine A pointer to the font engine to use when drawing the control
	//! If this is left out (or set to 0) it will use the default font engine specified by the CApplication (which must be set before instantiating this object)
	CGroupBox(const CRect& WindowRect, CWindow* pParent, std::string sText,
		CRGBColor& FontColor = ALTERNATE_TEXT_COLOR, CFontEngine* pFontEngine = nullptr);

	//! Standard destructor
	virtual ~CGroupBox(void);

	//! Sets the color of the font used to render the label
	//! \param FontColor The color of the label text
	void SetFontColor(CRGBColor& FontColor) { m_FontColor = FontColor; }

	//! Gets the font color for the label od the group box
	//! \return The color of the text in the label
	CRGBColor GetFontColor(void) { return m_FontColor; }

	// CWindow overrides
	//! Renders the Window Text, and clips to the Window Rect
	virtual void Draw(void) const;

	//! Set the WindowText of the label
	//! \param sWindowText The text to assign to the window
	virtual void SetWindowText(const std::string& sWindowText);

	//! Giving a control a new WindowRect will move and resize the control
	//! \param WindowRect A CRect that defines the outer limits of the control
	virtual void SetWindowRect(const CRect& WindowRect);

protected:
	CFontEngine* m_pFontEngine;  //!< A pointer to the font engine to use to render the text
	std::unique_ptr<CRenderedString> m_pRenderedString;  //!< An autopointer to the rendered version of the string
	CRGBColor m_FontColor;  //!< The font color


private:
	void operator=(CGroupBox) { }  //!< The assignment operator is not allowed for CWindow derived objects
};

}


#endif // _WG_GROUPBOX_H_




