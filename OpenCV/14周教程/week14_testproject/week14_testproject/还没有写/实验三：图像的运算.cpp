#pragma warning(disable: 4819)//warning C4819: ���ļ����������ڵ�ǰ����ҳ(936)�б�ʾ���ַ����뽫���ļ�����Ϊ Unicode ��ʽ�Է�ֹ���ݶ�ʧ
#include <opencv2\opencv.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;

//����д�ˣ��Լ�����
//http://wiki.opencv.org.cn/index.php/Cxcore�������
int main()
{
	Mat camera_img = imread("���.JPG");
	if (camera_img.empty())
	{
		cout << "error";
		return -1;
	}



	return 0;
}
