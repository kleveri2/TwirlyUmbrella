/**
 * \file Game.h
 *
 * \author Griffin Klevering
 */

#pragma once
#include <memory>
#include "Umbrella.h"
#include "Obstacle.h"
#include "Overlay.h"
#include <vector>
#include <deque>
#include <random>

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

    void Reset();

    void GameStart();

    void AddObstacle();

    bool TestCollision();

private:
    int mHeight; ///The width of the game
    int mWidth; ///The height of the game

    bool mGameOver; ///If the status of the game is game over

    bool mGameStart; ///If the status of the game is before it starts for the first time

    std::shared_ptr<CUmbrella> mUmbrella; ///The umbrella the user controls

    //I use a deque since it will frequently be removing from the front and adding to the end
    //Whiel also randomly accessing
    std::deque<std::shared_ptr<CObstacle>> mObstacles; ///The obstacles that the umbrella must dodge

    std::shared_ptr<COverlay> mOverlay; ///The overlay that provides info about the game

    ///Only the next obstacle needs to be checked for hitting, so this pointer holds that
    std::shared_ptr<CObstacle> mNextObstacle; 

    double mObstacleTime; ///The last time an obstacle was made

    int mObstacleRange; ///The range of Y coordinates where the Y can be

    std::mt19937 mGenerator; ///The generator for the random Obstacle Y coordinate
};

