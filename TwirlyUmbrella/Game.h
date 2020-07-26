/**
 * \file Game.h
 *
 * \author Griffin Klevering
 */

#pragma once
#include <memory>
#include "Umbrella.h"

/** Class for the game being played */
class CGame
{
public:

    CGame();

    void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height);

    void Update(double elapsedTime);

    void jump();

private:
    int mHeight; ///The width of the game
    int mWidth; ///The height of the game

    float mClientScaleX; ///The X scale of the client window
    float mClientScaleY; ///The Y scale of the client window

    std::shared_ptr<CUmbrella> mUmbrella; ///The umbrella the user controls
};

