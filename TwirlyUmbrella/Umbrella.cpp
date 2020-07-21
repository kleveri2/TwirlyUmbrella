#include "pch.h"
#include "Umbrella.h"
#include <string>

const std::wstring UmbrellaTest(L"images/Umbrellatest.png");

CUmbrella::CUmbrella()
{

	mUmbrellaImage = std::unique_ptr<Gdiplus::Bitmap>(Gdiplus::Bitmap::FromFile(UmbrellaTest.c_str()));
}

void CUmbrella::Draw(Gdiplus::Graphics* graphics)
{
    int x = 0;
    graphics->DrawImage(mUmbrellaImage.get(),50,50, mUmbrellaImage->GetWidth(), mUmbrellaImage->GetHeight());
}
