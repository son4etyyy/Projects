#include<iostream>
#include <fstream>
#include <cstdlib>
#include<cmath>
#include "ImageProcessor.h"
#include<cstdio>
#include<cmath>
using namespace std;

ImageProcessor::ImageProcessor()
{

}

ImageProcessor::ImageProcessor(string img_name)
{
    bitmap_image image(img_name);
    this->image = image;
}

/**
@return the instance of the internal object image
*/
bitmap_image ImageProcessor::getImage() const
{
    return this->image;
}


/**
Transform a single pixel into grayscale
@param x  - the x-coordinate of the pixel
@param y  - the y-coordinate of the pixel
@param red -  the amount of red in the pixel
@param green - the amount of green in the pixel
@param blue - the amount of blue in the pixel
*/
void ImageProcessor::convertToGrayScalePixel(size_t x, size_t y,unsigned char& red,unsigned char& green,unsigned char& blue)
{
    int scale = (int)(round(0.114 * (1.0 * blue)) + round(0.587 * (1.0*green)) + round(0.299 *(1.0*red)));
    image.set_pixel(x,y,scale,scale,scale);
}

/**
Converts the whole image in grayscalse using the internal member function convertToGrayScalePixel
*/
void ImageProcessor::convertToGrayScale()
{
    unsigned int height = image.height();
    unsigned int width = image.width();
    for (size_t x = 0; x < height; x++) // For each scan line
    {
        for (size_t y = 0; y < width; y++) // For each pixel
        {
            unsigned char red;
            unsigned char green;
            unsigned char blue;
            image.get_pixel(x,y,red,green,blue);
            convertToGrayScalePixel(x,y,red,green,blue);
        }
    }
}
/**
Noise reduction by Gaussian filter with size 5x5 with sigma = 1.0 and coefficients in matrix taken from
http://homepages.inf.ed.ac.uk/rbf/HIPR2/gsmooth.htm
*/
void ImageProcessor::gaussianBlur()
{
    int i, j,k,l;

    int kernelSize = 5;
    double sigma = 1.;
    vector<vector<double> > gaussianKernel(kernelSize);
    for(i = 0; i < kernelSize; i++)
    {
        gaussianKernel[i].resize(kernelSize);
    }

    //Change the sigma and the kernel
    //http://homepages.inf.ed.ac.uk/rbf/HIPR2/gsmooth.htm

    gaussianKernel[0][0] = 2.0/159;
    gaussianKernel[0][1] = 4.0/159;
    gaussianKernel[0][2] = 5.0/159;
    gaussianKernel[0][3] = 4.0/159;
    gaussianKernel[0][4] = 2.0/159;
    gaussianKernel[1][0] = 4.0/159;
    gaussianKernel[1][1] = 9.0/159;
    gaussianKernel[1][2] = 12.0/159;
    gaussianKernel[1][3] = 9.0/159;
    gaussianKernel[1][4] = 4.0/159;
    gaussianKernel[2][0] = 5.0/159;
    gaussianKernel[2][1] = 12.0/159;
    gaussianKernel[2][2] = 15.0/159;
    gaussianKernel[2][3] = 12.0/159;
    gaussianKernel[2][4] = 5.0/159;
    gaussianKernel[3][0] = 4.0/159;
    gaussianKernel[3][1] = 9.0/159;
    gaussianKernel[3][2] = 12.0/159;
    gaussianKernel[3][3] = 9.0/159;
    gaussianKernel[3][4] = 4.0/159;
    gaussianKernel[4][0] = 2.0/159;
    gaussianKernel[4][1] = 4.0/159;
    gaussianKernel[4][2] = 5.0/159;
    gaussianKernel[4][3] = 4.0/159;
    gaussianKernel[4][4] = 2.0/159;
    int Limit = kernelSize/2;

    int width = image.width();
    int height = image.height();

    for (i = 0; i < width; i++)
    {
        for (j = 0; j <height; j++)
        {
            double redSum  = 0;
            double greenSum  = 0;
            double blueSum  = 0;
            for (k = -Limit; k <= Limit; k++)
            {

                for (l = -Limit; l <= Limit; l++)
                {
                    if(i+k >= 0 && i+k < height && j+l >= 0 && j+l < width)
                    {
                        unsigned char red;
                        unsigned char green;
                        unsigned char blue;
                        image.get_pixel((size_t)(i + k),(size_t)(j+l),red,green,blue);
                        redSum+=(1.0*red)*gaussianKernel[Limit + k][Limit + l];
                        greenSum+=(1.0*green)*gaussianKernel[Limit + k][Limit + l];
                        blueSum+=(1.0*blue)*gaussianKernel[Limit + k][Limit + l];
                    }

                }
            }
            unsigned char redFinal = (unsigned char)floor(redSum/sigma);
            unsigned char greenFinal = (unsigned char)floor(greenSum/sigma);
            unsigned char blueFinal = (unsigned char)floor(blueSum/sigma);
            image.set_pixel((size_t)i, (size_t)j, redFinal, greenFinal, blueFinal);
        }

    }
}

/**
Saves a new image with name - the value of outputImageName
@param outputImage the name of the new image
*/
void ImageProcessor::saveImage(string outputImageName)
{
    outputImageName = outputImageName + ".bmp";
    image.save_image(outputImageName);
}

