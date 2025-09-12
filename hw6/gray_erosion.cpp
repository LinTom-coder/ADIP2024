#include "Header.h"

void gray_erosion(unsigned char* input_img, unsigned char* output_img, int width, int height, int num) {
	int half_num = num / 2;
	unsigned char* input_temp = new unsigned char[(width + 2 * half_num) * (height + 2 * half_num)];
	padding(input_img, input_temp, width, height, half_num);
	//創建結構元素
	int* struct_ele = (int*)malloc(num * num * sizeof(int*));
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			struct_ele[i * num + j] = 1;
		}
	}
	int* v = (int*)malloc(num * num * sizeof(int*));
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			struct_ele[i * num + j] = 0;
		}
	}
	//侵蝕運算
	for (int x = half_num; x < height + half_num; ++x) {
		for (int y = half_num; y < width + half_num; ++y) {
			for (int i = 0- half_num; i <= half_num; ++i) {
				for (int j = 0- half_num; j <= half_num; ++j) {
					v[(i + half_num) * num + (j + half_num)] = struct_ele[(i + half_num) * num + (j + half_num)] + input_temp[(x + i) * (width + 2 * half_num) + (y + j)];
				}
			}
			double min = 256;
			for (int i = 0; i < num * num; ++i) {
				if (v[i] <= min) {
					min = v[i];
				}
			}
			output_img[(x - half_num) * width + (y - half_num)] = min <= 0 ? 0 : min;
		}
	}
}