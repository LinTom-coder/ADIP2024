#include "Header.h"

void hw4_3_3() {
	/*-----------------------import image-----------------------*/
	char input_image_astronomy[] = "astronomy1280x720.raw";
	FILE* input_file_astronomy;
	int width = 1280;
	int height = 720;
	int size = width * height;
	unsigned char* img_astronomy = new unsigned char[size];
	char input_image_astronomy_noise[] = "astronomy_noise1280x720.raw";
	FILE* input_file_astronomy_noise;
	unsigned char* img_astronomy_noise = new unsigned char[size];

	input_file_astronomy = fopen(input_image_astronomy, "rb");
	if (input_file_astronomy == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_astronomy, 1, size, input_file_astronomy);

	input_file_astronomy_noise = fopen(input_image_astronomy_noise, "rb");
	if (input_file_astronomy_noise == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_astronomy_noise, 1, size, input_file_astronomy_noise);

	/*-----------------------setting output image-----------------------*/
	char output_img_0[] = "hw4_sobel_0.raw";
	FILE* output_file_0;
	unsigned char* img_0 = new unsigned char[size];
	char output_img_0_noise[] = "hw4_sobel_0_noise.raw";
	FILE* output_file_0_noise;
	unsigned char* img_0_noise = new unsigned char[size];

	/*-----------------------apply filter to image-----------------------*/
	sobel_0(img_astronomy, img_0, width, height);
	sobel_0(img_astronomy_noise, img_0_noise, width, height);

	/*-----------------------output image-----------------------*/
	output_file_0 = fopen(output_img_0, "wb");
	fwrite(img_0, 1, size, output_file_0);
	delete[] img_0;
	fclose(output_file_0);
	output_file_0_noise = fopen(output_img_0_noise, "wb");
	fwrite(img_0_noise, 1, size, output_file_0_noise);
	delete[] img_0_noise;
	fclose(output_file_0_noise);

	delete[] img_astronomy;
	fclose(input_file_astronomy);
	delete[] img_astronomy_noise;
	fclose(input_file_astronomy_noise);
}