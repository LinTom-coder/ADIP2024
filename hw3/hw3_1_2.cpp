#include "Header.h"

void hw3_1_2() {
	char input_image[] = "Firework220x293.raw";
	FILE* input_file;
	int width = 220;
	int height = 293;
	int size = width * height;
	unsigned char* img_firework = new unsigned char[size];

	char output_less1[] = "hw3_1_2_less1.raw";
	FILE* output1_file;
	unsigned char* img_less1 = new unsigned char[size];
	char output_less2[] = "hw3_1_2_less2.raw";
	FILE* output2_file;
	unsigned char* img_less2 = new unsigned char[size];

	char output_greater1[] = "hw3_1_2_greater1.raw";
	FILE* output3_file;
	unsigned char* img_greater1 = new unsigned char[size];
	char output_greater2[] = "hw3_1_2_greater2.raw";
	FILE* output4_file;
	unsigned char* img_greater2 = new unsigned char[size];

	input_file = fopen(input_image, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_firework, 1, size, input_file);

	double gamma1 = 0.7;
	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			img_less1[x * width + y] = pow(img_firework[x * width + y], gamma1) * pow(255, 1-gamma1);

		}
	}

	double gamma2 = 0.4;
	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			img_less2[x * width + y] = pow(img_firework[x * width + y], gamma2) * pow(255, 1-gamma2);

		}
	}

	double gamma3 = 2.5;
	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			img_greater1[x * width + y] = pow(img_firework[x * width + y], gamma3) * pow(255, 1 - gamma3);

		}
	}

	double gamma4 = 10.0;
	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			img_greater2[x * width + y] = pow(img_firework[x * width + y], gamma4) * pow(255, 1 - gamma4);

		}
	}

	output1_file = fopen(output_less1, "wb");
	fwrite(img_less1, 1, size, output1_file);
	delete[] img_less1;
	fclose(output1_file);
	output2_file = fopen(output_less2, "wb");
	fwrite(img_less2, 1, size, output2_file);
	delete[] img_less2;
	fclose(output2_file);
	output3_file = fopen(output_greater1, "wb");
	fwrite(img_greater1, 1, size, output3_file);
	delete[] img_greater1;
	fclose(output3_file);
	output4_file = fopen(output_greater2, "wb");
	fwrite(img_greater2, 1, size, output4_file);
	delete[] img_greater2;
	fclose(output4_file);

	delete[] img_firework;
	fclose(input_file);
}