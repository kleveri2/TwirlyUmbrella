/**
 * \file Obstacle.cpp
 *
 * \author Griffin Klevering
 */

#include "pch.h"
#include "Obstacle.h"
#include <string>

using namespace Gdiplus;


/** Constructor
* \param XStart The starting x location of the obstacle
* \param YStart the starting Y location of the obstacle
* \param GapSize the size of the gap between the top and bottom obstacles
*/
CObstacle::CObstacle(int XStart, int YStart, double GapSize, double XVelocity, std::shared_ptr<CTexture> texture) 
{
	SetXPos(XStart);
	SetYPos(YStart);
	mXVelocity = XVelocity;
	mGapSize = GapSize;

	mTexture = texture;
}

/** Draws the obstacle
* \param graphics  the GDI graphics being drawn on
*/
void CObstacle::Draw(Graphics* graphics)
{
	mTexture->DrawTexture(graphics, GetXPos() - mTexture->GetWidth(), \
		GetYPos() - mGapSize - mTexture->GetHeight());
	

	//Ypos = ypos + gapsize - height/2 + height/2
	mTexture->DrawTexture(graphics, GetXPos() - mTexture->GetWidth(), GetYPos() + mGapSize);

}

/** Changes the obstacle's position
* \param elapsedTime The time since the last update
*/
void CObstacle::Update(double elapsedTime)
{
	SetXPos(GetXPos() - (mXVelocity * elapsedTime));
}