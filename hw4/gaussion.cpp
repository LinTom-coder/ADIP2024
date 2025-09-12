#include "Header.h"

void gaussion(unsigned char* input_img, unsigned char* output_img, int width, int height, double sigma) {
	int padding_size = 2;
	int padding_width = width + 2 * padding_size;
	int padding_height = height + 2 * padding_size;
	int size = padding_width * padding_height;
	unsigned char* padding_img = new unsigned char[size];
	//printf("hihi\n");
	padding(input_img, padding_img, width, height, padding_size);
	//printf("hihi\n");
	
	double kernel_5x5[5][5];
	double total = 0;
	for (int i = -2; i <= 2; i++) {
		for (int j = -2; j <= 2; j++) {
			kernel_5x5[i + 2][j + 2] = exp(-(i * i + j * j) / (2 * sigma * sigma)) / (2 * 3.14 * sigma * sigma);
			total += kernel_5x5[i + 2][j + 2];
		}
	}

	for (int x = padding_size; x < height + padding_size; x++) {
		for (int y = padding_size; y < width + padding_size; y++) {
			double value = 0;
			value += kernel_5x5[0][0] * padding_img[(x - 2) * padding_width + (y - 2)];
			value += kernel_5x5[0][1] * padding_img[(x - 2) * padding_width + (y - 1)];
			value += kernel_5x5[0][2] * padding_img[(x - 2) * padding_width + (y)];
			value += kernel_5x5[0][3] * padding_img[(x - 2) * padding_width + (y + 1)];
			value += kernel_5x5[0][4] * padding_img[(x - 2) * padding_width + (y + 2)];

			value += kernel_5x5[1][0] * padding_img[(x - 1) * padding_width + (y - 2)];
			value += kernel_5x5[1][1] * padding_img[(x - 1) * padding_width + (y - 1)];
			value += kernel_5x5[1][2] * padding_img[(x - 1) * padding_width + (y)];
			value += kernel_5x5[1][3] * padding_img[(x - 1) * padding_width + (y + 1)];
			value += kernel_5x5[1][4] * padding_img[(x - 1) * padding_width + (y + 2)];

			value += kernel_5x5[2][0] * padding_img[(x)*padding_width + (y - 2)];
			value += kernel_5x5[2][1] * padding_img[(x)*padding_width + (y - 1)];
			value += kernel_5x5[2][2] * padding_img[(x)*padding_width + (y)];
			value += kernel_5x5[2][3] * padding_img[(x)*padding_width + (y + 1)];
			value += kernel_5x5[2][4] * padding_img[(x)*padding_width + (y + 2)];

			value += kernel_5x5[3][0] * padding_img[(x + 1) * padding_width + (y - 2)];
			value += kernel_5x5[3][1] * padding_img[(x + 1) * padding_width + (y - 1)];
			value += kernel_5x5[3][2] * padding_img[(x + 1) * padding_width + (y)];
			value += kernel_5x5[3][3] * padding_img[(x + 1) * padding_width + (y + 1)];
			value += kernel_5x5[3][4] * padding_img[(x + 1) * padding_width + (y + 2)];

			value += kernel_5x5[4][0] * padding_img[(x + 2) * padding_width + (y - 2)];
			value += kernel_5x5[4][1] * padding_img[(x + 2) * padding_width + (y - 1)];
			value += kernel_5x5[4][2] * padding_img[(x + 2) * padding_width + (y)];
			value += kernel_5x5[4][3] * padding_img[(x + 2) * padding_width + (y + 1)];
			value += kernel_5x5[4][4] * padding_img[(x + 2) * padding_width + (y + 2)];

			value /= total;
			output_img[(x - padding_size) * width + (y - padding_size)] = value;
		}
	}
	delete[] padding_img;
}


//	(-2,-2), (-2,-1), (-2,0), (-2,1), (-2,2),
//	(-1,-2), (-1,-1), (-1,0), (-1,1), (-1,2),
//	(0,-2),  (0,-1),  (0,0),  (0,1),  (0,2),
//	(1,-2),  (1,-1),  (1,0),  (1,1),  (1,2),
//	(2,-2),  (2,-1),  (2,0),  (2,1),  (2,2)

/*
	double kernel[5][5];
	double total = 0;
	for (int i = -2; i <= 2; i++) {
		for (int j = -2; j <= 2; j++) {
			kernel[i + 2][j + 2] = exp(-(i * i + j * j) / (2 * sigma * sigma)) / (2 * 3.14 * sigma * sigma);
			total += kernel[i + 2][j + 2];
		}
	}

	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			double value = 0;
			if (x - 2 >= 0 && y - 2 >= 0) {
				value += kernel[0][0] * input_img[(x - 2) * width + (y - 2)];
			}
			if (x - 2 >= 0 && y - 1 >= 0) {
				value += kernel[0][1] * input_img[(x - 2) * width + (y - 1)];
			}
			if (x - 2 >= 0) {
				value += kernel[0][2] * input_img[(x - 2) * width + (y)];
			}
			if (x - 2 >= 0 && y + 1 < width) {
				value += kernel[0][3] * input_img[(x - 2) * width + (y + 1)];
			}
			if (x - 2 >= 0 && y + 2 < width) {
				value += kernel[0][4] * input_img[(x - 2) * width + (y + 2)];
			}
			if (x - 1 >= 0 && y - 2 >= 0) {
				value += kernel[1][0] * input_img[(x - 1) * width + (y - 2)];
			}
			if (x - 1 >= 0 && y - 1 >= 0) {
				value += kernel[1][1] * input_img[(x - 1) * width + (y - 1)];
			}
			if (x - 1 >= 0) {
				value += kernel[1][2] * input_img[(x - 1) * width + (y)];
			}
			if (x - 1 >= 0 && y + 1 < width) {
				value += kernel[1][3] * input_img[(x - 1) * width + (y + 1)];
			}
			if (x - 1 >= 0 && y + 2 < width) {
				value += kernel[1][4] * input_img[(x - 1) * width + (y + 2)];
			}
			if (y - 2 >= 0) {
				value += kernel[2][0] * input_img[(x)*width + (y - 2)];
			}
			if (y - 1 >= 0) {
				value += kernel[2][1] * input_img[(x)*width + (y - 1)];
			}
			if (y + 1 < width) {
				value += kernel[2][3] * input_img[(x)*width + (y + 1)];
			}
			if (y + 2 < width) {
				value += kernel[2][4] * input_img[(x)*width + (y + 2)];
			}
			if (x + 1 < height && y - 2 >= 0) {
				value += kernel[3][0] * input_img[(x + 1) * width + (y - 2)];
			}
			if (x + 1 < height && y - 1 >= 0) {
				value += kernel[3][1] * input_img[(x + 1) * width + (y - 1)];
			}
			if (x + 1 < height) {
				value += kernel[3][2] * input_img[(x + 1) * width + (y)];
			}
			if (x + 1 < height && y + 1 < width) {
				value += kernel[3][3] * input_img[(x + 1) * width + (y + 1)];
			}
			if (x + 1 < height && y + 2 < width) {
				value += kernel[3][4] * input_img[(x + 1) * width + (y + 2)];
			}
			if (x + 2 < height && y - 2 >= 0) {
				value += kernel[4][0] * input_img[(x + 2) * width + (y - 2)];
			}
			if (x + 2 < height && y - 1 >= 0) {
				value += kernel[4][1] * input_img[(x + 2) * width + (y - 1)];
			}
			if (x + 2 < height) {
				value += kernel[4][2] * input_img[(x + 2) * width + (y)];
			}
			if (x + 2 < height && y + 1 < width) {
				value += kernel[4][3] * input_img[(x + 2) * width + (y + 1)];
			}
			if (x + 2 < height && y + 2 < width) {
				value += kernel[4][4] * input_img[(x + 2) * width + (y + 2)];
			}
			value += kernel[2][2] * input_img[(x)*width + (y)];

			value /= total;
			output_img[x * width + y] = value;
*/