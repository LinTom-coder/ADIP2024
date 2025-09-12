#include "Header.h"

void hw6_1() {
	/**********************crack600x400**********************/
	char  input_img600x400[] = "crack600x400.raw";
	FILE* file600x400;
	int width600 = 600;
	int height400 = 400;
	int size1 = width600 * height400;
	unsigned char* img_crack600x400 = new unsigned char[size1];
	unsigned char* img_crack_binary = new unsigned char[size1];
	unsigned char* img_crack_gray_temp = new unsigned char[size1];

	file600x400 = fopen(input_img600x400, "rb");
	if (file600x400 == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_crack600x400, 1, size1, file600x400);

	char output_img_binary600x400[] = "hw6_1_binary600x400.raw";
	FILE* output_file_binary600x400;
	unsigned char* output_binary_600x400 = new unsigned char[size1];
	memset(output_binary_600x400, 0, width600 * height400 * sizeof(unsigned char));

	char output_img_gray600x400[] = "hw6_1_gray600x400.raw";
	FILE* output_file_gray600x400;
	unsigned char* output_gray_600x400 = new unsigned char[size1];

	for (int x = 0; x < height400; ++x) {
		for (int y = 0; y < width600; ++y) {
			if (img_crack600x400[x * width600 + y] >= 128) {
				img_crack_binary[x * width600 + y] = 255;
			}
			else {
				img_crack_binary[x * width600 + y] = 0;
			}
		}
	}
	binary_closing(img_crack_binary, output_binary_600x400, width600, height400, 3);
	/*for (int x = 0; x < height400; ++x) {
		for (int y = 0; y < width600; ++y) {
			if (output_binary_600x400[x * width600 + y] >= 128) {
				output_binary_600x400[x * width600 + y] = 0;
			}
			else {
				output_binary_600x400[x * width600 + y] = 255;
			}
		}
	}*/

	gray_closing(img_crack600x400, output_gray_600x400, width600, height400, 3);

	output_file_binary600x400 = fopen(output_img_binary600x400, "wb");
	fwrite(output_binary_600x400, 1, height400 * width600, output_file_binary600x400);
	delete[] output_binary_600x400;
	fclose(output_file_binary600x400);

	output_file_gray600x400 = fopen(output_img_gray600x400, "wb");
	fwrite(output_gray_600x400, 1, height400 * width600, output_file_gray600x400);
	delete[] output_gray_600x400;
	fclose(output_file_gray600x400);

	delete[] img_crack600x400;
	delete[] img_crack_binary;
	fclose(file600x400);

	/**********************crack540x360**********************/
	char  input_img540x360[] = "crack540x360.raw";
	FILE* file540x360;
	int width540 = 540;
	int height360 = 360;
	int size2 = width540 * height360;
	unsigned char* img_crack540x360 = new unsigned char[size2];
	unsigned char* img_crack_binary2 = new unsigned char[size2];

	file540x360 = fopen(input_img540x360, "rb");
	if (file540x360 == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_crack540x360, 1, size2, file540x360);

	char output_img_binary540x360[] = "hw6_1_binary540x360.raw";
	FILE* output_file_binary540x360;
	unsigned char* output_binary_540x360 = new unsigned char[size2];
	char output_img_gray540x360[] = "hw6_1_gray540x360.raw";
	FILE* output_file_gray540x360;
	unsigned char* output_gray_540x360 = new unsigned char[size2];


	for (int x = 0; x < height360; ++x) {
		for (int y = 0; y < width540; ++y) {
			if (img_crack540x360[x * width540 + y] >= 128) {
				img_crack_binary2[x * width540 + y] = 255;
			}
			else {
				img_crack_binary2[x * width540 + y] = 0;
			}
		}
	}
	binary_closing(img_crack_binary2, output_binary_540x360, width540, height360, 3);
	/*for (int x = 0; x < height360; ++x) {
		for (int y = 0; y < width540; ++y) {
			if (output_binary_540x360[x * width540 + y] >= 128) {
				output_binary_540x360[x * width540 + y] = 0;
			}
			else {
				output_binary_540x360[x * width540 + y] = 255;
			}
		}
	}*/

	gray_closing(img_crack540x360, output_gray_540x360, width540, height360, 5);

	output_file_binary540x360 = fopen(output_img_binary540x360, "wb");
	fwrite(output_binary_540x360, 1, height360 * width540, output_file_binary540x360);
	delete[] output_binary_540x360;
	fclose(output_file_binary540x360);

	output_file_gray540x360 = fopen(output_img_gray540x360, "wb");
	fwrite(output_gray_540x360, 1, height360* width540, output_file_gray540x360);
	delete[] output_gray_540x360;
	fclose(output_file_gray540x360);

	delete[] img_crack540x360;
	delete[] img_crack_binary2;
	fclose(file600x400);

}