#include "resize.h"
#include <stdio.h>

using namespace cv;

void Resize(Mat input_file, Mat output_file, double dx, double dy)
{
	for (int i = 0; i < output_file.cols; i++)
	{
		int sx = floor(i*dx);
		sx = min(sx, input_file.cols - 1);//防止超出原图像的边界
		for (int j = 0; j < output_file.rows; j++)
		{
			int sy = cvFloor(j*dy);
			sy = min(sy, input_file.rows - 1);
			output_file.at<Vec3b>(j, i) = input_file.at<Vec3b>(sy, sx);
			
		}
	}
	imwrite("C:/Users/19611/Desktop/resize.png",output_file);

}

// 双线性插值
void Besize(Mat input_file, Mat& output_file, double dx, double dy)
{
	int i, j;
	int w = input_file.cols;
	int h = input_file.rows;
	int iw = output_file.cols;
	int ih = output_file.rows;

	for (i = 0; i < iw; i++)
	{
		double fx = (i + 0.5)*dx - 0.5;
		for (j = 0; j < ih; j++)
		{
			double fy = (j + 0.5)*dy - 0.5;
			// 四邻域
			int Lx = (int)fx;
			int Rx = Lx + 1;
			int Ly = (int)fy;
			int Ry = Ly + 1;
			
			Lx = Lx > w - 2 ? w - 2: Lx<0  ? 0:Lx;
			Rx = Rx > w - 1 ? w - 1: Rx<0  ? 0:Rx;
			Ly = Ly > h - 2 ? h - 2: Ly <0 ? 0:Ly ;
			Ry = Ry > h - 1 ? h - 1: Ry <0 ? 0:Ry;

			double u = Rx - fx;
			double v = Ry - fy;

			for (int k = 0; k < 3; k++)
			{
				double r1 = u*input_file.at<Vec3b>(Ly,Lx)[k] + (1 - u)*input_file.at<Vec3b>(Ly,Rx)[k];
				double r2 = u*input_file.at<Vec3b>(Ry,Lx)[k] + (1 - u)*input_file.at<Vec3b>(Ry,Rx)[k];
				output_file.at<Vec3b>(j, i)[k] = v*r1 + (1 - v)*r2;
			}
			
		}// for (j = 0; j < ih; j++)
	}// for (i = 0; i < iw; i++)
}