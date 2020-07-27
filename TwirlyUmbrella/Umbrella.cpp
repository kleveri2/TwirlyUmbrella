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
CUmbrella::CUmbrella(double XStart, double YStart)
{
	SetXPos(XStart);
	SetYPos(YStart);
	mUmbrellaImage = std::unique_ptr<Bitmap>(Bitmap::FromFile(UmbrellaTest.c_str()));
	mYVelocity = 0;
}

/**
* Draw the Umbrella
* \param graphics The GDI graphics being drawn on
*/
void CUmbrella::Draw(Graphics* graphics)
{
    graphics->DrawImage(mUmbrellaImage.get(), static_cast<int>(GetXPos()),\
		static_cast<int>(GetYPos()), mUmbrellaImage->GetWidth(),\
		mUmbrellaImage->GetHeight());
}

void CUmbrella::Update(double elapsedTime) 
{
	mYVelocity = mYVelocity + (Gravity * elapsedTime);
	double YPos = GetYPos();
	 SetYPos(YPos + mYVelocity);
}

