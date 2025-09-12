#include "Header.h"

void hw1_1_2_a_2() {
	char  input_img[] = "lena256.raw";                 // Input  raw image name
	FILE* input_file;
	int width = 256;
	int height = 256;
	int size = width * height;
	unsigned char* img_lena = new unsigned char[size];

	input_file = fopen(input_img, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_lena, 1, size, input_file);

	int position = 16888;
	int row_2, col_2;
	if (position >= 0 && position <= size) {
		unsigned char value = img_lena[position - 1];
		col_2 = position % width;
		row_2 = (position - col_2) / width;
		printf("\n");
		printf("1.2.a(2):Pixel value at (%d-th): %d\n", position, value);
		printf("1.2.a(2):Pixel coordinate: (%d, %d)\n", row_2, col_2 - 1);
	}
	else {
		printf("\n");
		printf("error!!");
	}
	delete[] img_lena;
	fclose(input_file);
}