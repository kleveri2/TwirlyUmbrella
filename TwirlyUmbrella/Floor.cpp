#include "pch.h"
#include "Floor.h"

/** Constructor
* \param XStart The starting x location of the floor
* \param YStart the starting Y location of the floor
*/
CFloor::CFloor(int XStart, int YStart, double XVelocity, std::shared_ptr<CTexture> texture)
{
	SetXPos(XStart);
	SetYPos(YStart);
	mXVelocity = XVelocity;
	mTexture = texture;
}

/** Draws the floor
* \param graphics  the GDI graphics being drawn on
*/
void CFloor::Draw(Graphics* graphics)
{
	auto state = graphics->Save();
	graphics->SetInterpolationMode(InterpolationModeNearestNeighbor);
	mTexture->DrawTexture(graphics, GetXPos() - mTexture->GetWidth() / 2 , \
		GetYPos() - mTexture->GetHeight()/2);

	graphics->Restore(state);

}

/** Changes the floor's position
* \param elapsedTime The time since the last update
*/
void CFloor::Update(double elapsedTime)
{
	//The floor updates then sees if its sister floor needs to be shifted back.
	//This avoids a problem where the floor would move off screen, shift back to be behind itssister, but its sister would move
	//And be one second in front of the other
	SetXPos(GetXPos() - (mXVelocity * elapsedTime));
	if (mOtherFloor->GetXPos() + mTexture->GetWidth() / 2  <= 0) 
	{
		mOtherFloor->SetXPos(GetXPos() + mTexture->GetWidth()-1);
	}
}