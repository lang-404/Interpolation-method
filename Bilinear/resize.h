
#ifndef RESIZE_H
#define RESIZE_H

#include <stdio.h>
#include <string.h>
#include <opencv2/opencv.hpp>
using namespace cv;

// ����ڲ�ֵ
void Resize(Mat input_file, Mat output_file, double dx, double dy);

// ˫���Բ�ֵ
void Besize(Mat input_file, Mat& output_file, double dx, double dy);



#endif
