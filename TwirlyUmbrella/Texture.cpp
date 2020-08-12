/**
 * \file Texture.cpp
 *
 * \author Griffin Klevering
 */

#include "pch.h"
#include "Texture.h"
#include <string>

 /** Initializer
 */
CTexture::CTexture(std::wstring file)
{
	mImage = std::unique_ptr<Bitmap>(Bitmap::FromFile(file.c_str()));
}


/** Draws a texture
* \param graphics  the GDI graphics being drawn on
* \pram x the x coordinate of the texture
* \param y the y coordinate of the texture
*/
void CTexture::DrawTexture(Graphics* graphics, double x, double y)
{
	graphics->DrawImage(mImage.get(), static_cast<float>(x), \
		static_cast<float>(y), static_cast<float>(mImage->GetWidth()), \
		static_cast<float>(mImage->GetHeight()));
}
