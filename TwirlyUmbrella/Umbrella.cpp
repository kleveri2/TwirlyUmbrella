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
CUmbrella::CUmbrella(double XStart, double YStart, double RotationRate)
{
	SetXPos(XStart);
	SetYPos(YStart);

	mTextureNum = 0;

	mLastChange  = 0;

	mRotationRate = RotationRate;
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
	mTextures[mTextureNum]->DrawTexture(graphics, -mTextures[mTextureNum]->GetWidth() / 2, -mTextures[mTextureNum]->GetHeight() / 2);

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

	if (mYVelocity < 0)
	{
		mTextureNum++;
		if (mTextureNum >= mTextures.size()) 
		{
			mTextureNum = 0;
		}
		
	}
	mLastChange = GetYPos();
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

/** Adds a new texture to the umbrella's texture cycle
* \param tex The new texture being added
*/
void CUmbrella::AddTexture(std::shared_ptr<CTexture> tex) 
{
	mTextures.push_back(tex);
}
