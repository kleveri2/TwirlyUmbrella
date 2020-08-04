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
    void Draw(Graphics* graphics);
    void Increment();
private:
    int mScore; ///The current score of the game
    int mHighScore; ///The highest scored so far
};

