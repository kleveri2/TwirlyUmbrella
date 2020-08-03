/**
 * \file Obstacle.cpp
 *
 * \author Griffin Klevering
 */

#include "pch.h"
#include "Obstacle.h"
#include <string>

using namespace Gdiplus;

const std::wstring ObstacleTest(L"images/Obstacletest2.png");

/** Constructor
* \param XStart The starting x location of the obstacle
* \param YStart the starting Y location of the obstacle
* \param GapSize the size of the gap between the top and bottom obstacles
*/
CObstacle::CObstacle(int XStart, int YStart, double GapSize, double XVelocity) 
{
	SetXPos(XStart);
	SetYPos(YStart);
	mXVelocity = XVelocity;
	mGapSize = GapSize;

	mTopImage = std::unique_ptr<Bitmap>(Bitmap::FromFile(ObstacleTest.c_str()));
	mBottomImage = std::unique_ptr<Bitmap>(Bitmap::FromFile(ObstacleTest.c_str()));
}

/** Draws the obstacle
* \param graphics  the GDI graphics being drawn on
*/
void CObstacle::Draw(Graphics* graphics)
{
	double width = mTopImage->GetWidth();
	double height = mTopImage->GetHeight();

	graphics->DrawImage(mTopImage.get(), static_cast<float>(GetXPos() - width/2), \
		static_cast<float>(GetYPos() - mGapSize - height), static_cast<float>(mTopImage->GetWidth()), \
		static_cast<float>(mTopImage->GetHeight()));

	//Ypos = ypos + gapsize - height/2 + height/2
	graphics->DrawImage(mBottomImage.get(), static_cast<float>(GetXPos() - width/2), \
		static_cast<float>(GetYPos() + mGapSize), static_cast<float>(mBottomImage->GetWidth()), \
		static_cast<float>(mBottomImage->GetHeight()));
}

/** Changes the obstacle's position
* \param elapsedTime The time since the last update
*/
void CObstacle::Update(double elapsedTime)
{
	SetXPos(GetXPos() - (mXVelocity * elapsedTime));
}