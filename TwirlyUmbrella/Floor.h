/**
 * \file Floor.h
 *
 * \author Griffin Klevering
 */

#pragma once
#include "GameObject.h"
#include "Texture.h"
/**Class for the moving floor */
class CFloor : public CGameObject
{
public:

	CFloor(int XStart, int YStart, double XVelocity, std::shared_ptr<CTexture> texture);

	void Draw(Graphics* graphics);

	void Update(double elapsedTime);

    /** Gets the width of the floor image
* \returns The width in pixels
*/
    double GetWidth() { return mTexture->GetWidth(); }

    /** Gets the height of the floor image
    * \returns The height in pixels
    */
    double GetHeight() { return mTexture->GetWidth(); }

private:
	///The texture
	std::shared_ptr<CTexture> mTexture;


	double mXVelocity; ///The velocity of the floor going left

};

