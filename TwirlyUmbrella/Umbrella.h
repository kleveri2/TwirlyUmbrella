/**
 * \file Umbrella.h
 *
 * \author Griffin Klevering
 */

#pragma once
#include "GameObject.h"
#include "Texture.h"
#include <memory>

/** Class for the umbrella the users plays with
*
* Space jumps
*/
class CUmbrella : public CGameObject
{
public:

    CUmbrella() = delete;

    CUmbrella(double XStart, double YStart, double RotationRate, std::shared_ptr<CTexture> texture);

    void Draw(Gdiplus::Graphics* graphics);

    void Update(double elapsedTime);

    void Fall(double elapsedTime);

    void Reset(double xStart, double yStart);

    /** Sets the falling velocity
    * \param newV The new velocity
    */
    void SetVelocity(double newV) { mYVelocity = newV; }

    /** Gets the height of the umbrella
    * \param return height of the umbrella image
    */
    double GetHeight() { return mTexture->GetHeight(); }

    /** Gets the height of the umbrella
    * \param return the width of the umbrella image
    */
    double GetWidth() { return mTexture->GetWidth(); }

private:
    ///The top obstacle image
    std::shared_ptr<CTexture> mTexture;
    ///How far the umbrella has rotated during game over
    double mRotation;
    ///The rate inwhich it roates during game over
    double mRotationRate; 
    /// The Y velocity of the umbrella
    double mYVelocity;
};

