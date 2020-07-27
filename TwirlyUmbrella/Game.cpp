/**
 * \file Game.cpp
 *
 * \author Griffin Klevering
 */

#include "pch.h"
#include "Game.h"
#include <memory>

const float StandardHeight = 1024; ///The standard height of the client
const float StandardWidth = 1820; ///The standard width of the client

///The starting locations for the X and the Y coordinates upon the game beginning
const double XStart = 500;
const double YStart = 500;

/** 
* Constructor
*/
CGame::CGame()
{
	mUmbrella = std::make_shared<CUmbrella>(XStart, YStart);
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

/**
* Updates each part of the game (pipes, umbrella, etc.)
* \param elapsedTime The time since the last update
*/
void CGame::Update(double elapsedTime) 
{
	mUmbrella->Update(elapsedTime);
}

/** Jumps the umbrella
*/
void CGame::jump() 
{
	mUmbrella->SetVelocity(-50);
}