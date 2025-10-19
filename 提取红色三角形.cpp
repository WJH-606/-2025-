#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("C:/Users/25404/Desktop/视觉组考核题所需图片/picture1.jpg");
	if (img.empty())
	{
		cout << "请确认图像文件名称是否正确" << endl;
		return -1;
	}
	Mat bigimg1, bigimg2;
	resize(img, bigimg1, Size(1280, 720), 0, 0, INTER_CUBIC);//让图片大小变为1280^720,放大图像
	Mat hsv;
	cvtColor(bigimg1, hsv, COLOR_BGR2HSV);//从一般默认的BGR—>HSV
	Mat mask1, mask2, redMask;
	inRange(hsv, Scalar(0, 150, 150), Scalar(10, 255, 255), mask1);
	inRange(hsv, Scalar(170, 150, 150), Scalar(180, 255, 255), mask2);//定义红色三角形的HSV范围
	redMask = mask1 | mask2;//只处理红色区域
	Mat redOnly;
	bitwise_and(bigimg1, bigimg1, redOnly, redMask);//提取红色三角形
	Mat binaryResult = Mat::zeros(redOnly.size(), CV_8UC1);//创建一个与bigimg3图像尺寸相同的全黑色一通道黑白图像，并将其赋值给result
	binaryResult.setTo(255, redMask);//红色三角形变白，其余为黑
	Mat edges, bigimg3,result;
	GaussianBlur(binaryResult, edges, Size(3, 3), 5);
	Canny(edges, bigimg3, 100, 200, 3);
	Mat BlueEdges;
	cvtColor(bigimg3, BlueEdges, COLOR_GRAY2BGR);
	BlueEdges.setTo(Scalar(255, 0, 0), bigimg3);
	namedWindow("img");
	imshow("img", img);//展示普通照片
	waitKey(0);
	imshow("黑白图像", binaryResult);//展示黑白图像
	waitKey(0);
	imshow("边缘提取图片", bigimg3);//展示边缘提取图片
	waitKey(0);
	return 0;
}