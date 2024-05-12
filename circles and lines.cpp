
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>﻿
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat src = imread("C:/Users/User/Downloads/11111.jpg");
    Mat gray, edges, color_dst;
    if (src.empty()) {
        cout << "Error" << endl;
        return -1;
    }

    namedWindow("Original", WINDOW_AUTOSIZE);
    imshow("Original", src);

    cvtColor(src, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, gray, Size(9, 9), 2, 2);
    Canny(gray, edges, 50, 200, 3);
    cvtColor(edges, color_dst, COLOR_GRAY2BGR);

    vector<Vec4i> lines;
    HoughLinesP(edges, lines, 1, CV_PI / 180, 80, 30, 10);
    for (size_t i = 0; i < lines.size(); i++) {
        line(color_dst, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]), Scalar(0, 0, 255), 3, LINE_AA);
    }

    vector<Vec3f> circles;
    HoughCircles(gray, circles, HOUGH_GRADIENT, 2, gray.rows / 4, 200, 100);
    for (size_t i = 0; i < circles.size(); i++) {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);

        circle(color_dst, center, radius, Scalar(255, 0, 0), 3, LINE_AA);
    }

    imshow("Lines and Circles", color_dst);
    waitKey(0);
    return 0;
}