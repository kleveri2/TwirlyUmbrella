/**
 * \file Umbrella.cpp
 *
 * \author Griffin Klevering
 */

#include "pch.h"
#include "Umbrella.h"
#include <string>


using namespace Gdiplus;

///The gravity the umbrella must face
const double Gravity = 100;

/** Constructor */
CUmbrella::CUmbrella(double XStart, double YStart, double RotationRate, std::shared_ptr<CTexture> texture)
{
	SetXPos(XStart);
	SetYPos(YStart);


	mRotationRate = RotationRate;
	mTexture = texture;
	mRotation = 0;
	mYVelocity = 0;
}

/**
* Draw the Umbrella
* \param graphics The GDI graphics being drawn on
*/
void CUmbrella::Draw(Graphics* graphics)
{
	auto state = graphics->Save();
	graphics->TranslateTransform(static_cast<float>(GetXPos()), static_cast<float>(GetYPos()));
	graphics->RotateTransform((float)(mRotation));

	// -width/2 because GDI places coordinates at the top left of an image instead of the middle
	mTexture->DrawTexture(graphics, -mTexture->GetWidth() / 2, -mTexture->GetHeight() / 2);

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
	if (mYVelocity < 0) 
	{
		mYVelocity = 0;
	}
	mRotation = mRotation + elapsedTime * mRotationRate;
	Update(elapsedTime);
}

/** Resets the umbrella from a game over
* \param xStart The reset x starting coordinate
* \param yStart The reset y starting coordinate
*/
void CUmbrella::Reset(double xStart, double yStart) 
{
	SetXPos(xStart);
	SetYPos(yStart);
	mYVelocity = 0;
	mRotation = 0;
}
