#pragma once
#include <memory>
class CUmbrella
{
public:

    CUmbrella();

    /**
    * Draw the game and its components
    * \param graphics the GDI graphics being drawn on
    * \param width The width of the window
    * \param height The height ofthe window
    */
    void Draw(Gdiplus::Graphics* graphics);

private:
    std::unique_ptr<Gdiplus::Bitmap> mUmbrellaImage;
};

