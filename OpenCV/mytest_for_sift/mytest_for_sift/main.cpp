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
		Mat src = imread("D:\\github_repository\\-OpenCV\\OpenCV\\14�̳ܽ�\\week14_testproject\\mytest_for_sift\\�ֻ�.jpg");
		//�ֻ��������������Ƭ̫�󣬺����ᱨ��
		//�������뵽�Ľ���취�ǣ�
		//1���ָ�ͼ���ٴ���OK�����������ܳ��ֱ�Ե������
		//2���ĵ�64λ�Ľ������ȥ������������ǵ����ܻ���Ҫ���ֻ����������ַ������������У�
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