#pragma once
#ifndef MYHEADER_H
#define MYHEADER_H

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <math.h>
#include <time.h>
//#include <windows.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <fstream>

void hw5_1();
void hw5_2_1();
void hw5_2_2();
void hw5_3_1();
void hw5_3_2();
//void hw4_3_3();
//void hw4_3_4();
//void hw1_2_b();

using namespace cv;
using namespace std;

void padding0(unsigned char*, unsigned char*, int, int, int);
void centrelize(std::vector<float>&, int, int);
double PSNR(double, unsigned char*, int, int);
double MSE(unsigned char*, unsigned char*, int, int);
void LPF(unsigned char*, unsigned char*, unsigned char*, int, int, int);
void HPF(unsigned char*, unsigned char*, unsigned char*, int, int, int);
void BHPF(unsigned char*, unsigned char*, unsigned char*, int, int, int, int);
void BLPF(unsigned char*, unsigned char*, unsigned char*, int, int, int, int);

#endif  // MYHEADER_H

#pragma once

