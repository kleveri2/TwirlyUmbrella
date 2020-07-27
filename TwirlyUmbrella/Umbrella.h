/**
 * \file Umbrella.h
 *
 * \author Griffin Klevering
 */

#pragma once
#include "GameObject.h"
#include <memory>

/** Class for the umbrella the users plays with
*
* Space jumps
*/
class CUmbrella : public CGameObject
{
public:

    CUmbrella() = delete;

    CUmbrella(double XStart, double YStart);

    void Draw(Gdiplus::Graphics* graphics);

    void Update(double elapsedTime);

    /** Sets the falling velocity
    * \param newV The new velocity
    */
    void SetVelocity(double newV) { mYVelocity = newV; }

private:

    ///The image of the umbrella being used
    std::unique_ptr<Gdiplus::Bitmap> mUmbrellaImage;
    /// The Y velocity of the umbrella
    double mYVelocity;
};

