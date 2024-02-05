#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;

void showResized(const std::string& path)
{
    Mat img = imread(path);
    Mat imgResized;

    std::cout << img.size() << std::endl;

    resize(img, imgResized, Size(100, 100));
    // OR with scale
    // resize(img, imgResized, Size(), 0.5, 0.5);

    imshow("Regular image", img);
    waitKey(0);

    imshow("Resized image", imgResized);
    waitKey(0);
}

void showCropped(const std::string& path)
{
    Mat img = imread(path);
    Mat imgCropped;

    // x, y, width, height
    // x, y for top left point of the window
    Rect roi(100, 100, 300, 250);
    imgCropped = img(roi);

    imshow("Cropped image", imgCropped);
    waitKey(0);
}

int main(int argc, char** argv)
{
    const std::string img_path = "../../RESOURCES/test.png";

    // showResized(img_path);
    showCropped(img_path);
}