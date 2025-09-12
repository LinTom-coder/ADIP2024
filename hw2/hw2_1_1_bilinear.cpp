#include "Header.h"

void  hw2_1_1_bilinear() {
	char input_image[] = "lena512.raw";
	char output_image[] = "hw2_1_1_bilinear.raw";
	FILE* input_file;
	FILE* output_file;
	int width = 512;
	int height = 512;
	int size = width * height;
	unsigned char* img_lena = new unsigned char[size]; // array for image data

	float ratio = 0.6;
	int target_width = (int)(width * ratio);
	int target_height = (int)(height * ratio);
	int target_size = target_width * target_height;
	unsigned char* img_1_1_bilinear = new unsigned char[target_size];

	char input_image_blur[] = "lena512_blur.raw";
	char output_image_blur[] = "hw2_1_1_bilinear_blur.raw";
	FILE* input_file_blur;
	FILE* output_file_blur;
	unsigned char* img_lena_blur = new unsigned char[size]; // array for image data
	unsigned char* img_1_1_bilinear_blur = new unsigned char[target_size];

	input_file = fopen(input_image, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_lena, 1, size, input_file);

	input_file_blur = fopen(input_image_blur, "rb");
	if (input_file_blur == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_lena_blur, 1, size, input_file_blur);

	bilinear(img_lena, img_1_1_bilinear, width, height, target_width, target_height, ratio);
	bilinear(img_lena_blur, img_1_1_bilinear_blur, width, height, target_width, target_height, ratio);

	output_file = fopen(output_image, "wb");
	fwrite(img_1_1_bilinear, 1, target_size, output_file);
	output_file_blur = fopen(output_image_blur, "wb");
	fwrite(img_1_1_bilinear_blur, 1, target_size, output_file_blur);
	delete[] img_1_1_bilinear;
	delete[] img_lena;
	fclose(input_file_blur);
	fclose(output_file_blur);
	delete[] img_1_1_bilinear_blur;
	delete[] img_lena_blur;
	fclose(input_file_blur);
	fclose(output_file_blur);
}