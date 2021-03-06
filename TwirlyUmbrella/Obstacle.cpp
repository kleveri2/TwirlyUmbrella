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
	SetVelocity(XVelocity);
	mGapSize = GapSize;

	SetTexture(texture);
}

/** Draws the obstacle
* \param graphics  the GDI graphics being drawn on
*/
void CObstacle::Draw(Graphics* graphics)
{
	GetTexture()->DrawTexture(graphics, GetXPos() - GetTexture()->GetWidth()/2, \
		GetYPos() - mGapSize - GetTexture()->GetHeight());

	//Ypos = ypos + gapsize - height/2 + height/2
	GetTexture()->DrawTexture(graphics, GetXPos() - GetTexture()->GetWidth()/2, GetYPos() + mGapSize);

}

/** Changes the obstacle's position
* \param elapsedTime The time since the last update
*/
void CObstacle::Update(double elapsedTime)
{
	SetXPos(GetXPos() - (GetVelocity() * elapsedTime));
}