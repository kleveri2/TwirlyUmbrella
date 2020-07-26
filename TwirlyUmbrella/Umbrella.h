#pragma once
#include <memory>
class CUmbrella
{
public:

    CUmbrella();

    void Draw(Gdiplus::Graphics* graphics);

    void Update(double elapsedTime);

private:
    ///The image of the umbrella being used
    std::unique_ptr<Gdiplus::Bitmap> mUmbrellaImage;
    ///The X coordinate of the umbrella
    double mXPos;
    ///The y boordinate of the umbrella
    double mYPos;

    double mVelocity;
};

