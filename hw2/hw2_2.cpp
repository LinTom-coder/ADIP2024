#include "Header.h"

void hw2_2() {
	char input_img[] = "duck900x660.raw";
	FILE* input_file;
	int width = 900;
	int height = 660;
	int size = width * height;
	unsigned char* img_duck = new unsigned char[size];

	char output8to4[] = "hw2_2_8to4.raw";
	FILE* output_file_8to4;
	unsigned char* img_8to4 = new unsigned char[size];

	char output_floyd4[] = "hw2_2_floyd4.raw";
	FILE* output_file_floyd4;
	unsigned char* img_floyd4 = new unsigned char[size];

	char output8to1[] = "hw2_2_8to1.raw";
	FILE* output_file_8to1;
	unsigned char* img_8to1 = new unsigned char[size];

	char output_floyd1[] = "hw2_2_floyd1.raw";
	FILE* output_file_floyd1;
	unsigned char* img_floyd1 = new unsigned char[size];

	input_file = fopen(input_img, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_duck, 1, size, input_file);

	//題目 8bits to 4bits
	
	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			img_8to4[x * width + y] = img_duck[x * width + y] / 16 * 17;
		}
	}
	memcpy(img_floyd4, img_duck, size * sizeof(unsigned char));
	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			int old_p = img_floyd4[x * width + y];
			int new_p = img_floyd4[x * width + y] / 16 * 17;
			img_floyd4[x * width + y] = new_p;
			int error = old_p - new_p;
			if (y + 1 < width) {
				img_floyd4[x * width + (y + 1)] = img_floyd4[x * width + (y + 1)] + error * 7 / 16;
			}
			if (y > 0 && x + 1 < height) {
				img_floyd4[(x + 1) * width + (y - 1)] = img_floyd4[(x + 1) * width + (y - 1)] + error * 3 / 16;
			}
			if (x + 1 < height) {
				img_floyd4[(x + 1) * width + y] = img_floyd4[(x + 1) * width + y] + error * 5 / 16;
			}
			if (y + 1 < width && x + 1 < height) {
				img_floyd4[(x + 1) * width + (y + 1)] = img_floyd4[(x + 1) * width + (y + 1)] + error * 1 / 16;
			}
		}
	}

	//題目 8bits to 1bits
	//int quantized_value2[] = { 0, 255 };

	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			img_8to1[x * width + y] = img_duck[x * width + y] / 128 * 255;
		}
	}
	memcpy(img_floyd1, img_duck, size * sizeof(unsigned char));
	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			int old_p = img_floyd1[x * width + y];
			int new_p = img_floyd1[x * width + y] / 128 * 255;
			img_floyd1[x * width + y] = new_p;
			int error = old_p - new_p;
			if (y + 1 < width) {
				img_floyd1[x * width + (y + 1)] = img_floyd1[x * width + (y + 1)] + error * 7 / 16;
			}
			if (y > 0 && x + 1 < height) {
				img_floyd1[(x + 1) * width + (y - 1)] = img_floyd1[(x + 1) * width + (y - 1)] + error * 3 / 16;
			}
			if (x + 1 < height) {
				img_floyd1[(x + 1) * width + y] = img_floyd1[(x + 1) * width + y] + error * 5 / 16;
			}
			if (y + 1 < width && x + 1 < height) {
				img_floyd1[(x + 1) * width + (y + 1)] = img_floyd1[(x + 1) * width + (y + 1)] + error * 1 / 16;
			}
		}
	}

	output_file_8to4 = fopen(output8to4, "wb");
	fwrite(img_8to4, 1, size, output_file_8to4);
	output_file_floyd4 = fopen(output_floyd4, "wb");
	fwrite(img_floyd4, 1, size, output_file_floyd4);

	output_file_8to1 = fopen(output8to1, "wb");
	fwrite(img_8to1, 1, size, output_file_8to1);
	output_file_floyd1 = fopen(output_floyd1, "wb");
	fwrite(img_floyd1, 1, size, output_file_floyd1);

	delete[] img_duck;
	delete[] img_8to4;
	delete[] img_floyd4;
	fclose(input_file);
	fclose(output_file_8to4);
	fclose(output_file_floyd4);
	fclose(output_file_floyd1);
}