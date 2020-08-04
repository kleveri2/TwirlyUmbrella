/**
 * \file Overlay.cpp
 *
 * \author Griffin Klevering
 */
#include "pch.h"
#include "Overlay.h"
#include <string>

using namespace Gdiplus;

/** Constructor
*/
COverlay::COverlay()
{
	mScore = 0;
	mHighScore = 0;
}

/** Draws the scoreboard
* \param graphics  the GDI graphics being drawn on
*/
void COverlay::Draw(Graphics* graphics)
{
    /// Sets Font
    FontFamily fontFamily(L"Arial");
    Gdiplus::Font font(&fontFamily, 80);

    std::wstring score = L"Score: " + std::to_wstring(mScore);

    SolidBrush green(Color(0, 64, 0));
    graphics->DrawString(score.c_str(),  // String to draw
        -1,         // String length, -1 means it figures it out on its own
        &font,      // The font to use
        PointF(10, 10),   // Where to draw (top left corner)
        &green);    // The brush to draw the text with
}

/** Increments the score by 1
*/
void COverlay::Increment()
{
    mScore++;
}
