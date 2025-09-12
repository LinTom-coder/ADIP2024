#include "Header.h"

void hw3_3_2() {
	// man
	char input_image_man[] = "man500x500.raw";
	FILE* input_file_man;
	int width = 500;
	int height = 500;
	int size = width * height;
	unsigned char* img_man = new unsigned char[size];
	char output_img_man[] = "hw3_3_2_man.raw";
	FILE* output_file_man;
	unsigned char* output_man = new unsigned char[size];

	input_file_man = fopen(input_image_man, "rb");
	if (input_file_man == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_man, 1, size, input_file_man);
	double pdf[256];
	double cdf[256] = {0};
	for (int v = 0; v < 256; v++) {
		double count = 0.0;
		for (int i = 0; i < size; i++) {
			if (img_man[i] == v) {
				count++;
			}
		}
		pdf[v] = count / size;
		printf("%f/", pdf[v]);
	}
	printf("\n");
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j <= i; j++) {
			cdf[i] += pdf[j];
		}
		printf("%f/", cdf[i]);
	}
	for (int i = 0; i < size; i++) {
		for (int v = 0; v < 256; v++) {
			if (img_man[i] == v) {
				output_man[i] = (int)(255.0 * cdf[v]);
			}
		}
	}

	output_file_man = fopen(output_img_man, "wb");
	fwrite(output_man, 1, size, output_file_man);
	delete[] output_man;
	fclose(output_file_man);
	delete[] img_man;
	fclose(input_file_man);

	// town
	char input_image_town[] = "town500x500.raw";
	FILE* input_file_town;
	unsigned char* img_town = new unsigned char[size];
	char output_img_town[] = "hw3_3_2_town.raw";
	FILE* output_file_town;
	unsigned char* output_town = new unsigned char[size];

	input_file_town = fopen(input_image_town, "rb");
	if (input_file_town == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_town, 1, size, input_file_town);

	double pdf2[256];
	double cdf2[256] = { 0 };
	for (int v = 0; v < 256; v++) {
		double count = 0.0;
		for (int i = 0; i < size; i++) {
			if (img_town[i] == v) {
				count++;
			}
		}
		pdf2[v] = count / size;
		printf("%f/", pdf2[v]);
	}
	printf("\n");
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j <= i; j++) {
			cdf2[i] += pdf2[j];
		}
		printf("%f/", cdf2[i]);
	}
	for (int i = 0; i < size; i++) {
		for (int v = 0; v < 256; v++) {
			if (img_town[i] == v) {
				output_town[i] = (int)(255.0 * cdf2[v]);
			}
		}
	}

	output_file_town = fopen(output_img_town, "wb");
	fwrite(output_town, 1, size, output_file_town);
	delete[] output_town;
	fclose(output_file_town);
	delete[] img_town;
	fclose(input_file_town);
}