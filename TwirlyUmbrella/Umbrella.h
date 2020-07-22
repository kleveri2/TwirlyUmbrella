#pragma once
#include <memory>
class CUmbrella
{
public:

    CUmbrella();

    void Draw(Gdiplus::Graphics* graphics);

private:
    std::unique_ptr<Gdiplus::Bitmap> mUmbrellaImage;

    double mXPos;
    double mYPos;
};

