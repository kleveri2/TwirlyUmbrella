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

///The standard velocity of the obstacle
const double ObstacleVelocity = 100;

///The size of the gap between obstacles
const double GapSize = 1.75;

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
	mGenerator = generator;
	//Add an initial obstacle
	AddObstacle();

	//The next obstacle to be hit is the first one
	mNextObstacle = mObstacles[0];
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
	//Add an obstacle every x seconds
	mObstacleTime += elapsedTime;
	if ((mObstacleTime) > 4) 
	{
		AddObstacle();
		mObstacleTime = 0;
	}
	//Update the position of each obstacle
	for (auto obstacle : mObstacles) 
	{
		obstacle->Update(elapsedTime);
	}
	//Only one obstacle will be off screen at a time, so we only need to worry about the first one
	auto it = mObstacles.begin();
	if ((*it)->GetXPos() + (*it)->GetWidth()  <= 0) 
	{
		mObstacles.erase(it);
	}
	mUmbrella->Update(elapsedTime);
	TestCollision();
}

/** Jumps the umbrella
*/
void CGame::jump() 
{
	mUmbrella->SetVelocity(-50);
}

/** Adds an obstacle with a random Y to the game
*/
void CGame::AddObstacle() 
{
	std::uniform_int_distribution<int> distribution(MinimumY, MaximumY);
	int randomY = distribution(mGenerator);
  	mObstacleTime = 0;
	std::shared_ptr<CObstacle> obstacle = std::make_shared<CObstacle>(1850, randomY, mUmbrella->GetHeight() * GapSize, ObstacleVelocity);
	mObstacles.push_back(obstacle);
}

/** Tests to see if the umbrella has hit an obstacle
* \returns If the umbrella has made collision with an obstacle or not
*/
bool CGame::TestCollision() 
{
	//The umbrella hit box
	double umbrellaTop = mUmbrella->GetYPos() - (mUmbrella->GetHeight()) / 2;
	double umbrellaBot = mUmbrella->GetYPos() + (mUmbrella->GetHeight()) / 2;
	double umbrellaLeft = mUmbrella->GetXPos() - (mUmbrella->GetWidth()) / 2;
	double umbrellaRight = mUmbrella->GetXPos() + (mUmbrella->GetWidth()) / 2;

	//The top obstacle hit box
	double upObstacleTop = mNextObstacle->GetYPos() - (mUmbrella->GetHeight() / 2) - (GapSize * mUmbrella->GetHeight());
	double upObstacleBot = mNextObstacle->GetYPos() + (mUmbrella->GetHeight() / 2) - (GapSize * mUmbrella->GetHeight());
	double upObstacleLeft = mNextObstacle->GetXPos() - (mNextObstacle->GetWidth()/2);
	double upObstacleRight = mNextObstacle->GetXPos() + (mNextObstacle->GetWidth() / 2);

	//The bottom obstacle hit box
	double downObstacleTop = mNextObstacle->GetYPos() - (mUmbrella->GetHeight() / 2) + (GapSize * mUmbrella->GetHeight());
	double downObstacleBot = mNextObstacle->GetYPos() + (mUmbrella->GetHeight() / 2) + (GapSize * mUmbrella->GetHeight());
	double downObstacleLeft = mNextObstacle->GetXPos() - (mNextObstacle->GetWidth() / 2);
	double downObstacleRight = mNextObstacle->GetXPos() + (mNextObstacle->GetWidth() / 2);

	//If the top obstacle is hit
	if (umbrellaTop < upObstacleBot && umbrellaRight > upObstacleLeft&& umbrellaLeft < upObstacleRight) 
	{
		return true;
	}
	//If the bottom obstacle is hit
	if (umbrellaBot > downObstacleTop && umbrellaRight > downObstacleLeft && umbrellaLeft < downObstacleRight)
	{
 		return true;
	}
	return false;
}