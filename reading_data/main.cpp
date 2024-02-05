#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;

void openImage(const std::string& path)
{
    // Matrix to store n dimensional arrays, image in our case
    Mat img = imread(path);

    // Function to show image
    imshow("Image", img);

    // Without that function a window will close immediately
    waitKey(0);
}

void openVideo(const std::string& path)
{
    // Class for capturing videos
    VideoCapture cap(path);

    Mat img;

    while (true)
    {
        cap.read(img);
        imshow("Video", img);
        waitKey(1);
    }
}

void openVideoFromWebcam()
{
    VideoCapture cap(0);

    Mat img;

    while (true)
    {
        cap.read(img);
        imshow("Webcam", img);
        waitKey(1);
    }
}

int main(int argc, char** argv)
{
    // const std::string image_path = "../../RESOURCES/test.png";
    // openImage(image_path);

    // const std::string video_path = "../../RESOURCES/test_video.mp4";
    // openVideo(video_path);

    openVideoFromWebcam();
}