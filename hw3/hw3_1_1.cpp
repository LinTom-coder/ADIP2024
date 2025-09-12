#include "Header.h"

void hw3_1_1() {
	//char input_image[] = "Firework220x293.raw";
	char input_image[] = "astronomy1280x720.raw";
	FILE* input_file;
	int width = 1280;
	int height = 720;
	int size = width * height;
	unsigned char* img_firework = new unsigned char[size];

	char output1[] = "hw3_1_1_log.raw";
	FILE* output1_file;
	unsigned char* img_log = new unsigned char[size];
	char output2[] = "hw3_1_1_inverse.raw";
	FILE* output2_file;
	unsigned char* img_inverse = new unsigned char[size];

	input_file = fopen(input_image, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_firework, 1, size, input_file);

	double c_log = 255 / log10(255);
	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			img_log[x * width + y] = c_log * log10(1 + img_firework[x * width + y]);
			
		}
	}
	double c = 255.0 / 9.0;
	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			img_inverse[x * width + y] = c * (pow(10.0, img_firework[x * width + y] / 255.0) - 1);
		}
	}

	output1_file = fopen(output1, "wb");
	fwrite(img_log, 1, size, output1_file);
	delete[] img_log;
	fclose(output1_file);

	output2_file = fopen(output2, "wb");
	fwrite(img_inverse, 1, size, output2_file);
	delete[] img_inverse;
	fclose(output2_file);

	delete[] img_firework;
	fclose(input_file);
}