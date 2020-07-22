#include "pch.h"
#include "Umbrella.h"
#include <string>

const std::wstring UmbrellaTest(L"images/Umbrellatest.png");

using namespace Gdiplus;

const double XStart = 500;
const double YStart = 500;

/** Constructor */
CUmbrella::CUmbrella()
{
	mXPos = XStart;
	mYPos = YStart;
	mUmbrellaImage = std::unique_ptr<Bitmap>(Bitmap::FromFile(UmbrellaTest.c_str()));
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
