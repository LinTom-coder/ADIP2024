#include "Header.h"

void hw3_2_2() {
	char input_image[] = "lena256.raw";
	FILE* input_file;
	int width = 256;
	int height = 256;
	int size = width * height;
	unsigned char* img_lena = new unsigned char[size];

	input_file = fopen(input_image, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_lena, 1, size, input_file);

	//save 6 and 7
	char output_6and7[] = "compressed_lena_6and7.raw";
	FILE* output_file_6and7;
	unsigned char* lena_6and7 = new unsigned char[size];

	for (int i = 0; i < size; i++) {
		lena_6and7[i] = img_lena[i] & 192;
	}
	output_file_6and7 = fopen(output_6and7, "wb");
	fwrite(lena_6and7, 1, size, output_file_6and7);
	delete[] lena_6and7;
	fclose(output_file_6and7);

	//save 3 to 7
	char output_3to7[] = "compressed_lena_3to7.raw";
	FILE* output_file_3to7;
	unsigned char* lena_3to7 = new unsigned char[size];

	for (int i = 0; i < size; i++) {
		lena_3to7[i] = img_lena[i] & 248;
	}
	output_file_3to7 = fopen(output_3to7, "wb");
	fwrite(lena_3to7, 1, size, output_file_3to7);
	delete[] lena_3to7;
	fclose(output_file_3to7);

	delete[] img_lena;
	fclose(input_file);
}