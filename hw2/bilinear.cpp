#include "Header.h"

void  bilinear(unsigned char* input_img, unsigned char* output_img, int w, int h, int target_w, int target_h, float r) {
	for (int i = 0; i < target_h; i++) {
		for (int j = 0; j < target_w; j++) {
			float x = i / r;
			float y = j / r;
			int x1 = (int)x;
			int y1 = (int)y;
			int x2 = x1 + 1 < w ? x1 + 1 : x1;
			int y2 = y1 + 1 < h ? y1 + 1 : y1;

			float dx = x - x1;
			float dy = y - y1;

			unsigned char p11 = input_img[x1 * w + y1];
			unsigned char p12 = input_img[x2 * w + y1];
			unsigned char p21 = input_img[x1 * w + y2];
			unsigned char p22 = input_img[x2 * w + y2];

			output_img[i * target_w + j] = (1 - dx) * (1 - dy) * p11 + dx * (1 - dy) * p12 + (1 - dx) * dy * p21 + dx * dy * p22;
		}
	}
}



// (1-dx)*x1+dx*x2 --> x1-dx*x1+dx*x2 --> x1+(x2-x1)*dx