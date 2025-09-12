#include "Header.h"

void gray_dilation3x3(unsigned char* input_img, unsigned char* output_img, int width, int height) {
	int struct_ele[] = {1, 1, 1,
						1, 1, 1,
						1, 1, 1 };
	double v[] = {0,0,0,0,0,0,0,0,0};
	unsigned char* input_temp = new unsigned char[(width + 2) * (height + 2)];
	padding(input_img, input_temp, width, height, 1);

	for (int x = 1; x < height + 1; ++x) {
		for (int y = 1; y < width; ++y) {
			v[0] = struct_ele[0] + input_temp[(x - 1) * (width + 2) + (y - 1)];
			v[1] = struct_ele[1] + input_temp[(x - 1) * (width + 2) + (y)];
			v[2] = struct_ele[2] + input_temp[(x - 1) * (width + 2) + (y + 1)];
			v[3] = struct_ele[3] + input_temp[(x) * (width + 2) + (y - 1)];
			v[4] = struct_ele[4] + input_temp[(x) * (width + 2) + (y)];
			v[5] = struct_ele[5] + input_temp[(x) * (width + 2) + (y + 1)];
			v[6] = struct_ele[6] + input_temp[(x + 1) * (width + 2) + (y - 1)];
			v[7] = struct_ele[7] + input_temp[(x + 1) * (width + 2) + (y)];
			v[8] = struct_ele[8] + input_temp[(x + 1) * (width + 2) + (y + 1)];

			double max = 0;
			for (int i = 0; i < 9; ++i) {
				if (v[i] > max) {
					max = v[i];
				}
			}
			output_img[(x - 1) * width + (y - 1)] = max >= 255 ? 255 : max;
		}
	}
}