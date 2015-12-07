#pragma warning(disable: 4819)//warning C4819: ���ļ����������ڵ�ǰ����ҳ(936)�б�ʾ���ַ����뽫���ļ�����Ϊ Unicode ��ʽ�Է�ֹ���ݶ�ʧ
#include <opencv2\opencv.hpp>
#include <opencv\cv.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
int main()
{
	//Mat camera_img = imread("���.JPG");
	
	Mat camera_img = imread("art2.jpg");
	if (camera_img.empty())
	{
		cout << "error";
		return -1;
	}
	Mat camera_gray_img;//��ʱ�����ǿյ�
	cvtColor(camera_img, camera_gray_img, CV_BGR2GRAY);//����ͨ��ͼ��ת��Ϊ��ͨ����ͼ��

	Mat sobelx;
	Sobel(camera_gray_img, sobelx, CV_32F, 1, 0);//sobel��Ե���
	imshow("1", sobelx);
	waitKey();

	//���·���Ҷ�
	double minVal, maxVal;
	minMaxLoc(sobelx, &minVal, &maxVal); //find minimum and maximum intensities
	//��ֹԽ�磬��������Ҫ��������
	//convertTo�����ö����ػҶȽ����������㣺
	//m(x,y) = saturate_cast(��(*this)(x,y)+��)
	//img.convertTo(dest, ddepth,��,��);
	sobelx.convertTo(sobelx, CV_32F, 1, -minVal);
	Mat draw;
	sobelx.convertTo(draw, CV_8U, 255.0 / (maxVal - minVal),0);

	namedWindow("��Ե���", WND_PROP_AUTOSIZE);
	imshow("��Ե���", draw);
	waitKey();


	return 0;
}
