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

    void CGame::OnDraw(Gdiplus::Graphics* graphics);

private:
    std::shared_ptr<CUmbrella> mUmbrella; //The umbrella the user controls
};

