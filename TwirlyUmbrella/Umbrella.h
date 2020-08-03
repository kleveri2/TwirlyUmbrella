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

    /** Gets the height of the umbrella
    * \param return height of the umbrella image
    */
    double GetHeight() { return mUmbrellaImage->GetHeight(); }

    /** Gets the height of the umbrella
    * \param return the width of the umbrella image
    */
    double GetWidth() { return mUmbrellaImage->GetWidth(); }

private:

    ///The image of the umbrella being used
    std::unique_ptr<Gdiplus::Bitmap> mUmbrellaImage;
    /// The Y velocity of the umbrella
    double mYVelocity;
};

