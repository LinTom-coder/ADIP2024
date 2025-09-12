#include "Header.h"

// padding_size 指要補的圈數
void padding0(unsigned char* input_img, unsigned char* output_img, int width, int height, int padding_size) {
	int padding_width = width + 2 * padding_size;
	int padding_height = height + 2 * padding_size;

	for (int x = 0; x < padding_size; x++) {
		for (int y = 0; y < padding_size; y++) {
			output_img[x * (padding_width)+y] = 0;
		}
	}

	for (int y = 0; y < width; y++) {
		output_img[0 * padding_width + y + padding_size] = 0;
		output_img[1 * padding_width + y + padding_size] = 0;
	}

	for (int x = 0; x < padding_size; x++) {
		for (int y = width + padding_size; y < padding_width; y++) {
			output_img[x * (padding_width)+y] = 0;
		}
	}

	for (int x = 0; x < height; x++) {
		output_img[(x + padding_size) * padding_width + 0] = 0;
		output_img[(x + padding_size) * padding_width + 1] = 0;
	}

	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			output_img[(x + padding_size) * padding_width + (y + padding_size)] = input_img[x * width + y];
		}
	}

	for (int x = 0; x < height; x++) {
		output_img[(x + padding_size) * padding_width + padding_width - 2] = 0;
		output_img[(x + padding_size) * padding_width + padding_width - 1] = 0;
	}

	for (int x = padding_width - padding_size; x < padding_height; x++) {
		for (int y = 0; y < padding_size; y++) {
			output_img[x * padding_width + y] = 0;
		}
	}

	for (int y = 0; y < width; y++) {
		output_img[(padding_height - 2) * padding_width + y + padding_size] = 0;
		output_img[(padding_height - 1) * padding_width + y + padding_size] = 0;
	}

	for (int x = padding_height - padding_size; x < padding_height; x++) {
		for (int y = width + padding_size; y < padding_width; y++) {
			output_img[x * padding_width + y] = 0;
		}
	}
}