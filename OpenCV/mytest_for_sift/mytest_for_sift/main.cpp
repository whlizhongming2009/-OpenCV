#include <windows.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2\opencv.hpp>
#include <opencv\cv.hpp>
#include <cv.h>
#include <cxcore.h>
#include "sift.h"
using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
	try
	{
		Mat src = imread("D:\\github_repository\\-OpenCV\\OpenCV\\14周教程\\week14_testproject\\mytest_for_sift\\手机.jpg");
		//手机、相机的两张照片太大，后续会报错
		//现在能想到的解决办法是：
		//1、分割图像再处理（OK）——但可能出现边缘的问题
		//2、改到64位的解决方案去（不过如果考虑到可能还需要在手机上运行这种方案根本不可行）
		if (src.empty())
		{
			cout << "jobs_512.jpg open error! " << endl;
			getchar();
			return -1;
		}

		if (src.channels() != 3)
			return -2;

		vector<Keypoint> features;

		Sift(src, features, 1.6);
		//	DrawKeyPoints(src, features);
		DrawSiftFeatures(src, features);

		write_features(features, "descriptor.txt");

		imshow("src", src);
	}
		catch (Exception &err)
	{
		int a = 0;
		a = 2;
	}

	waitKey();
	return 0;
}