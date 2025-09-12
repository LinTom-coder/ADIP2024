#include "Header.h"

void hw1_1_2_b() {
	//-----------------------1. Initial variable-----------------------//
	char  input_img[] = "lena256.raw";                 // Input  raw image name
	char output_img[] = "1_2_b_out.raw";              // Output raw image name
	FILE* input_file;
	FILE* output_file;
	int width = 256;
	int height = 256;
	int size = width * height;
	unsigned char* img_lena = new unsigned char[size]; // array for image data

	//-----------------------2. Read File-----------------------//
	// using fopen as example, fstream works too
	input_file = fopen(input_img, "rb");

	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}

	fread(img_lena, 1, size, input_file);
	output_file = fopen(output_img, "wb");
	fwrite(img_lena, 1, size, output_file);
	delete[] img_lena;
	fclose(input_file);
	fclose(output_file);
}