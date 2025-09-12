#pragma once
#ifndef MYHEADER_H
#define MYHEADER_H

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <math.h>
//#include <time.h>
//#include <windows.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

void hw4_1();
void hw4_2_1();
void hw4_2_2();
void hw4_3_1();
void hw4_3_2();
void hw4_3_3();
void hw4_3_4();
//void hw1_2_b();

void local_histo(unsigned char*, unsigned char*, int, int, int);
void gaussion(unsigned char*, unsigned char*, int, int, double);
void mean3x3(unsigned char*, unsigned char*, int, int);
void mean5x5(unsigned char*, unsigned char*, int, int);
void padding(unsigned char*, unsigned char*, int, int, int);
void neighbor4(unsigned char*, unsigned char*, int, int);
void neighbor8(unsigned char*, unsigned char*, int, int);
void sobel_0(unsigned char*, unsigned char*, int, int);
void sobel_90(unsigned char*, unsigned char*, int, int);

#endif  // MYHEADER_H

#pragma once
#pragma once
