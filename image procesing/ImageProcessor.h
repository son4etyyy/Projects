#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include<string>
#include<vector>
#include "bitmap_image.hpp"
using namespace std;
class ImageProcessor
{
public:
    ImageProcessor();
    ImageProcessor(string img_name);
    bitmap_image getImage()const;
    void convertToGrayScalePixel(size_t x, size_t y,unsigned char& red,unsigned char& green,unsigned char& blue);
    void convertToGrayScale();
    void gaussianBlur();
    void saveImage(string outputImageName);
private:
    string img_name;
    bitmap_image image;
};
#endif // IMAGEPROCESSOR_h
