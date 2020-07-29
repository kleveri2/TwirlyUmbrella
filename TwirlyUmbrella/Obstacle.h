/**
 * \file Obstacle.h
 *
 * \author Griffin Klevering
 */

#pragma once
#include "GameObject.h"
/** Class for the obstacles the umbrella will need to navigate
*
* Derived from CGameObject
*/
class CObstacle : public CGameObject
{
public:

    CObstacle() = delete;

    CObstacle(int XStart, int YStart, int GapSize);

    void Draw(Gdiplus::Graphics* graphics);

    void Update(double elapsedTime) {}

private:
    ///The top obstacle image
    std::unique_ptr<Gdiplus::Bitmap> mTopImage;

    ///The bottom obstacle image
    std::unique_ptr<Gdiplus::Bitmap> mBottomImage;

    int mGapSize; ///The size of the gap between two poles;

};

