#include "Header.h"

void mean5x5(unsigned char* input_img, unsigned char* output_img, int width, int height) {
	double kernel_5x5[] = { 1, 1, 1, 1, 1,
							1, 1, 1, 1, 1,
							1, 1, 1, 1, 1,
							1, 1, 1, 1, 1,
							1, 1, 1, 1, 1 };
	int padding_size = 2;
	int padding_width = width + 2 * padding_size;
	int padding_height = height + 2 * padding_size;
	int size = padding_width * padding_height;
	unsigned char* padding_img = new unsigned char[size];
	//printf("hihi\n");
	padding(input_img, padding_img, width, height, padding_size);
	//printf("hihi\n");
	for (int x = padding_size; x < height + padding_size; x++) {
		for (int y = padding_size; y < width + padding_size; y++) {
			double value = 0;
			value += kernel_5x5[0] * padding_img[(x - 2) * padding_width + (y - 2)];
			value += kernel_5x5[1] * padding_img[(x - 2) * padding_width + (y - 1)];
			value += kernel_5x5[2] * padding_img[(x - 2) * padding_width + (y)];
			value += kernel_5x5[3] * padding_img[(x - 2) * padding_width + (y + 1)];
			value += kernel_5x5[4] * padding_img[(x - 2) * padding_width + (y + 2)];
			value += kernel_5x5[5] * padding_img[(x - 1) * padding_width + (y - 2)];
			value += kernel_5x5[6] * padding_img[(x - 1) * padding_width + (y - 1)];
			value += kernel_5x5[7] * padding_img[(x - 1) * padding_width + (y)];
			value += kernel_5x5[8] * padding_img[(x - 1) * padding_width + (y + 1)];
			value += kernel_5x5[9] * padding_img[(x - 1) * padding_width + (y + 2)];
			value += kernel_5x5[10] * padding_img[(x)* padding_width + (y - 2)];
			value += kernel_5x5[11] * padding_img[(x)*padding_width + (y - 1)];
			value += kernel_5x5[13] * padding_img[(x)*padding_width + (y + 1)];
			value += kernel_5x5[14] * padding_img[(x)*padding_width + (y + 2)];
			value += kernel_5x5[15] * padding_img[(x + 1) * padding_width + (y - 2)];
			value += kernel_5x5[16] * padding_img[(x + 1) * padding_width + (y - 1)];
			value += kernel_5x5[17] * padding_img[(x + 1) * padding_width + (y)];
			value += kernel_5x5[18] * padding_img[(x + 1) * padding_width + (y + 1)];
			value += kernel_5x5[19] * padding_img[(x + 1) * padding_width + (y + 2)];
			value += kernel_5x5[20] * padding_img[(x + 2) * padding_width + (y - 2)];
			value += kernel_5x5[21] * padding_img[(x + 2) * padding_width + (y - 1)];
			value += kernel_5x5[22] * padding_img[(x + 2) * padding_width + (y)];
			value += kernel_5x5[23] * padding_img[(x + 2) * padding_width + (y + 1)];
			value += kernel_5x5[24] * padding_img[(x + 2) * padding_width + (y + 2)];

			value += kernel_5x5[12] * padding_img[(x) * padding_width + (y)];
			value /= 25;
			output_img[(x - padding_size) * width + (y - padding_size)] = value;
		}
	}
	delete[] padding_img;
}