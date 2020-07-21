#include "pch.h"
#include "Game.h"
#include <memory>

const float StandardHeight = 1024; ///The standard height of the client
const float StandardWidth = 1820; ///The standard width of the client

/** 
* Constructor
*/
CGame::CGame()
{
	mUmbrella = std::make_shared<CUmbrella>();
}

void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height)
{
	///Scales the window to any size
	mClientScaleY = height / StandardHeight;
	mClientScaleX = width / StandardWidth;
	graphics->ScaleTransform(mClientScaleX, mClientScaleY);

	mUmbrella->Draw(graphics);
}
