#pragma warning(disable: 4819)//warning C4819: ���ļ����������ڵ�ǰ����ҳ(936)�б�ʾ���ַ����뽫���ļ�����Ϊ Unicode ��ʽ�Է�ֹ���ݶ�ʧ
#include <opencv2\opencv.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
int main()
{
	Mat camera_img = imread("���.JPG");//�����ݣ�����
	Mat phone_img = imread("�ֻ�.JPG");//�����ݣ�����
	if (camera_img.empty())
	{
		cout << "error";
		return -1;
	}

	imshow("���", camera_img);
	Mat camera_gray_img = imread("���.JPG", ImreadModes::IMREAD_GRAYSCALE);//��ȡΪ�Ҷ�ͼ��
	imshow("������Ҷ�ͼ��", camera_gray_img);
	imwrite("save.jpg", camera_gray_img);//ͼƬ���棬ֻ��֧��png��jpg��tiff��ʽ�ĵ�ͨ����3ͨ����ͼƬ��������˵������

	if (phone_img.empty())
	{
		cout << "error";
		return -1;
	}

	imshow("�ֻ�", phone_img);


	waitKey();

	return 0;
}
