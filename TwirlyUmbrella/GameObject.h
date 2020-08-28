/**
 * \file GameObject.h
 *
 * \author Griffin Klevering
 */

#pragma once
#include "Texture.h"
#include <memory>

/**
 * Base class for all objects in the game
 *
 * Consists of obstacles and the umbrella
 */
class CGameObject
{
public:

    /** Draw an object
    * Pure virtual
    * \param graphics The graphics being drawn upon
    */
    virtual void Draw(Gdiplus::Graphics* graphics) = 0;

    /** Update an object
    * Pure virtual
    * \param elapsedTime the time since the last update
    */
    virtual void Update(double elapsedTime) = 0;

    /**Gets the X Position
    * \return The X Coordinate
    */
    double GetXPos() { return mXPos; }

    /**Gets the Y Position
    * \return The y Coordinate
    */
    double GetYPos() { return mYPos; }

    /** Sets the X Position
    * \param The X Coordinate
    */
    void SetXPos(double newP) { mXPos = newP; }

    /** Sets the Y Position
    * \param The Y Coordinate
    */
    void SetYPos(double newP) { mYPos = newP; }

    /** Gets the width of the texture
   * \returns The width in pixels
   */
    double GetWidth() { return mTexture->GetWidth(); }

    /** Gets the height of the texture
    * \returns The height in pixels
    */
    double GetHeight() { return mTexture->GetHeight(); }

    /** Sets the texture
    * \param tex The texture being set
    */
    void SetTexture(std::shared_ptr<CTexture> tex) { mTexture = tex; }

    /** Gets the texture
    * \returns The texture pointer
    */
    std::shared_ptr<CTexture> GetTexture() { return mTexture; }

private:
    ///The X coordinate of the object
    double mXPos = 0;
    ///The Y coordinate of the object
    double mYPos = 0;

    ///The texture
    std::shared_ptr<CTexture> mTexture;
};

