#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap;//实例化一个VideoCapture类
	cap.open(0);//打开摄像头
	if (!cap.isOpened())//检查摄像头是否正常开启
	{
		std::cout << "无法正常打开摄像头" << std::endl;
		return -1;
	}
	double fps = cap.get(CAP_PROP_FPS);//读取帧数
	std::cout << "fps" << fps << std::endl;//显示帧数
	while (1)//持续开启摄像头
	{
		cv::Mat frame;
		bool rSuccess = cap.read(frame);//获得当前帧
		if (!rSuccess)//检查当前帧是否正常获取
		{
			std::cout << "不能从视频中读取帧" << std::endl;
			break;
		}
		else
		{
			cv::imshow("frame", frame);//显示当前帧
		}
		waitKey(30);
	}
}