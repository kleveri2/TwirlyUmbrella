/**
* \file ScrollingObject.h
*
* \author Griffin Klevering
*/

#pragma once
#include "GameObject.h"

/**The base class for an object that scrolls horizontally */
class CScrollingObject : public CGameObject
{
public:
	/** Sets the x velocity
	* \param newV The new velocity
	*/
	void SetVelocity(double newV) { mXVelocity = newV; }

	/** Gets the x velocity
	* \param return the x velocity in pixels
	*/
	double GetVelocity() { return mXVelocity; }

private:
	///The x velocity of a scrolling object
	double mXVelocity;
};

