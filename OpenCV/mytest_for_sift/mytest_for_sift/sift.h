//vs2010+opencv2.2
//zdd
//zddmail@gmail.com
//Just for fun



#ifndef SIFT_H
#define SIFT_H

#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
using namespace cv;
using namespace std;

typedef double pixel_t;//��������

//��ʼsigma
#define INIT_SIGMA 0.5

//sigma 
#define SIGMA 1.6

//intervals
#define INTERVALS 3

//r
#define RATIO 10

#define MAX_INTERPOLATION_STEPS 5 

//|D(x^)| < 0.03   0.03��ֵ��̫��
#define DXTHRESHOLD 0.04

//bins = 36
#define ORI_HIST_BINS 36    

#define ORI_SIGMA_TIMES 1.5

#define ORI_WINDOW_RADIUS 3.0 * ORI_SIGMA_TIMES 

#define ORI_SMOOTH_TIMES 2

#define ORI_PEAK_RATIO 0.8

#define FEATURE_ELEMENT_LENGTH 128

#define DESCR_HIST_BINS 8

#define DESCR_WINDOW_WIDTH 4

#define DESCR_SCALE_ADJUST 3

#define DESCR_MAG_THR 0.2

#define INT_DESCR_FCTR 512.0


struct Keypoint
{
	int octave; //�ؼ���������
	int interval;// �ؼ������ڲ�

	double offset_interval;//������Ĳ������

	int x; //x,y����,����octave��interval��ȡ�Ĳ���ͼ��
	int y;

	//scale = sigma0*pow(2.0, o+s/S)
	double scale; //�ռ�߶�����

	double dx; //���������꣬�����걻���ų�ԭͼ���С 
	double dy;

	double offset_x;
	double offset_y;

	//��˹���������ڸ���߶����꣬��ͬ�����ͬ���sigmaֵ��ͬ
	//�ؼ�������������ڳ߶�
	double octave_scale; //offset_i;

	double ori;//����

	int descr_length;
	double descriptor[FEATURE_ELEMENT_LENGTH]; //

	double val;//��ֵ
};

void write_features(const vector<Keypoint>&features, const char*file);

void testInverse3D();

void write_pyr(const vector<Mat>& pyr, const char* dir);

void DrawKeyPoints(Mat &src, vector<Keypoint>& keypoints);

const char* GetFileName(const char* dir, int i);

void ConvertToGray(const Mat& src, Mat& dst);

void DownSample(const Mat& src, Mat& dst);

void UpSample(const Mat& src, Mat& dst);

void GaussianTemplateSmooth(const Mat &src, Mat &dst, double);

void GaussianSmooth2D(const Mat &src, Mat &dst, double sigma);

void GaussianSmooth(const Mat &src, Mat &dst, double sigma);

void Sift(const Mat &src, vector<Keypoint>& features, double sigma = SIGMA, int intervals = INTERVALS);

void CreateInitSmoothGray(const Mat &src, Mat &dst, double);

void GaussianPyramid(const Mat &src, vector<Mat>&gauss_pyr, int octaves, int intervals, double sigma);

void Sub(const Mat& a, const Mat& b, Mat & c);

void DogPyramid(const vector<Mat>& gauss_pyr, vector<Mat>& dog_pyr, int octaves, int intervals);

void DetectionLocalExtrema(const vector<Mat>& dog_pyr, vector<Keypoint>& extrema, int octaves, int intervals);

void DrawSiftFeatures(Mat& src, vector<Keypoint>& features);

#endif