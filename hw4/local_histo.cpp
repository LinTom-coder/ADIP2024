#include "Header.h"

void local_histo(unsigned char* input_img, unsigned char* output_img, int width, int height, int kernel_size) {
	double size = kernel_size * kernel_size;

	int padding_size = (int)kernel_size / 2;
	int padding_width = width + 2 * padding_size;
	int padding_height = height + 2 * padding_size;
	unsigned char* padding_img = new unsigned char[padding_width * padding_height];
	printf("hihi\n");
	padding(input_img, padding_img, width, height, padding_size);
	printf("hihi\n");

	//double size = width * height;
	for (int x = padding_size; x < height + padding_size; x++) {
		for (int y = padding_size; y < width + padding_size; y++) {
			double pdf[256] = { 0 };
			double cdf[256] = { 0 };
			//pdf
			for (int i = 0 - (int)(kernel_size / 2); i <= (int)(kernel_size / 2); i++) {
				for (int j = 0 - (int)(kernel_size / 2); j <= (int)(kernel_size / 2); j++) {
					for (int v = 0; v < 256; v++) {
						if (padding_img[(x + i) * padding_width + (y + j)] == v) {
							pdf[v]++;
						}
					}
				}
			}

			//cdf
			for (int i = 0; i < 256; i++) {
				for (int j = 0; j <= i; j++) {
					cdf[i] += pdf[j];
					cdf[i] /= size;
				}
			}

			//histo
			for (int v = 0; v < 256; v++) {
				if (padding_img[(x) * padding_width + (y)] == v) {
					output_img[(x - padding_size) * width + (y - padding_size)] = (int)(255.0 * cdf[v]);
				}
			}

		}
	}
	delete[] padding_img;
}

/*
#include "Header.h"

void local_histo(unsigned char* input_img, unsigned char* output_img, int width, int height, int kernel_size) {
	double size = kernel_size * kernel_size;
	//double size = width * height;
	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			double pdf[256] = { 0 };
			double cdf[256] = { 0 };
			//pdf
			for (int i = 0 - (int)(kernel_size / 2); i <= (int)(kernel_size / 2); i++) {
				for (int j = 0 - (int)(kernel_size / 2); j <= (int)(kernel_size / 2); j++) {
					if ((x + i) >= 0 && (x + i) < height && (y + j) >= 0 && (y + j) < width) {
						for (int v = 0; v < 256; v++) {
							if (input_img[(x + i) * width + (y + j)] == v) {
								pdf[v]++;
							}
						}
					}
					else {
						pdf[0]++;
					}
				}
			}

			//cdf
			for (int i = 0; i < 256; i++) {
				for (int j = 0; j <= i; j++) {
					cdf[i] += pdf[j];
					cdf[i] /= size;
				}
			}

			//histo
			for (int v = 0; v < 256; v++) {
				if (input_img[(x) * width + (y)] == v) {
					output_img[(x) * width + (y)] = (int)(255.0 * cdf[v]);
				}
			}

		}
	}
}
*/