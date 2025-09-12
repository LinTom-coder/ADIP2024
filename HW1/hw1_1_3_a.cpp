#include "Header.h"

void hw1_1_3_a() {
	char  input_img[] = "lena256.raw";                 
	char output_img1_3_a[] = "1_3_a_out.raw";
	FILE* input_file;
	FILE* output_file;
	int width = 256;
	int height = 256;
	int size = width * height;
	unsigned char* img_lena = new unsigned char[size];
	unsigned char* img_1_3 = new unsigned char[size];

	input_file = fopen(input_img, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_lena, 1, size, input_file);

	for (int x = 0; x < 256; x++) {
		for (int y = 0; y < 256; y++) {
			if (img_lena[x * width + y] >= 179) {
				img_1_3[x * width + y] = 255;
			}
			else {
				img_1_3[x * width + y] = img_lena[x * width + y] + 76;
			}
		}
	}

	output_file = fopen(output_img1_3_a, "wb");
	fwrite(img_1_3, 1, size, output_file);
	delete[] img_1_3;
	delete[] img_lena;
	fclose(input_file);
	fclose(output_file);
}