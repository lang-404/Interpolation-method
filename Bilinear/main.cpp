#include <string.h>
#include <iostream>
#include"resize.h"


using namespace cv;

int main()
{
	// ��ȡͼƬ
	Mat mat_Src = imread("C:/Users/19611/Desktop/size.png");
	int iw = mat_Src.cols;
	int ih = mat_Src.rows;
	Mat mat_Dst = Mat(Size(iw*4,ih*4),CV_8UC3);
	
	Mat opencvRet;

	double dx = (double)mat_Src.cols / mat_Dst.cols;
	double dy = (double)mat_Src.rows / mat_Dst.rows;

	// ����ڲ�ֵ
	//Resize(mat_Src,mat_Dst,dx,dy);

	// ˫���Բ�ֵ
	Besize(mat_Src, mat_Dst, dx, dy);
	imwrite("C:/Users/19611/Desktop/bresize.png", mat_Dst);

	// opencv resize�����Ŵ�
	//resize(mat_Src, opencvRet,Size(iw*2,ih*2));
	//imwrite("C:/Users/19611/Desktop/opencv_resize.png", opencvRet);


	return 0;
}