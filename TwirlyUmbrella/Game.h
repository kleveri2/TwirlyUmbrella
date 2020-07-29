/**
 * \file Game.h
 *
 * \author Griffin Klevering
 */

#pragma once
#include <memory>
#include "Umbrella.h"
#include "Obstacle.h"
#include <vector>
/** Class for the game being played
* Contains obstacles and an umbrella
*/
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

    std::vector<std::shared_ptr<CObstacle>> mObstacles; ///The obstacles that the umbrella must dodge

    double mObstacleTime; ///The last time an obstacle was made

    int mObstacleRange; ///The range of Y coordinates where the Y can be
};

