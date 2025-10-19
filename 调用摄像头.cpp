#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
	VideoCapture video(0);
	string filename = "output.mp4";
	int fourcc = VideoWriter::fourcc('m', 'p', '4', 'v');
	double fps =10.0;
	Size frame_size;
	VideoWriter VideoWriter(filename, fourcc, fps, frame_size);
	if (video.isOpened())
	{
		cout << "视频中图像的宽度" << video.get(CAP_PROP_FRAME_WIDTH) << endl;
		cout << "视频中图像的高度" << video.get(CAP_PROP_FRAME_HEIGHT) << endl;
		cout << "视频帧率=" << video.get(CAP_PROP_FPS) << endl;
	}
	else
	{
		cout << "请确认视频文件名称是否正确" << endl;
		return -1;
	}
	Mat frame;
	int frame_count = 0;
	
	while (true)
	{
		video >> frame;
		VideoWriter.write(frame);
		frame_count++;
		namedWindow("录制中");
		VideoWriter.release();
		imshow("录制中", frame);
		waitKey(1000);
	}
	
		return 0;
}