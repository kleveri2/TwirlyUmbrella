/**
 * \file Umbrella.cpp
 *
 * \author Griffin Klevering
 */

#include "pch.h"
#include "Umbrella.h"
#include <string>

const std::wstring UmbrellaTest(L"images/Umbrellatest.png");

using namespace Gdiplus;

///The gravity the umbrella must face
const double Gravity = 100;

/** Constructor */
CUmbrella::CUmbrella(double XStart, double YStart, double RotationRate)
{
	SetXPos(XStart);
	SetYPos(YStart);


	mRotationRate = RotationRate;
	mUmbrellaImage = std::unique_ptr<Bitmap>(Bitmap::FromFile(UmbrellaTest.c_str()));
	mRotation = 0;
	mYVelocity = 0;
}

/**
* Draw the Umbrella
* \param graphics The GDI graphics being drawn on
*/
void CUmbrella::Draw(Graphics* graphics)
{
	double width = mUmbrellaImage->GetWidth();
	double height = mUmbrellaImage->GetHeight();
	auto state = graphics->Save();
		graphics->TranslateTransform(static_cast<float>(GetXPos()), static_cast<float>(GetYPos()));
		graphics->RotateTransform((float)(mRotation));

		// -width/2 because GDI places coordinates at the top left of an image instead of the middle
		graphics->DrawImage(mUmbrellaImage.get(), static_cast<float>(-width/2), \
			static_cast<float>(-height/2), static_cast<float>(mUmbrellaImage->GetWidth()), \
			static_cast<float>(mUmbrellaImage->GetHeight()));

	graphics->Restore(state);
}

/** Changes the umbrellas position
* \param elapsedTime The time since the last update
*/
void CUmbrella::Update(double elapsedTime) 
{
	mYVelocity = mYVelocity + (Gravity * elapsedTime);
	double YPos = GetYPos();
	SetYPos(YPos + mYVelocity);
}

/** The umbrella falls after a game over
* \param elapsedTime The time since the last update
*/
void CUmbrella::Fall(double elapsedTime)
{
	if (mYVelocity > 0) 
	{
		mYVelocity = 0;
	}
	mRotation = mRotation + elapsedTime * mRotationRate;
	if (mRotation > 180) 
	{
		mRotation = 180;
	}
}
