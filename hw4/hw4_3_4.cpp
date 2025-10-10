#include "Header.h"

void hw4_3_4() {
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
	char output_img_90[] = "hw4_sobel_90.raw";
	FILE* output_file_90;
	unsigned char* img_90 = new unsigned char[size];
	char output_img_90_noise[] = "hw4_sobel_90_noise.raw";
	FILE* output_file_90_noise;
	unsigned char* img_90_noise = new unsigned char[size];

	/*-----------------------apply filter to image-----------------------*/
	sobel_90(img_astronomy, img_90, width, height);
	sobel_90(img_astronomy_noise, img_90_noise, width, height);

	/*-----------------------combine image-----------------------*/
	char input_image_sobel_0[] = "hw4_sobel_0.raw";
	FILE* input_file_sobel_0;
	unsigned char* img_sobel_0 = new unsigned char[size];
	char input_image_sobel_0_noise[] = "hw4_sobel_0_noise.raw";
	FILE* input_file_sobel_0_noise;
	unsigned char* img_sobel_0_noise = new unsigned char[size];

	input_file_sobel_0 = fopen(input_image_sobel_0, "rb");
	if (input_file_sobel_0 == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_sobel_0, 1, size, input_file_sobel_0);

	input_file_sobel_0_noise = fopen(input_image_sobel_0_noise, "rb");
	if (input_file_sobel_0_noise == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_sobel_0_noise, 1, size, input_file_sobel_0_noise);

	char output_img[] = "hw4_sobel.raw";
	FILE* output_file_sobel;
	unsigned char* img_sobel = new unsigned char[size];
	char output_img_noise[] = "hw4_sobel_noise.raw";
	FILE* output_file_sobel_noise;
	unsigned char* img_sobel_noise = new unsigned char[size];

	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			img_sobel[x * width + y] = sqrt(img_sobel_0[x * width + y] * img_sobel_0[x * width + y] + img_90[x * width + y] * img_90[x * width + y]);
			img_sobel[x * width + y] = (img_sobel[x * width + y] > 255) ? 255 : img_sobel[x * width + y];
		}
	}
	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			img_sobel_noise[x * width + y] = sqrt(img_sobel_0_noise[x * width + y] * img_sobel_0_noise[x * width + y] + img_90_noise[x * width + y] * img_90_noise[x * width + y]);
			img_sobel_noise[x * width + y] = (img_sobel_noise[x * width + y] > 255) ? 255 : img_sobel_noise[x * width + y];
		}
	}

	/*-----------------------output image-----------------------*/
	output_file_90 = fopen(output_img_90, "wb");
	fwrite(img_90, 1, size, output_file_90);
	delete[] img_90;
	fclose(output_file_90);
	output_file_90_noise = fopen(output_img_90_noise, "wb");
	fwrite(img_90_noise, 1, size, output_file_90_noise);
	delete[] img_90_noise;
	fclose(output_file_90_noise);

	output_file_sobel = fopen(output_img, "wb");
	fwrite(img_sobel, 1, size, output_file_sobel);
	delete[] img_sobel;
	fclose(output_file_sobel);

	output_file_sobel_noise = fopen(output_img_noise, "wb");
	fwrite(img_sobel_noise, 1, size, output_file_sobel_noise);
	delete[] img_sobel_noise;
	fclose(output_file_sobel_noise);

	delete[] img_astronomy;
	fclose(input_file_astronomy);
	delete[] img_astronomy_noise;
	fclose(input_file_astronomy_noise);
}