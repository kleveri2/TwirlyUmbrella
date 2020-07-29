/**
 * \file Game.cpp
 *
 * \author Griffin Klevering
 */

#include "pch.h"
#include "Game.h"

#include <memory>
#include <ctime>
#include <random>

const float StandardHeight = 1024; ///The standard height of the client
const float StandardWidth = 1820; ///The standard width of the client

///The starting locations for the X and the Y coordinates upon the game beginning
const double XStart = 500;
const double YStart = 500;

///The maximum and minimum locations of the center of the gap between the pillars
const int MaximumY = 800;
const int MinimumY = 200;

/** 
* Constructor
*/
CGame::CGame()
{
	mObstacleTime = 0;
	mUmbrella = std::make_shared<CUmbrella>(XStart, YStart);

	//Get a random number through random_device
	std::random_device rd;
	//Use it as a seed
	std::mt19937 generator(rd());

	//The distribution of high and low to get the Y
	std::uniform_int_distribution<int> distribution(MinimumY, MaximumY);

	int randomY = distribution(generator);

	std::shared_ptr<CObstacle> obstacle = std::make_shared<CObstacle>(100, randomY, mUmbrella->GetHeight() * 1.5);
	mObstacles.push_back(obstacle);
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
	graphics->ScaleTransform(mClientScaleY, mClientScaleY);
	for (auto obstacle : mObstacles) 
	{
		obstacle->Draw(graphics);
	}
	mUmbrella->Draw(graphics);
}

/**
* Updates each part of the game (pipes, umbrella, etc.)
* \param elapsedTime The time since the last update
*/
void CGame::Update(double elapsedTime) 
{
	if (mObstacleTime == 0) 
	{
		
	}
	mUmbrella->Update(elapsedTime);
}

/** Jumps the umbrella
*/
void CGame::jump() 
{
	mUmbrella->SetVelocity(-50);
}