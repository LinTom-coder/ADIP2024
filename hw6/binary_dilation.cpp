#include "Header.h"

void binary_dilation(unsigned char* input_img, unsigned char* output_img, int width, int height, int num) {
	int half_num = num / 2;
	unsigned char* input_temp = new unsigned char[(width + 2 * half_num) * (height + 2 * half_num)];
	padding(input_img, input_temp, width, height, half_num);

	if (num == 3) {
		for (int x = 1; x < height + 1; ++x) {
			for (int y = 1; y < width + 1; ++y) {
				output_img[(x - 1) * width + (y - 1)] =
					input_temp[(x - 1) * (width + 2) + (y - 1)] ||
					input_temp[(x - 1) * (width + 2) + (y)] ||
					input_temp[(x - 1) * (width + 2) + (y + 1)] ||
					input_temp[(x) * (width + 2) + (y - 1)] ||
					input_temp[(x) * (width + 2) + (y)] ||
					input_temp[(x) * (width + 2) + (y + 1)] ||
					input_temp[(x + 1) * (width + 2) + (y - 1)] ||
					input_temp[(x + 1) * (width + 2) + (y)] ||
					input_temp[(x + 1) * (width + 2) + (y + 1)] ? 255 : 0;
			}
		}
	}
	else if (num == 5) {
		for (int x = 2; x < height + 2; ++x) {
			for (int y = 2; y < width + 2; ++y) {
				output_img[(x - 2) * width + (y - 2)] =
					input_temp[(x - 2) * (width + 4) + (y - 2)] ||
					input_temp[(x - 2) * (width + 4) + (y - 1)] ||
					input_temp[(x - 2) * (width + 4) + (y)] ||
					input_temp[(x - 2) * (width + 4) + (y + 1)] ||
					input_temp[(x - 2) * (width + 4) + (y + 2)] ||
					input_temp[(x - 1) * (width + 4) + (y - 2)] ||
					input_temp[(x - 1) * (width + 4) + (y - 1)] ||
					input_temp[(x - 1) * (width + 4) + (y)] ||
					input_temp[(x - 1) * (width + 4) + (y + 1)] ||
					input_temp[(x - 1) * (width + 4) + (y + 2)] ||
					input_temp[(x) * (width + 4) + (y - 2)] ||
					input_temp[(x) * (width + 4) + (y - 1)] ||
					input_temp[(x) * (width + 4) + (y)] ||
					input_temp[(x) * (width + 4) + (y + 1)] ||
					input_temp[(x) * (width + 4) + (y + 2)] ||
					input_temp[(x + 1) * (width + 4) + (y - 2)] ||
					input_temp[(x + 1) * (width + 4) + (y - 1)] ||
					input_temp[(x + 1) * (width + 4) + (y)] ||
					input_temp[(x + 1) * (width + 4) + (y + 1)] ||
					input_temp[(x + 1) * (width + 4) + (y + 2)] ||
					input_temp[(x + 2) * (width + 4) + (y - 2)] ||
					input_temp[(x + 2) * (width + 4) + (y - 1)] ||
					input_temp[(x + 2) * (width + 4) + (y)] ||
					input_temp[(x + 2) * (width + 4) + (y + 1)] ||
					input_temp[(x + 2) * (width + 4) + (y + 2)] ? 255 : 0;
			}
		}
	}
	else if (num == 7) {
		for (int x = 3; x < height + 3; ++x) {
			for (int y = 3; y < width + 3; ++y) {
				output_img[(x - 3) * width + (y - 3)] =
					input_temp[(x - 3) * (width + 6) + (y - 3)] ||
					input_temp[(x - 3) * (width + 6) + (y - 2)] ||
					input_temp[(x - 3) * (width + 6) + (y - 1)] ||
					input_temp[(x - 3) * (width + 6) + (y)] ||
					input_temp[(x - 3) * (width + 6) + (y + 1)] ||
					input_temp[(x - 3) * (width + 6) + (y + 2)] ||
					input_temp[(x - 3) * (width + 6) + (y + 3)] ||
					input_temp[(x - 2) * (width + 6) + (y - 3)] ||
					input_temp[(x - 2) * (width + 6) + (y - 2)] ||
					input_temp[(x - 2) * (width + 6) + (y - 1)] ||
					input_temp[(x - 2) * (width + 6) + (y)] ||
					input_temp[(x - 2) * (width + 6) + (y + 1)] ||
					input_temp[(x - 2) * (width + 6) + (y + 2)] ||
					input_temp[(x - 2) * (width + 6) + (y + 3)] ||
					input_temp[(x - 1) * (width + 6) + (y - 3)] ||
					input_temp[(x - 1) * (width + 6) + (y - 2)] ||
					input_temp[(x - 1) * (width + 6) + (y - 1)] ||
					input_temp[(x - 1) * (width + 6) + (y)] ||
					input_temp[(x - 1) * (width + 6) + (y + 1)] ||
					input_temp[(x - 1) * (width + 6) + (y + 2)] ||
					input_temp[(x - 1) * (width + 6) + (y + 3)] ||
					input_temp[(x) * (width + 6) + (y - 3)] ||
					input_temp[(x) * (width + 6) + (y - 2)] ||
					input_temp[(x) * (width + 6) + (y - 1)] ||
					input_temp[(x) * (width + 6) + (y)] ||
					input_temp[(x) * (width + 6) + (y + 1)] ||
					input_temp[(x) * (width + 6) + (y + 2)] ||
					input_temp[(x) * (width + 6) + (y + 3)] ||
					input_temp[(x + 3) * (width + 6) + (y - 3)] ||
					input_temp[(x + 3) * (width + 6) + (y - 2)] ||
					input_temp[(x + 3) * (width + 6) + (y - 1)] ||
					input_temp[(x + 3) * (width + 6) + (y)] ||
					input_temp[(x + 3) * (width + 6) + (y + 1)] ||
					input_temp[(x + 3) * (width + 6) + (y + 2)] ||
					input_temp[(x + 3) * (width + 6) + (y + 3)] ||
					input_temp[(x + 2) * (width + 6) + (y - 3)] ||
					input_temp[(x + 2) * (width + 6) + (y - 2)] ||
					input_temp[(x + 2) * (width + 6) + (y - 1)] ||
					input_temp[(x + 2) * (width + 6) + (y)] ||
					input_temp[(x + 2) * (width + 6) + (y + 1)] ||
					input_temp[(x + 2) * (width + 6) + (y + 2)] ||
					input_temp[(x + 2) * (width + 6) + (y + 3)] ||
					input_temp[(x + 1) * (width + 6) + (y - 3)] ||
					input_temp[(x + 1) * (width + 6) + (y - 2)] ||
					input_temp[(x + 1) * (width + 6) + (y - 1)] ||
					input_temp[(x + 1) * (width + 6) + (y)] ||
					input_temp[(x + 1) * (width + 6) + (y + 1)] ||
					input_temp[(x + 1) * (width + 6) + (y + 2)] ||
					input_temp[(x + 1) * (width + 6) + (y + 3)] ? 255 : 0;
			}
		}
	}
}

/*
for (int x = 1; x < height + 1; ++x) {
		for (int y = 1; y < width + 1; ++y) {
			if ((struct_ele[0] == input_img[(x - 1) * (width + 2) + (y - 1)]) || (struct_ele[1] == input_img[(x - 1) * (width + 2) + (y)]) || (struct_ele[2] == input_img[(x - 1) * (width + 2) + (y + 1)])
				|| (struct_ele[3] == input_img[(x) * (width + 2) + (y - 1)]) || (struct_ele[4] == input_img[(x)* (width + 2) + (y)]) || (struct_ele[5] == input_img[(x)* (width + 2) + (y + 1)])
				|| (struct_ele[6] == input_img[(x + 1) * (width + 2) + (y - 1)]) || (struct_ele[7] == input_img[(x + 1) * (width + 2) + (y)]) || (struct_ele[8] == input_img[(x + 1) * (width + 2) + (y + 1)])) {
				output_img[(x - 1) * width + (y - 1)] = 0;
			}
			else {
				output_img[(x - 1) * width + (y - 1)] = 255;
			}
		}
	}*/

/*for (int x = 2; x < height + 2; ++x) {
			for (int y = 2; y < width + 2; ++y) {
				if ((struct_ele5[0] == input_img[(x - 2) * (width + 4) + (y - 2)]) ||
					(struct_ele5[1] == input_img[(x - 2) * (width + 4) + (y - 1)]) ||
					(struct_ele5[2] == input_img[(x - 2) * (width + 4) + (y)]) ||
					(struct_ele5[3] == input_img[(x - 2) * (width + 4) + (y + 1)]) ||
					(struct_ele5[4] == input_img[(x - 2) * (width + 4) + (y + 2)]) ||
					(struct_ele5[5] == input_img[(x - 1) * (width + 4) + (y - 2)]) ||
					(struct_ele5[6] == input_img[(x - 1) * (width + 4) + (y - 1)]) ||
					(struct_ele5[7] == input_img[(x - 1) * (width + 4) + (y)]) ||
					(struct_ele5[8] == input_img[(x - 1) * (width + 4) + (y + 1)]) ||
					(struct_ele5[9] == input_img[(x - 1) * (width + 4) + (y + 2)]) ||
					(struct_ele5[10] == input_img[(x) * (width + 4) + (y - 2)]) ||
					(struct_ele5[11] == input_img[(x) * (width + 4) + (y - 1)]) ||
					(struct_ele5[12] == input_img[(x) * (width + 4) + (y)]) ||
					(struct_ele5[13] == input_img[(x) * (width + 4) + (y + 1)]) ||
					(struct_ele5[14] == input_img[(x) * (width + 4) + (y + 2)]) ||
					(struct_ele5[15] == input_img[(x + 1) * (width + 4) + (y - 2)]) ||
					(struct_ele5[16] == input_img[(x + 1) * (width + 4) + (y - 1)]) ||
					(struct_ele5[17] == input_img[(x + 1) * (width + 4) + (y)]) ||
					(struct_ele5[18] == input_img[(x + 1) * (width + 4) + (y + 1)]) ||
					(struct_ele5[19] == input_img[(x + 1) * (width + 4) + (y + 2)]) ||
					(struct_ele5[20] == input_img[(x + 2) * (width + 4) + (y - 2)]) ||
					(struct_ele5[21] == input_img[(x + 2) * (width + 4) + (y - 1)]) ||
					(struct_ele5[22] == input_img[(x + 2) * (width + 4) + (y)]) ||
					(struct_ele5[23] == input_img[(x + 2) * (width + 4) + (y + 1)]) ||
					(struct_ele5[24] == input_img[(x + 2) * (width + 4) + (y + 2)])) {
					output_img[(x - 2) * width + (y - 2)] = 0;
				}
				else {
					output_img[(x - 2) * width + (y - 2)] = 255;
				}
			}
		}*/