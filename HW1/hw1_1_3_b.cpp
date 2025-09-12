#include "Header.h"

void hw1_1_3_b() {
	char  input_img[] = "lena256.raw";                 // Input  raw image name
	char output_img1_3_b[] = "1_3_b_out.raw";            // Output raw image name
	FILE* input_file;
	FILE* output_file;
	int width = 256;
	int height = 256;
	int size = width * height;
	unsigned char* img_lena = new unsigned char[size]; // array for image data
	unsigned char* img_1_3_b = new unsigned char[size];

	input_file = fopen(input_img, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_lena, 1, size, input_file);

	srand(time(0));
	int random = (rand() % 161) - 81; // %161 將隨機範圍定位在0~161，在減-80位移到-80~80
	printf("1_3_b's random value:%d", random);
	for (int x = 0; x < 256; x++) {
		for (int y = 0; y < 256; y++) {
			//int random = (rand() % 161) - 81; // %161 將隨機範圍定位在0~161，在減-80位移到-80~80
			if (img_lena[x * width + y] + random >= 255) {
				img_1_3_b[x * width + y] = 255;
			}
			else if (img_lena[x * width + y] + random <= 0) {
				img_1_3_b[x * width + y] = 0;
			}
			else {
				img_1_3_b[x * width + y] = img_lena[x * width + y] + random;
			}
		}
	}

	output_file = fopen(output_img1_3_b, "wb");
	fwrite(img_1_3_b, 1, size, output_file);
	delete[] img_lena;
	fclose(input_file);
	fclose(output_file);
}