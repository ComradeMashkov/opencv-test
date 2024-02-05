#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;

void showGrayPicture(const std::string& path)
{
    Mat img = imread(path);
    Mat imgGray;

    // Writes data from img to imgGray but with convertion to gray color
    cvtColor(img, imgGray, COLOR_BGR2GRAY);

    imshow("Image gray", imgGray);
    waitKey(0);
}

void showGaussianBlur(const std::string& path)
{
    Mat img = imread(path);
    Mat imgBlured;

    // Writes data from img to imgGray but with convertion to gray color
    // 5, 0 - stddev
    GaussianBlur(img, imgBlured, Size(7, 7), 10);

    imshow("Image blured", imgBlured);
    waitKey(0);
}

void showCanny(const std::string& path)
{
    Mat img = imread(path);
    Mat imgCanny;

    // 50, 150 - thresholds
    Canny(img, imgCanny, 50, 150);

    imshow("Image canny", imgCanny);
    waitKey(0);
}

void showDilated(const std::string& path)
{
    Mat img = imread(path);
    Mat imgDil;

    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    dilate(img, imgDil, kernel);

    imshow("Image dilated", imgDil);
    waitKey(0);
}

int main(int argc, char** argv)
{
    const std::string img_path = "../../RESOURCES/test.png";

    // showGrayPicture(img_path);
    // showGaussianBlur(img_path);
    // showCanny(img_path);
    showDilated(img_path);

    return 0;
}