#include "Header.h"

void binary_thinning(unsigned char* input_img, unsigned char* output_img, int width, int height) {
	unsigned char* input_padding = new unsigned char[(width + 2) * (height + 2)];
	unsigned char* output_temp = new unsigned char[width * height];
	unsigned char* input_temp = new unsigned char[width * height];

	memcpy(input_temp, input_img, width * height);
	memcpy(output_temp, input_img, width * height);
	int mse = 0;
	do {
		//B1
		padding(output_temp, input_padding, width, height, 1);
		for (int x = 1; x < height + 1; ++x) {
			for (int y = 1; y < width + 1; ++y) {
				//hit
				int hit = input_padding[(x) * (width + 2) + (y)] && input_padding[(x + 1) * (width + 2) + (y - 1)] && input_padding[(x + 1) * (width + 2) + (y)] && input_padding[(x + 1) * (width + 2) + (y + 1)] ? 1 : 0;
				//miss
				int miss = input_padding[(x - 1) * (width + 2) + (y - 1)] == 0 && input_padding[(x - 1) * (width + 2) + (y)] == 0 && input_padding[(x - 1) * (width + 2) + (y + 1)] == 0 ? 1 : 0;
				if (hit && miss) {
					output_temp[(x - 1) * width + (y - 1)] = 255;
				}
				else {
					output_temp[(x - 1) * width + (y - 1)] = 0;
				}
				output_temp[(x - 1) * width + (y - 1)] = abs(input_padding[(x) * (width + 2) + (y)] - output_temp[(x - 1) * width + (y - 1)]);
			}
		}

		//B2
		padding(output_temp, input_padding, width, height, 1);
		for (int x = 1; x < height + 1; ++x) {
			for (int y = 1; y < width + 1; ++y) {
				//hit
				int hit = input_padding[(x) * (width + 2) + (y - 1)] && input_padding[(x) * (width + 2) + (y)] && input_padding[(x + 1) * (width + 2) + (y - 1)] && input_padding[(x + 1) * (width + 2) + (y)] ? 1 : 0;
				//miss
				int miss = input_padding[(x - 1) * (width + 2) + (y)] == 0 && input_padding[(x - 1) * (width + 2) + (y + 1)] == 0 && input_padding[(x) * (width + 2) + (y + 1)] == 0 ? 1 : 0;
				if (hit && miss) {
					output_temp[(x - 1) * width + (y - 1)] = 255;
				}
				else {
					output_temp[(x - 1) * width + (y - 1)] = 0;
				}
				output_temp[(x - 1) * width + (y - 1)] = abs(input_padding[(x) * (width + 2) + (y)] - output_temp[(x - 1) * width + (y - 1)]);

			}
		}

		//B3
		padding(output_temp, input_padding, width, height, 1);
		for (int x = 1; x < height + 1; ++x) {
			for (int y = 1; y < width + 1; ++y) {
				//hit
				int hit = input_padding[(x - 1) * (width + 2) + (y - 1)] && input_padding[(x) * (width + 2) + (y - 1)] && input_padding[(x) * (width + 2) + (y)] && input_padding[(x + 1) * (width + 2) + (y - 1)] ? 1 : 0;
				//miss
				int miss = input_padding[(x - 1) * (width + 2) + (y + 1)] == 0 && input_padding[(x) * (width + 2) + (y + 1)] == 0 && input_padding[(x + 1) * (width + 2) + (y + 1)] == 0 ? 1 : 0;
				if (hit && miss) {
					output_temp[(x - 1) * width + (y - 1)] = 255;
				}
				else {
					output_temp[(x - 1) * width + (y - 1)] = 0;
				}
				output_temp[(x - 1) * width + (y - 1)] = abs(input_padding[(x) * (width + 2) + (y)] - output_temp[(x - 1) * width + (y - 1)]);

			}
		}

		//B4
		padding(output_temp, input_padding, width, height, 1);
		for (int x = 1; x < height + 1; ++x) {
			for (int y = 1; y < width + 1; ++y) {
				//hit
				int hit = input_padding[(x - 1) * (width + 2) + (y - 1)] && input_padding[(x - 1) * (width + 2) + (y)] && input_padding[(x) * (width + 2) + (y - 1)] && input_padding[(x) * (width + 2) + (y)] ? 1 : 0;
				//miss
				int miss = input_padding[(x) * (width + 2) + (y + 1)] == 0 && input_padding[(x + 1) * (width + 2) + (y)] == 0 && input_padding[(x + 1) * (width + 2) + (y + 1)] == 0 ? 1 : 0;
				if (hit && miss) {
					output_temp[(x - 1) * width + (y - 1)] = 255;
				}
				else {
					output_temp[(x - 1) * width + (y - 1)] = 0;
				}
				output_temp[(x - 1) * width + (y - 1)] = abs(input_padding[(x) * (width + 2) + (y)] - output_temp[(x - 1) * width + (y - 1)]);
			}
		}

		//B5
		padding(output_temp, input_padding, width, height, 1);
		for (int x = 1; x < height + 1; ++x) {
			for (int y = 1; y < width + 1; ++y) {
				//hit
				int hit = input_padding[(x - 1) * (width + 2) + (y - 1)] && input_padding[(x - 1) * (width + 2) + (y)] && input_padding[(x - 1) * (width + 2) + (y + 1)] && input_padding[(x) * (width + 2) + (y)] ? 1 : 0;
				//miss
				int miss = input_padding[(x + 1) * (width + 2) + (y - 1)] == 0 && input_padding[(x + 1) * (width + 2) + (y)] == 0 && input_padding[(x + 1) * (width + 2) + (y + 1)] == 0 ? 1 : 0;
				if (hit && miss) {
					output_temp[(x - 1) * width + (y - 1)] = 255;
				}
				else {
					output_temp[(x - 1) * width + (y - 1)] = 0;
				}
				output_temp[(x - 1) * width + (y - 1)] = abs(input_padding[(x) * (width + 2) + (y)] - output_temp[(x - 1) * width + (y - 1)]);

			}
		}

		//B6
		padding(output_temp, input_padding, width, height, 1);
		for (int x = 1; x < height + 1; ++x) {
			for (int y = 1; y < width + 1; ++y) {
				//hit
				int hit = input_padding[(x - 1) * (width + 2) + (y)] && input_padding[(x - 1) * (width + 2) + (y + 1)] && input_padding[(x) * (width + 2) + (y)] && input_padding[(x) * (width + 2) + (y + 1)] ? 1 : 0;
				//miss
				int miss = input_padding[(x) * (width + 2) + (y - 1)] == 0 && input_padding[(x + 1) * (width + 2) + (y - 1)] == 0 && input_padding[(x + 1) * (width + 2) + (y)] == 0 ? 1 : 0;
				if (hit && miss) {
					output_temp[(x - 1) * width + (y - 1)] = 255;
				}
				else {
					output_temp[(x - 1) * width + (y - 1)] = 0;
				}
				output_temp[(x - 1) * width + (y - 1)] = abs(input_padding[(x) * (width + 2) + (y)] - output_temp[(x - 1) * width + (y - 1)]);

			}
		}

		//B7
		padding(output_temp, input_padding, width, height, 1);
		for (int x = 1; x < height + 1; ++x) {
			for (int y = 1; y < width + 1; ++y) {
				//hit
				int hit = input_padding[(x - 1) * (width + 2) + (y + 1)] && input_padding[(x) * (width + 2) + (y)] && input_padding[(x) * (width + 2) + (y + 1)] && input_padding[(x + 1) * (width + 2) + (y + 1)] ? 1 : 0;
				//miss
				int miss = input_padding[(x - 1) * (width + 2) + (y - 1)] == 0 && input_padding[(x) * (width + 2) + (y - 1)] == 0 && input_padding[(x + 1) * (width + 2) + (y - 1)] == 0 ? 1 : 0;
				if (hit && miss) {
					output_temp[(x - 1) * width + (y - 1)] = 255;
				}
				else {
					output_temp[(x - 1) * width + (y - 1)] = 0;
				}
				output_temp[(x - 1) * width + (y - 1)] = abs(input_padding[(x) * (width + 2) + (y)] - output_temp[(x - 1) * width + (y - 1)]);

			}

		}

		//B8
		padding(output_temp, input_padding, width, height, 1);
		for (int x = 1; x < height + 1; ++x) {
			for (int y = 1; y < width + 1; ++y) {
				//hit
				int hit = input_padding[(x) * (width + 2) + (y)] && input_padding[(x) * (width + 2) + (y + 1)] && input_padding[(x + 1) * (width + 2) + (y)] && input_padding[(x + 1) * (width + 2) + (y + 1)] ? 1 : 0;
				//miss
				int miss = input_padding[(x - 1) * (width + 2) + (y - 1)] == 0 && input_padding[(x - 1) * (width + 2) + (y)] == 0 && input_padding[(x) * (width + 2) + (y - 1)] == 0 ? 1 : 0;
				if (hit && miss) {
					output_temp[(x - 1) * width + (y - 1)] = 255;
				}
				else {
					output_temp[(x - 1) * width + (y - 1)] = 0;
				}
				output_temp[(x - 1) * width + (y - 1)] = abs(input_padding[(x) * (width + 2) + (y)] - output_temp[(x - 1) * width + (y - 1)]);

			}
		}
		mse = MSE(output_temp, input_temp, width, height);
		memcpy(output_img, output_temp, width * height);
		memcpy(input_temp, output_temp, width * height);
	} while (mse != 0);

	delete[] input_padding;
	delete[] input_temp;
	delete[] output_temp;
}