/**
 * \file Obstacle.cpp
 *
 * \author Griffin Klevering
 */

#include "pch.h"
#include "Obstacle.h"
#include <string>

using namespace Gdiplus;

const std::wstring ObstacleTest(L"images/obstacletest.png");

/** Constructor
* \param XStart The starting x location of the obstacle
* \param YStart the starting Y location of the obstacle
* \param GapSize the size of the gap between the top and bottom obstacles
*/
CObstacle::CObstacle(int XStart, int YStart, int GapSize) 
{
	SetXPos(XStart);
	SetYPos(YStart);

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

	graphics->DrawImage(mTopImage.get(), static_cast<int>(GetXPos() - width/2), \
		static_cast<int>(GetYPos() - mGapSize - height), mTopImage->GetWidth(), \
		mTopImage->GetHeight());

	//Ypos = ypos + gapsize - height/2 + height/2
	graphics->DrawImage(mBottomImage.get(), static_cast<int>(GetXPos() - width/2), \
		static_cast<int>(GetYPos() + mGapSize), mBottomImage->GetWidth(), \
		mBottomImage->GetHeight());
}