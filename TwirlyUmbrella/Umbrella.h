/**
 * \file Umbrella.h
 *
 * \author Griffin Klevering
 */

#pragma once
#include "GameObject.h"
#include "Texture.h"
#include <vector>
#include <memory>

/** Class for the umbrella the users plays with
*
* Space jumps
*/
class CUmbrella : public CGameObject
{
public:

    CUmbrella() = delete;

    CUmbrella(double XStart, double YStart, double RotationRate);

    void Draw(Gdiplus::Graphics* graphics);

    void Update(double elapsedTime);

    void Fall(double elapsedTime);

    void Reset(double xStart, double yStart);

    void AddTexture(std::shared_ptr<CTexture> tex);

    /** Sets the falling velocity
    * \param newV The new velocity
    */
    void SetVelocity(double newV) { mYVelocity = newV; }

    /** Gets the height of the umbrella
    * \param return height of the umbrella image
    */
    double GetHeight() { return mTextures[mTextureNum]->GetHeight(); }

    /** Gets the height of the umbrella
    * \param return the width of the umbrella image
    */
    double GetWidth() { return mTextures[mTextureNum]->GetWidth(); }

private:
    ///The top obstacle image
    std::vector<std::shared_ptr<CTexture>> mTextures;

    ///The current texture
    int mTextureNum;

     /// Where the texture was last changed on the y axis
    double mLastChange;

    ///How far the umbrella has rotated during game over
    double mRotation;
    ///The rate inwhich it roates during game over
    double mRotationRate; 
    /// The Y velocity of the umbrella
    double mYVelocity;
};

