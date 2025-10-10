#include "Header.h"

void hw4_2_1() {
	//import image
	char input_image_gaussian[] = "noisy_gaussian.raw";
	FILE* input_file_gaussian;
	int width = 500;
	int height = 500;
	int size = width * height;
	unsigned char* img_gaussian = new unsigned char[size];
	char input_image_salt_pepper[] = "noisy_salt_pepper.raw";
	FILE* input_file_salt_pepper;
	unsigned char* img_salt = new unsigned char[size];

	input_file_gaussian = fopen(input_image_gaussian, "rb");
	if (input_file_gaussian == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_gaussian, 1, size, input_file_gaussian);

	input_file_salt_pepper = fopen(input_image_salt_pepper, "rb");
	if (input_file_salt_pepper == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_salt, 1, size, input_file_salt_pepper);

	//set output image
	char output_img_gaussian3x3[] = "noisy_gaussian_3x3.raw";
	FILE* output_file_gaussian3x3;
	unsigned char* gaussian3 = new unsigned char[size];
	char output_img_gaussian5x5[] = "noisy_gaussian_5x5.raw";
	FILE* output_file_gaussian5x5;
	unsigned char* gaussian5 = new unsigned char[size];

	char output_img_salt_pepper3x3[] = "noisy_salt_pepper_3x3.raw";
	FILE* output_file_salt_pepper3x3;
	unsigned char* salt3 = new unsigned char[size];
	char output_img_salt_pepper5x5[] = "noisy_salt_pepper_5x5.raw";
	FILE* output_file_salt_pepper5x5;
	unsigned char* salt5 = new unsigned char[size];

	//3x3
	mean3x3(img_gaussian, gaussian3, width, height);
	mean3x3(img_salt, salt3, width, height);

	output_file_gaussian3x3 = fopen(output_img_gaussian3x3, "wb");
	fwrite(gaussian3, 1, size, output_file_gaussian3x3);
	delete[] gaussian3;
	fclose(output_file_gaussian3x3);
	output_file_salt_pepper3x3 = fopen(output_img_salt_pepper3x3, "wb");
	fwrite(salt3, 1, size, output_file_salt_pepper3x3);
	delete[] salt3;
	fclose(output_file_salt_pepper3x3);

	//5x5
	mean5x5(img_gaussian, gaussian5, width, height);
	mean5x5(img_salt, salt5, width, height);

	output_file_gaussian5x5 = fopen(output_img_gaussian5x5, "wb");
	fwrite(gaussian5, 1, size, output_file_gaussian5x5);
	delete[] gaussian5;
	fclose(output_file_gaussian5x5);
	output_file_salt_pepper5x5 = fopen(output_img_salt_pepper5x5, "wb");
	fwrite(salt5, 1, size, output_file_salt_pepper5x5);
	delete[] salt5;
	fclose(output_file_salt_pepper5x5);

	delete[] img_gaussian;
	fclose(input_file_gaussian);
	delete[] img_salt;
	fclose(input_file_salt_pepper);
}