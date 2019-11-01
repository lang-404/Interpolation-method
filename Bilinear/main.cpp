#include <string.h>
#include <iostream>
#include"resize.h"


using namespace cv;

int main()
{
	// 读取图片
	Mat mat_Src = imread("C:/Users/19611/Desktop/size.png");
	int iw = mat_Src.cols;
	int ih = mat_Src.rows;

	Mat Neares_Dst = Mat(Size(iw * 4, ih * 4), CV_8UC3);
	Mat Bilinear_Dst = Mat(Size(iw*4,ih*4),CV_8UC3);


	double Neares_dx = (double)mat_Src.cols / Neares_Dst.cols;
	double Neares_dy = (double)mat_Src.rows / Neares_Dst.rows;

	double Bilinear_dx = (double)mat_Src.cols / Bilinear_Dst.cols;
	double Bilinear_dy = (double)mat_Src.rows / Bilinear_Dst.rows;

	// 最近邻插值
	Resize(mat_Src, Neares_Dst, Neares_dx, Neares_dy);
	imwrite("C:/Users/19611/Desktop/Neares_resize.png", Neares_Dst);

	// 双线性插值
	Besize(mat_Src, Bilinear_Dst, Bilinear_dx, Bilinear_dy);
	imwrite("C:/Users/19611/Desktop/Bilinear_resize.png", Bilinear_Dst);



	return 0;
}