/**
 * \file Obstacle.h
 *
 * \author Griffin Klevering
 */

#pragma once
#include "GameObject.h"
#include "Texture.h"
#include "ScrollingObject.h"
/** Class for the obstacles the umbrella will need to navigate
*
* Derived from CGameObject
*/
class CObstacle : public CScrollingObject
{
public:

    CObstacle() = delete;


    CObstacle(int XStart, int YStart, double GapSize, double XVelocity, std::shared_ptr<CTexture> texture);

    void Draw(Gdiplus::Graphics* graphics);

    void Update(double elapsedTime);

private:
    double mGapSize; ///The size of the gap between two poles;

};

