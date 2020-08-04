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
void COverlay::Draw(Graphics* graphics, bool gameOver)
{
    /// Sets Font
    FontFamily fontFamily(L"Arial");
    Gdiplus::Font font(&fontFamily, 50);

    std::wstring score = L"Score: " + std::to_wstring(mScore);

    SolidBrush red(Color(BYTE(2000), BYTE(40), BYTE(40)));
    graphics->DrawString(score.c_str(), -1, &font, PointF(1400, 10), &red);

    std::wstring highscore = L"High Score: " + std::to_wstring(mHighScore);

    graphics->DrawString(highscore.c_str(), -1, &font, PointF(1242, 65), &red);

    if (gameOver == true) 
    {
        Gdiplus::Font font2(&fontFamily, 150);
        graphics->DrawString(L"GAME OVER", -1, &font2, PointF(250, 512), &red);
        if (mScore > mHighScore)
        {
            Gdiplus::Font font3(&fontFamily, 100);
            SolidBrush green(Color(BYTE(40), BYTE(200), BYTE(40)));
            graphics->DrawString(L"New Record!", -1, &font3, PointF(480, 200), &green);
        }
        SolidBrush green(Color(BYTE(40), BYTE(200), BYTE(40)));
        graphics->DrawString(L"Press ""SPACE"" to reset", -1, &font, PointF(480, 400), &green);
    }
}

/** Increments the score by 1
*/
void COverlay::Increment()
{
    mScore++;
}

/** Resets score after a game over
* Sets a new high score
*/
void COverlay::ResetScore() 
{
    if (mScore > mHighScore) 
    {
        mHighScore = mScore;
    }
    mScore = 0;
}