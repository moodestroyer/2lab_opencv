#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main() {

	Mat img = imread("C:/Users/User/Downloads/11.jpg");
	Mat hsv, lab, yuv, xyz, gray;

	if (img.empty()) {
		std::cout << "Не удалось отобразить изображение" << std::endl;
		return -1;
	}

	imshow("Original", img);
	waitKey(0);

	cvtColor(img, hsv, COLOR_BGR2HSV);
	imshow("HSV", hsv);
	waitKey(0);

	cvtColor(img, lab, COLOR_BGR2Lab);
	imshow("Lab", lab);
	waitKey(0);

	cvtColor(img, yuv, COLOR_BGR2YUV);
	imshow("YUV", yuv);
	waitKey(0);

	cvtColor(img, xyz, COLOR_BGR2XYZ);
	imshow("XYZ", xyz);
	waitKey(0);

	return 0;
}