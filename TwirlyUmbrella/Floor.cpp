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
	mTexture->DrawTexture(graphics, GetXPos() - mTexture->GetWidth() / 2, \
		GetYPos() - mTexture->GetHeight()/2);

}

/** Changes the floor's position
* \param elapsedTime The time since the last update
*/
void CFloor::Update(double elapsedTime)
{
	SetXPos(GetXPos() - (mXVelocity * elapsedTime));
}