#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void on_MouseHandle(int event, int x, int y, int flags, void* param);	//鼠标响应函数

Mat frame;			//定义一个全局的Mat变量，用于存储图像

int main()
{
	namedWindow("picture", cv::WINDOW_NORMAL);
	setMouseCallback("picture", on_MouseHandle);	//关联鼠标响应函数

	frame = imread("picture2.jpg");	//读取图片
	imshow("picture", frame);  //显示图片
	waitKey(0);            //直到有按键按下
	return 0;
}

void on_MouseHandle(int event, int x, int y, int flags, void* param)
{
	static Point pt1, pt2;
	static int start = 0;
	Mat img;

	frame.copyTo(img);   //这样复制两个变量不会使用同一幅图像
	switch (event)
	{
		case EVENT_LBUTTONDOWN:		//左键按下消息
		{
			start = 1;
			pt1 = Point(x, y);
			cout << "start: (" << pt1.x << ", " << pt1.y << ")" << endl;
			break;
		}
		case cv::EVENT_MOUSEMOVE:		//鼠标移动事件
		{
			pt2 = Point(x, y);
			if (start == 1)
			{
				rectangle(img, pt1, pt2, Scalar(255, 0, 0), 10, 80, 0);
				imshow("picture", img);  //显示当前已画矩形的图片
				Vec3b pixel = img.at<Vec3b>(y, x);//从图像中获取此点的BGR值（图像在内存中以行优先存储的）
				int blue = pixel[0];
				int green = pixel[1];
				int red = pixel[2];
				cout << "坐标：(" << pt2.x << "," << pt2.y << ")" ;
				cout << "BGR：(" << blue << "," << green << ","<< red <<")" << endl;
			}
			break;
		}
		case cv::EVENT_LBUTTONUP:		//鼠标左键弹起事件
		{
			start = 0;
			pt2 = Point(x, y);
			cout << "end: (" << pt2.x << ", " << pt2.y << ")" << endl;
			Point centre;
			centre.x = (pt1.x + pt2.x) / 2;
			centre.y = (pt1.y + pt2.y) / 2;
			cout << "矩形的中点：" << "(" << centre.x << "," << centre.y << ")" << endl;
			rectangle(img, pt1, pt2, Scalar(255, 0, 0), 10, 80, 0);
			imshow("picture", img);  //显示当前已画矩形的图片
			string filename = "image" + to_string(time(0)) + ".jpg";
			imwrite(filename, img);//保存图像
			break;
		}

	}
}

