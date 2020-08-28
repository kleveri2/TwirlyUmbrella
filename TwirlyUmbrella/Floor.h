/**
 * \file Floor.h
 *
 * \author Griffin Klevering
 */

#pragma once
#include "GameObject.h"
#include "Texture.h"
#include "ScrollingObject.h"
#include <memory>
/**Class for the moving floor */
class CFloor : public CScrollingObject
{
public:

	CFloor(int XStart, int YStart, double XVelocity, std::shared_ptr<CTexture> texture);

	void Draw(Graphics* graphics);

	void Update(double elapsedTime);

	/** Sets the floor that this floor connects to
	* \param OF the other floor being set
	*/
	void SetOtherFloor(std::shared_ptr<CFloor> OF) { mOtherFloor = OF.get(); }

private:
	/// The other floor this floor connects to
	CFloor* mOtherFloor;

};

