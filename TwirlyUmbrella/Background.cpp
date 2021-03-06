#include "pch.h"
#include "Background.h"

/** Constructor
* \param XStart The starting x location of the background
* \param YStart the starting Y location of the background
* \param XVelocity The speed the background moves
* \param texture The texture of the background
*/
CBackground::CBackground(int XStart, int YStart, double XVelocity, std::shared_ptr<CTexture> texture)
{
	SetXPos(XStart);
	SetYPos(YStart);
	SetTexture(texture);
}

/** Draws the background
* \param graphics  the GDI graphics being drawn on
*/
void CBackground::Draw(Graphics* graphics)
{
	auto state = graphics->Save();
	//this makes it not lag horribly
	//graphics->SetCompositingMode(CompositingModeSourceCopy);
	graphics->SetInterpolationMode(InterpolationModeNearestNeighbor);
		GetTexture()->DrawTexture(graphics, GetXPos() - GetTexture()->GetWidth()/2, \
			GetYPos() - GetTexture()->GetHeight()/2);
	graphics->Restore(state);
}

/** Changes the backgrounds
* \param elapsedTime The time since the last update
*/
void CBackground::Update(double elapsedTime)
{
	
}