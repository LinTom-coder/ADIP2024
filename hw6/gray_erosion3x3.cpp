#include "Header.h"

void gray_erosion3x3(unsigned char* input_img, unsigned char* output_img, int width, int height) {
	int struct_ele[] = {1, 1, 1,
						1, 1, 1,
						1, 1, 1 };
	double v[] = { 0,0,0,0,0,0,0,0,0 };
	unsigned char* input_temp = new unsigned char[(width + 2) * (height + 2)];
	padding(input_img, input_temp, width, height, 1);

	for (int x = 1; x < height + 1; ++x) {
		for (int y = 1; y < width; ++y) {
			v[0] = input_temp[(x - 1) * (width + 2) + (y - 1)] - struct_ele[0];
			v[1] = input_temp[(x - 1) * (width + 2) + (y)] - struct_ele[1];
			v[2] = input_temp[(x - 1) * (width + 2) + (y + 1)] - struct_ele[2];
			v[3] = input_temp[(x)* (width + 2) + (y - 1)] - struct_ele[3];
			v[4] = input_temp[(x)* (width + 2) + (y)] - struct_ele[4];
			v[5] = input_temp[(x)* (width + 2) + (y + 1)] - struct_ele[5];
			v[6] = input_temp[(x + 1) * (width + 2) + (y - 1)] - struct_ele[6];
			v[7] = input_temp[(x + 1) * (width + 2) + (y)] - struct_ele[7];
			v[8] = input_temp[(x + 1) * (width + 2) + (y + 1)] - struct_ele[8];

			double min = 256;
			for (int i = 0; i < 9; ++i) {
				if (v[i] <= min) {
					min = v[i];
				}
			}
			output_img[(x - 1) * width + (y - 1)] = min <= 0 ? 0 : min;
		}
	}
}