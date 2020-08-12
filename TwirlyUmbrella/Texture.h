/**
 * \file Texture.h
 *
 * \author Griffin Klevering
 */

#pragma once

#include <memory>
#include <string>
using namespace Gdiplus;
 /** The class with the real bitmaps of the things the game draws
 * So the game doesn't need to load in textures each time one is created, it just draws this png
 */
class CTexture
{
public:
	CTexture(std::wstring);
    void DrawTexture(Graphics* graphics, double x, double y);

    /** Gets the width of the  image
    * \returns The width in pixels
    */
    double GetWidth() { return mImage->GetWidth(); }

    /** Gets the height of the  image
    * \returns The height in pixels
    */
    double GetHeight() { return mImage->GetHeight(); }

private:
	std::shared_ptr<Gdiplus::Bitmap> mImage;
};

