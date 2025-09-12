#include "Header.h"

void hw1_1_2_a_1() {
	char  input_img[] = "lena256.raw";                 // Input  raw image name
	//char output_img[] = "1_2_b_out.raw";              // Output raw image name
	FILE* input_file;
	//FILE* output_file;
	int width = 256;
	int height = 256;
	int size = width * height;
	unsigned char* img_lena = new unsigned char[size]; // array for image data

	input_file = fopen(input_img, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_lena, 1, size, input_file);

	//題目
	int row_1 = 78;
	int col_1 = 199;
	if (row_1 >= 0 && row_1 < height && col_1 >= 0 && col_1 < width) {
		unsigned char pixel_value = img_lena[(row_1)*width + (col_1 + 1)]; // 計算像素在陣列中的位置
		printf("\n");
		printf("1.2.a(1):Pixel value at (%d, %d): %d\n", row_1, col_1, pixel_value);
	}
	else {
		printf("\n");
		printf("Coordinates (%d, %d) are out of bounds!\n", row_1, col_1);
	}

	delete[] img_lena;
	fclose(input_file);
	//fclose(output_file);
}