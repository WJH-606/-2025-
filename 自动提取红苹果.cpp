#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>

using namespace std;
using namespace cv;
int main()
{
	Mat image = imread("C:/Users/25404/Desktop/视觉组考核题所需图片/apple.jpg");
	if (image.empty())
	{
		cout << "图片无法加载：" << endl;
		return -1;
	}
	Mat original = image.clone();
	Mat hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	Scalar lower_red1(0, 100, 80);
	Scalar upper_red1(12, 255, 255);
	Scalar lower_red2(165, 100, 80);
	Scalar upper_red2(180, 255, 255);
	Mat mask1, mask2, red_mask;
	inRange(hsv, lower_red1, upper_red1, mask1);
	inRange(hsv, lower_red2, upper_red2, mask2);
	red_mask = mask1 | mask2;
	vector<vector<Point>>contours;
	vector<Vec4i> hierarchy;
	findContours(red_mask, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	double max_area = 0;
	int max = -1;
	for (size_t i = 0; i < contours.size(); i++)
	{
		double area = contourArea(contours[i]);
		if (area > max_area)
		{
			max_area = area;
			max = i;
		}
	}
	Mat result = original.clone();
	if (max != -1)
	{
		drawContours(result, contours, max, Scalar(0, 255, 0), 2);
		Rect bounding_rect = boundingRect(contours[max]);
		rectangle(result, bounding_rect, Scalar(255, 0, 0), 3);
	}
	namedWindow("apple");
	imshow("apple", image);
	imshow("apple2", result);
	waitKey(0);
	return 0;
}