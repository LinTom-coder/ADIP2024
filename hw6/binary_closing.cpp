#include "Header.h"

void binary_closing(unsigned char* input_img, unsigned char* output_img, int width, int height, int num) {
	unsigned char* output_temp = new unsigned char[(width) * (height)];
	binary_dilation(input_img, output_temp, width, height, num);
	binary_erosion(output_temp, output_img, width, height, num);

	delete[] output_temp;
}