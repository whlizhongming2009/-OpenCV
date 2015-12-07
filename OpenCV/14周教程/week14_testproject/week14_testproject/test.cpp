#pragma warning(disable: 4819)//warning C4819: 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失
#include <opencv2\opencv.hpp>
#include <opencv\cv.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
int main()
{
	//Mat camera_img = imread("相机.JPG");
	
	Mat camera_img = imread("art2.jpg");
	if (camera_img.empty())
	{
		cout << "error";
		return -1;
	}
	Mat camera_gray_img;//此时数据是空的
	cvtColor(camera_img, camera_gray_img, CV_BGR2GRAY);//将多通道图像转换为单通道的图像

	Mat sobelx;
	Sobel(camera_gray_img, sobelx, CV_32F, 1, 0);//sobel边缘检测
	imshow("1", sobelx);
	waitKey();

	//重新分配灰度
	double minVal, maxVal;
	minMaxLoc(sobelx, &minVal, &maxVal); //find minimum and maximum intensities
	//防止越界，线性运算要分两步走
	//convertTo的作用对像素灰度进行线性运算：
	//m(x,y) = saturate_cast(α(*this)(x,y)+β)
	//img.convertTo(dest, ddepth,α,β);
	sobelx.convertTo(sobelx, CV_32F, 1, -minVal);
	Mat draw;
	sobelx.convertTo(draw, CV_8U, 255.0 / (maxVal - minVal),0);

	namedWindow("边缘检测", WND_PROP_AUTOSIZE);
	imshow("边缘检测", draw);
	waitKey();


	return 0;
}
