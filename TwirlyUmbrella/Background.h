/**
 * \file Background.h
 *
 * \author Griffin Klevering
 */

#pragma once
#include "Texture.h"
#include "GameObject.h"
#include <memory>
 /** Class for the background of the game
 * Contains a simple scrolling png
 */
class CBackground : public CGameObject
{

public:

	CBackground() = delete;
	CBackground(int XStart, int YStart, double XVelocity, std::shared_ptr<CTexture> texture);
	void Draw(Graphics* graphics);
	void Update(double elapsedTime);
};

