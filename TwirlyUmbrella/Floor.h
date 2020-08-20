/**
 * \file Floor.h
 *
 * \author Griffin Klevering
 */

#pragma once
#include "GameObject.h"
#include "Texture.h"
#include <memory>
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
    double GetHeight() { return mTexture->GetHeight(); }

	/** Sets the floor that this floor connects to
	* \param OF the other floor being set
	*/
	void SetOtherFloor(std::shared_ptr<CFloor> OF) { mOtherFloor = OF.get(); }

private:
	///The texture
	std::shared_ptr<CTexture> mTexture;

	/// The other floor this floor connects to
	CFloor* mOtherFloor;


	double mXVelocity; ///The velocity of the floor going left

};

