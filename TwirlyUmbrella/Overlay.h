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
    void Draw(Graphics* graphics, bool gameOver);
    void Increment();
    void ResetScore();
private:
    int mScore; ///The current score of the game
    int mHighScore; ///The highest scored so far
};

