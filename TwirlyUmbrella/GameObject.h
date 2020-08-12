/**
 * \file GameObject.h
 *
 * \author Griffin Klevering
 */

#pragma once
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
    virtual void Draw(Gdiplus::Graphics* graphics) {}

    /** Update an object
    * Pure virtual
    * \param elapsedTime the time since the last update
    */
    virtual void Update(double elapsedTime) = 0;

    /** Gets the height of an image
    * Pure virtual
    */
    virtual double GetHeight() = 0;

    /** Gets the width of an image
    * Pure virtual
    */
    virtual double GetWidth() = 0;

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


private:
    ///The X coordinate of the object
    double mXPos = 0;
    ///The Y coordinate of the object
    double mYPos = 0;
};

