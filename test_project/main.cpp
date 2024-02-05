#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./main <image_path>" << std::endl;
        return -1;
    }

    Mat image;
    image = imread(argv[1], IMREAD_COLOR);

    if (!image.data)
    {
        std::cerr << "No image data" << std::endl;
        return -1;
    }

    imshow("Display Image", image);

    waitKey(0);

    return 0;
}