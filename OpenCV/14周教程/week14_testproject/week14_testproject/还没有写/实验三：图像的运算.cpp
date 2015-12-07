#pragma warning(disable: 4819)//warning C4819: 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失
#include <opencv2\opencv.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;

//懒得写了，自己看吧
//http://wiki.opencv.org.cn/index.php/Cxcore数组操作
int main()
{
	Mat camera_img = imread("相机.JPG");
	if (camera_img.empty())
	{
		cout << "error";
		return -1;
	}



	return 0;
}
