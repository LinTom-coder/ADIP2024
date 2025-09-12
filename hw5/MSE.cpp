#include "Header.h"

double MSE(unsigned char* input_img, unsigned char* org_img, int w, int h) {
	double mse = 0.0;
	double total = 0.0;
	int size = w * h;
	for (int x = 0; x < h; x++) {
		for (int y = 0; y < w; y++) {
			double a = 0;
			a = org_img[x * w + y] - input_img[x * w + y];
			//printf("%f\n", a);
			total += a * a;
		}
	}
	mse = total / size;
	//printf("show MSE:%f\n", mse);
	return mse;
}