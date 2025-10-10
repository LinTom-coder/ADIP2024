#include "Header.h"

void hw4_3_2() {
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
	char output_img_8neighbor[] = "hw4_8neighbor.raw";
	FILE* output_file_8neighbor;
	unsigned char* img_neighbor8 = new unsigned char[size];
	char output_img_8neighbor_noise[] = "hw4_8neighbor_noise.raw";
	FILE* output_file_8neighbor_noise;
	unsigned char* img_neighbor8_noise = new unsigned char[size];

	/*-----------------------apply filter to image-----------------------*/
	neighbor8(img_astronomy, img_neighbor8, width, height);
	neighbor8(img_astronomy_noise, img_neighbor8_noise, width, height);

	/*-----------------------output image-----------------------*/
	output_file_8neighbor = fopen(output_img_8neighbor, "wb");
	fwrite(img_neighbor8, 1, size, output_file_8neighbor);
	delete[] img_neighbor8;
	fclose(output_file_8neighbor);
	output_file_8neighbor_noise = fopen(output_img_8neighbor_noise, "wb");
	fwrite(img_neighbor8_noise, 1, size, output_file_8neighbor_noise);
	delete[] img_neighbor8_noise;
	fclose(output_file_8neighbor_noise);

	delete[] img_astronomy;
	fclose(input_file_astronomy);
	delete[] img_astronomy_noise;
	fclose(input_file_astronomy_noise);
}