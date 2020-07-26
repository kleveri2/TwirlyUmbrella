#include "pch.h"
#include "Umbrella.h"
#include <string>

const std::wstring UmbrellaTest(L"images/Umbrellatest.png");

using namespace Gdiplus;

///The starting locations for the X and the Y coordinates upon the game beginning
const double XStart = 500;
const double YStart = 500;
///The gravity the umbrella must face
const double Gravity = 100;

/** Constructor */
CUmbrella::CUmbrella()
{
	mXPos = XStart;
	mYPos = YStart;
	mUmbrellaImage = std::unique_ptr<Bitmap>(Bitmap::FromFile(UmbrellaTest.c_str()));
	mVelocity = 0;
}

/**
* Draw the Umbrella
* \param graphics The GDI graphics being drawn on
*/
void CUmbrella::Draw(Graphics* graphics)
{
    graphics->DrawImage(mUmbrellaImage.get(), static_cast<int>(mXPos),\
		static_cast<int>(mYPos), mUmbrellaImage->GetWidth(),\
		mUmbrellaImage->GetHeight());
}

void CUmbrella::Update(double elapsedTime) 
{
	mVelocity = mVelocity + (Gravity * elapsedTime);
	mYPos = mYPos + mVelocity;
}

