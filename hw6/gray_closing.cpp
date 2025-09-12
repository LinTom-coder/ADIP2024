#include "Header.h"

void gray_closing(unsigned char* input_img, unsigned char* output_img, int width, int height, int num) {
	unsigned char* output_temp = new unsigned char[(width) * (height)];
	/*gray_dilation3x3(input_img, output_temp, width, height);
	gray_erosion3x3(output_temp, output_img, width, height);*/
	gray_dilation(input_img, output_temp, width, height, num);
	gray_erosion(output_temp, output_img, width, height, num);
	delete[] output_temp;
}