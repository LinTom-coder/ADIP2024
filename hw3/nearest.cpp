#include "Header.h"
int my_round(float);

void nearest(unsigned char* input_img, unsigned char* output_img, int w, int h, int target_w, int target_h, float r) {
	for (int i = 0; i < target_h; i++) {
		for (int j = 0; j < target_w; j++) {
			int old_x = my_round(i / r);
			int old_y = my_round(j / r);
			//printf("%d, %d, %d, %d\n", old_x, old_y, new_x, new_y);
			output_img[(i * target_w) + j] = input_img[old_x * w + old_y];
		}
	}
}

int my_round(float num) {
	int n = (int)num;
	if ((num - n) > 0.5) {
		return n + 1;
	}
	else{
		return n;
	}
}