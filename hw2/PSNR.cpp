#include "Header.h"

double natural_log(double x) {
    if (x <= 0) {
        printf("Error: ln(x) is undefined for x <= 0.\n");
        return -1;
    }

    double y = (x - 1) / (x + 1);  // 使用修正，將 x 調整為更接近 1
    double y_squared = y * y;
    double result = 0.0;

    // 計算展開的項目
    for (int i = 1; i <= 201; i += 2) {
        result += (1.0 / i) * y;
        y *= y_squared;
    }
    return 2 * result;
}


double PSNR(double mse, unsigned char* input_img, int h, int w) {
	unsigned char max=0;
	for (int x = 0; x < h; x++) {
		for (int y = 0; y < w; y++) {
			max = input_img[x * w + y] > max ? input_img[x * w + y] : max;
		}
	}
    //double psnr = 10 * natural_log(a) / natural_log(10);
    if (mse > 0) {
        double psnr = 10 * log10((255 * 255) / mse);
        return psnr;
    }
    else {
        double psnr = 100;
        return psnr;
    }

}