#pragma once
#ifndef MYHEADER_H
#define MYHEADER_H

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <time.h>
#include <windows.h>
//#include <opencv2/opencv.hpp>
//#include <opencv2/highgui/highgui.hpp>

void hw2_1_1_nearest();
void hw2_1_1_bilinear();
void hw2_1_2();
void hw2_2();
void hw2_3_1();
void hw2_3_2();
void hw2_3_2_test();
//void hw1_2_b();

void bilinear(unsigned char*, unsigned char*, int, int, int, int, float);
void nearest(unsigned char*, unsigned char*, int, int, int, int, float);
double MSE(unsigned char*, unsigned char*, int, int);
double PSNR(double, unsigned char*, int, int);
void D4(unsigned char*, int, int, int*, int, int, int);

void hw_3_2();

#endif  // MYHEADER_H

