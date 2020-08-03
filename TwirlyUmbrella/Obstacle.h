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

    CObstacle(int XStart, int YStart, double GapSize, double XVelocity);

    void Draw(Gdiplus::Graphics* graphics);

    void Update(double elapsedTime);

    /** Gets the width of the obstacle image
    * \returns The width in pixels
    * uses mTopImage, but both are the same width, so its arbitrary
    */
    double GetWidth() { return mTopImage->GetWidth(); }

    /** Gets the height of the obstacle image
    * \returns The height in pixels
    * uses mTopImage, but both are the same height, so its arbitrary
    */
    double GetHeight() { return mTopImage->GetWidth(); }

private:
    ///The top obstacle image
    std::unique_ptr<Gdiplus::Bitmap> mTopImage;

    ///The bottom obstacle image
    std::unique_ptr<Gdiplus::Bitmap> mBottomImage;

    double mGapSize; ///The size of the gap between two poles;

    double mXVelocity; ///The velocity of the obstacle going left

};

