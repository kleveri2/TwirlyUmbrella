/**
 * \file Overlay.h
 *
 * \author Griffin Klevering
 */

#pragma once
using namespace Gdiplus;

/**
* Displays messages for the user, like score and game start and game over
*/
class COverlay
{
public:
    COverlay();
    void DrawScore(Graphics* graphics);
    void DrawGameOver(Graphics* graphics);
    void DrawGameStart(Graphics* graphics);
    void Increment();
    void ResetScore();
private:
    int mScore; ///The current score of the game
    int mHighScore; ///The highest scored so far
};

