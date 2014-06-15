#include <iostream>
#include "ImageProcessor.h"
using namespace std;

/**
Asks the user for the desirable command
@param filename  - the name of a file we will process
@param command  - the selected command
*/
void readCommand(string filename, string& command)
{
    cout << "How do you want to proccess the image " << filename << "?" << endl;
    cout << "Enter A if you want to turn it into grayscale." << endl;
    cout << "Enter B if you want to apply gaussian blur method." << endl;
    cin >> command;
}

/**
Reads the name of a file and makes an object of type ImageProcessor
@param filename  - the name of a file to be read
@param img_pr  - the new object of type ImageProcessor
*/
void readImageName(string& filename, ImageProcessor& img_pr)
{
    cout << "Please enter the file name: ";
    cin >> filename;
    ImageProcessor img_proc(filename);
    img_pr = img_proc;
}

int main()
{
    string filename;
    ImageProcessor img_proc;
    readImageName(filename, img_proc);
    bool fileNotFound = !img_proc.getImage();
    while(fileNotFound)
    {
        readImageName(filename, img_proc);
        fileNotFound = !img_proc.getImage();
    }

    string command;
    readCommand(filename, command);

    while(command != "A" && command!="B")
    {
        readCommand(filename, command);
    }
    cout << "Please enter the name of your new image: ";
    string outputImage;
    cin >> outputImage;

    if(command == "A")
        img_proc.convertToGrayScale();
    else
        img_proc.gaussianBlur();

    img_proc.saveImage(outputImage);
    return 0;
}
