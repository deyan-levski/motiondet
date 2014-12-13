#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
 
int main(int argc, char *argv[])
{
cv::Mat frame;
cv::Mat oldframe;
cv::Mat dest;
cv::Mat back;
cv::Mat fore;
cv::VideoCapture cap(0);
cv::BackgroundSubtractorMOG2 bg;
bg.setInt("nmixtures", 3);
bg.setBool("detectShadows", false);

int flag=1;

std::vector<std::vector<cv::Point> > contours;

cv::namedWindow("Frame");
cv::namedWindow("Background");

cap.read(frame);

while (1)
{
        cap.read(frame);

//if (flag == 1) {
//oldframe=frame;
//flag=0;
//}
//else if (flag==0) {
//cap.read(frame);
//flag=1;
//}

    bg.operator ()(frame, fore);
    bg.getBackgroundImage(back);
    cv::erode(fore, fore, cv::Mat());
    cv::dilate(fore, fore, cv::Mat());
    cv::findContours(fore, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    cv::drawContours(frame, contours, -1, cv::Scalar(0, 0, 255), 2);
    //cvSub(frame,oldframe,dest);
//    dest=(frame-oldframe);
    
    cv::imshow("Frame", frame);
 //   cv::imshow("FrameOld", oldframe);
    cv::imshow("FrameDiff", dest);
    if (cv::waitKey(1000) >= 0) break;
}

return 0; 
}
