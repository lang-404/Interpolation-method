
#ifndef RESIZE_H
#define RESIZE_H

#include <stdio.h>
#include <string.h>
#include <opencv2/opencv.hpp>
using namespace cv;

// 最近邻插值
void Resize(Mat input_file, Mat output_file, double dx, double dy);

// 双线性插值
void Besize(Mat input_file, Mat& output_file, double dx, double dy);



#endif
