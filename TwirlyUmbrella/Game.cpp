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

/**
* Draw the game and its components
* \param graphics the GDI graphics being drawn on
* \param width The width of the window
* \param height The height of the window
*/
void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height)
{
	///Scales the window to any size
	mClientScaleY = height / StandardHeight;
	mClientScaleX = width / StandardWidth;
	graphics->ScaleTransform(mClientScaleX, mClientScaleY);

	mUmbrella->Draw(graphics);
}

void CGame::Update(double elapsedTime) 
{
}
