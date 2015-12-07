#pragma warning(disable: 4819)//warning C4819: 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失
#include <opencv2\opencv.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
int main()
{
	Mat camera_img = imread("相机.JPG");//看数据！！！
	Mat phone_img = imread("手机.JPG");//看数据！！！
	if (camera_img.empty())
	{
		cout << "error";
		return -1;
	}

	imshow("相机", camera_img);
	Mat camera_gray_img = imread("相机.JPG", ImreadModes::IMREAD_GRAYSCALE);//读取为灰度图像
	imshow("相机（灰度图）", camera_gray_img);
	imwrite("save.jpg", camera_gray_img);//图片保存，只能支持png、jpg、tiff格式的单通道或3通道的图片（看函数说明）。

	if (phone_img.empty())
	{
		cout << "error";
		return -1;
	}

	imshow("手机", phone_img);


	waitKey();

	return 0;
}
