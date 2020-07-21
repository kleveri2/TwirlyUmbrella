#include "pch.h"
#include "Game.h"
#include <memory>
CGame::CGame()
{
	mUmbrella = std::make_shared<CUmbrella>();
}

void CGame::OnDraw(Gdiplus::Graphics* graphics)
{
	mUmbrella->Draw(graphics);
}
