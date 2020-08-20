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
const double XStart = 200;
const double YStart = 500;
///The rate the umbrella rotate in game over
const double rrate = 200;

///The maximum and minimum locations of the center of the gap between the pillars
const int MaximumY = 750;
const int MinimumY = 200;

///The standard velocity of the obstacle
const double ObstacleVelocity = 250;

///The size of the gap between obstacles
const double GapSize = 2.5;

/** 
* Constructor
*/
CGame::CGame()
{
	mObstacleTime = 0;

	CreateTextureMap();

	mUmbrella = std::make_shared<CUmbrella>(XStart, YStart, rrate);
	mUmbrella->AddTexture(mTextures["Umbrella1"]);
	mUmbrella->AddTexture(mTextures["Umbrella2"]);
	mUmbrella->AddTexture(mTextures["Umbrella3"]);
	mUmbrella->AddTexture(mTextures["Umbrella4"]);
	mOverlay = std::make_shared<COverlay>();

	mBackground = std::make_shared<CBackground>(0 + mTextures["Background"]->GetWidth()/2,\
		0 + StandardHeight/2,ObstacleVelocity, mTextures["Background"]);

	std::shared_ptr<CFloor> floor1 = std::make_shared<CFloor>(0 + mTextures["Floor"]->GetWidth() / 2, \
		StandardHeight - mTextures["Floor"]->GetHeight() / 2, \
		ObstacleVelocity, mTextures["Floor"]);
	std::shared_ptr<CFloor> floor2 = std::make_shared<CFloor>(mTextures["Floor"]->GetWidth() * 1.5 -1, \
		StandardHeight - mTextures["Floor"]->GetHeight() / 2, \
		ObstacleVelocity, mTextures["Floor"]);

	floor1->SetOtherFloor(floor2);
	floor2->SetOtherFloor(floor1);

	mFloors.push_back(floor1);
	mFloors.push_back(floor2);


	mGameOver = false;

	mGameStart = true;
}


/** Initializes the textures in the map*/
void CGame::CreateTextureMap() 
{
	mTextures["Umbrella1"] = std::make_shared<CTexture>(L"images/umbrella1.png");
	mTextures["Umbrella2"] = std::make_shared<CTexture>(L"images/umbrella2.png");
	mTextures["Umbrella3"] = std::make_shared<CTexture>(L"images/umbrella3.png");
	mTextures["Umbrella4"] = std::make_shared<CTexture>(L"images/umbrella4.png");
	mTextures["Obstacle"] = std::make_shared<CTexture>(L"images/obstacle2.png");
	mTextures["Background"] = std::make_shared<CTexture>(L"images/background.png");
	mTextures["Floor"] = std::make_shared<CTexture>(L"images/floor3.png");

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
	float clientScaleY = height / StandardHeight;
	float clientScaleX = width / StandardWidth;
	graphics->ScaleTransform(clientScaleX, clientScaleY);
	mBackground->Draw(graphics);
	
	for (auto obstacle : mObstacles) 
	{
		obstacle->Draw(graphics);
	}

	
	for (auto floor : mFloors) 
	{
		floor->Draw(graphics);
	}
	mUmbrella->Draw(graphics);
	mOverlay->DrawScore(graphics);
	if (mGameOver == true) 
	{
		mOverlay->DrawGameOver(graphics);
	}
	if (mGameStart == true) 
	{
		mOverlay->DrawGameStart(graphics);
	}
}

/**
* Updates each part of the game (pipes, umbrella, etc.)
* \param elapsedTime The time since the last update
*/
void CGame::Update(double elapsedTime) 
{
	if (mGameOver == true)
	{
		mUmbrella->Fall(elapsedTime);
	}
	else if (mGameStart == true) 
	{
		///umbrella do something here
		
	}
	else
	{
		
		mBackground->Update(elapsedTime);
		for (auto floor : mFloors)
		{
			floor->Update(elapsedTime);
		}
		//Add an obstacle every x seconds
		mObstacleTime += elapsedTime;
		if ((mObstacleTime) > 2)
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
		if (mObstacles.front()->GetXPos() + mObstacles.front()->GetWidth() <= 0)
		{
			mObstacles.pop_front();
		}
		
		//If it makes it through the next obstacle shifts
		if (mUmbrella->GetXPos() - (mUmbrella->GetWidth()/2) > mNextObstacle->GetXPos() + (mNextObstacle->GetWidth()/2))
		{
			mOverlay->Increment();
			mNextObstacle = mObstacles[1];
		}
		mUmbrella->Update(elapsedTime);
		mGameOver = TestCollision();
	}
	

}

/** Jumps the umbrella
*/
void CGame::jump() 
{
	if (mGameOver == true && mUmbrella->GetYPos() > StandardHeight + 100)
	{
		Reset();
	}
	if (mGameStart == true) 
	{
		GameStart();
		mGameStart = false;
	}
	//We want to start with a jump and jump whenever the game isn't over 
	if (mGameOver == false)
	{
		mUmbrella->SetVelocity(-50);
	}
}

/** Resets the game from a game over
*/
void CGame::Reset() 
{
	//Put the umbrella back in the default position
	mUmbrella->Reset(XStart, YStart);

	//Reset the score
	mOverlay->ResetScore();

	//Destroy and recreate obstacles
	mObstacleTime = 0;
	mObstacles.clear();
	GameStart();

	mGameOver = false;
}

/** Starts the game after a game over or for the first time
*/
void CGame::GameStart() 
{
	//Get a random number through random_device
	std::random_device rd;
	//Use it as a seed
	std::mt19937 generator(rd());
	mGenerator = generator;
	//Add an initial obstacle
	AddObstacle();

	//The next obstacle to be hit is the first one

	mNextObstacle = mObstacles.front();
}

/** Adds an obstacle with a random Y to the game
*/
void CGame::AddObstacle() 
{
	std::uniform_int_distribution<int> distribution(MinimumY, MaximumY);
	int randomY = distribution(mGenerator);
  	mObstacleTime = 0;
	std::shared_ptr<CObstacle> obstacle = std::make_shared<CObstacle>(1850, randomY, mUmbrella->GetHeight() * GapSize, ObstacleVelocity, mTextures["Obstacle"]);
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
	double upObstacleBot = mNextObstacle->GetYPos() - (GapSize * mUmbrella->GetHeight());
	double upObstacleLeft = mNextObstacle->GetXPos() - (mNextObstacle->GetWidth()/2);
	double upObstacleRight = mNextObstacle->GetXPos() + (mNextObstacle->GetWidth() / 2);

	//The bottom obstacle hit box
	double downObstacleTop = mNextObstacle->GetYPos() + (GapSize * mUmbrella->GetHeight());
	double downObstacleLeft = mNextObstacle->GetXPos() - (mNextObstacle->GetWidth() / 2);
	double downObstacleRight = mNextObstacle->GetXPos() + (mNextObstacle->GetWidth() / 2);

	//If the top obstacle is hit
	if (umbrellaTop < upObstacleBot && umbrellaRight > upObstacleLeft && umbrellaLeft < upObstacleRight) 
	{
		mUmbrella->SetVelocity(-10);
 		return true;
	}
	//If the bottom obstacle is hit
	if (umbrellaBot > downObstacleTop && umbrellaRight > downObstacleLeft && umbrellaLeft < downObstacleRight)
	{
		mUmbrella->SetVelocity(-10);
    		return true;
	}
	// Since the floors are the same, we can safely just use the first
	double floorTop = mFloors[0]->GetYPos() - (mFloors[0]->GetHeight() / 2);
	if (umbrellaBot > floorTop) 
	{
		mUmbrella->SetVelocity(-10);
		return true;
	}
	return false;
}