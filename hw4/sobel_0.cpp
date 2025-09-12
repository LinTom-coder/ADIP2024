#include "Header.h"

void sobel_0(unsigned char* input_img, unsigned char* output_img, int width, int height) {
	double kernel_3x3[] = { -1, -2, -1,
							 0,  0,  0,
							 1,  2,  1 };
	int padding_size = 1;
	int padding_width = width + 2 * padding_size;
	int padding_height = height + 2 * padding_size;
	int size = padding_width * padding_height;
	unsigned char* padding_img = new unsigned char[size];
	//printf("hi\n");
	padding(input_img, padding_img, width, height, padding_size);
	//printf("hi\n");

	for (int x = padding_size; x < height + padding_size; x++) {
		for (int y = padding_size; y < width + padding_size; y++) {
			double value = 0;
			value += kernel_3x3[0] * padding_img[(x - 1) * padding_width + (y - 1)];
			value += kernel_3x3[1] * padding_img[(x - 1) * padding_width + (y)];
			value += kernel_3x3[2] * padding_img[(x - 1) * padding_width + (y + 1)];
			value += kernel_3x3[3] * padding_img[(x)*padding_width + (y - 1)];
			value += kernel_3x3[4] * padding_img[(x)*padding_width + (y)];
			value += kernel_3x3[5] * padding_img[(x)*padding_width + (y + 1)];
			value += kernel_3x3[6] * padding_img[(x + 1) * padding_width + (y - 1)];
			value += kernel_3x3[7] * padding_img[(x + 1) * padding_width + (y)];
			value += kernel_3x3[8] * padding_img[(x + 1) * padding_width + (y + 1)];
			value = (value < 0) ? 0 : value;
			value = (value >= 255) ? 255 : value;
			output_img[(x - padding_size) * width + (y - padding_size)] = value;
		}
	}
	delete[] padding_img;
}