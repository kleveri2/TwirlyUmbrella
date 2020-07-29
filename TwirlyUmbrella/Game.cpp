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
	mObstacleTime += elapsedTime;
	if ((mObstacleTime) > 4) 
	{
		AddObstacle();
		mObstacleTime = 0;
	}
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
	std::shared_ptr<CObstacle> obstacle = std::make_shared<CObstacle>(1850, randomY, mUmbrella->GetHeight() * 1.75, ObstacleVelocity);
	mObstacles.push_back(obstacle);
}