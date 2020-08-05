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
void COverlay::DrawScore(Graphics* graphics)
{
    /// Sets Font
    FontFamily fontFamily(L"Arial");
    Gdiplus::Font font(&fontFamily, 50);

    std::wstring score = L"Score: " + std::to_wstring(mScore);

    SolidBrush red(Color(BYTE(2000), BYTE(40), BYTE(40)));
    graphics->DrawString(score.c_str(), -1, &font, PointF(1400, 10), &red);

    std::wstring highscore = L"High Score: " + std::to_wstring(mHighScore);

    graphics->DrawString(highscore.c_str(), -1, &font, PointF(1242, 65), &red);
}

/** Draw game over info
* \param graphics  the GDI graphics being drawn on
*/
void COverlay::DrawGameOver(Graphics* graphics)
{
    FontFamily fontFamily(L"Arial");

    Gdiplus::Font font(&fontFamily, 150);
    SolidBrush red(Color(BYTE(2000), BYTE(40), BYTE(40)));
    graphics->DrawString(L"GAME OVER", -1, &font, PointF(250, 512), &red);

    SolidBrush green(Color(BYTE(40), BYTE(200), BYTE(40)));
    if (mScore > mHighScore)
    {
        Gdiplus::Font font2(&fontFamily, 100);
        graphics->DrawString(L"New Record!", -1, &font2, PointF(480, 200), &green);
    }
    Gdiplus::Font font3(&fontFamily, 50);
    graphics->DrawString(L"Press ""SPACE"" to reset", -1, &font3, PointF(550, 400), &green);
}

/** Draw game start info
* \param graphics  the GDI graphics being drawn on
*/
void COverlay::DrawGameStart(Graphics* graphics)
{
    FontFamily fontFamily(L"Arial");
    Gdiplus::Font font(&fontFamily, 50);
    SolidBrush green(Color(BYTE(40), BYTE(200), BYTE(40)));

    graphics->DrawString(L"Press ""SPACE"" to begin!", -1, &font, PointF(550, 400), &green);
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