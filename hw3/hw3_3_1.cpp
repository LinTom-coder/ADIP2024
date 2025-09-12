#include "Header.h"

void hw3_3_1() {
	char input_image_man[] = "man500x500.raw";
	FILE* input_file_man;
	int width = 500;
	int height = 500;
	int size = width * height;
	unsigned char* img_man = new unsigned char[size];
	char output_img_man[] = "hw3_3_1_man.raw";
	FILE* output_file_man;
	unsigned char* output_man = new unsigned char[size];

	input_file_man = fopen(input_image_man, "rb");
	if (input_file_man == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_man, 1, size, input_file_man);

	char input_image_town[] = "town500x500.raw";
	FILE* input_file_town;
	unsigned char* img_town = new unsigned char[size];
	char output_img_town[] = "hw3_3_1_town.raw";
	FILE* output_file_town;
	unsigned char* output_town = new unsigned char[size];

	input_file_town = fopen(input_image_town, "rb");
	if (input_file_town == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_town, 1, size, input_file_town);
	
	// man
	double r1 = 100;
	double r2 = 180;
	double s1 = 50;
	double s2 = 220;
	for (int i = 0; i < size; i++) {
		if (img_man[i] <= r1) {
			output_man[i] = (s1 / r1) * img_man[i];
		}
		else if (r1 < img_man[i] && img_man[i] <= r2 ) {
			output_man[i] = (s2 - s1) / (r2 - r1) * img_man[i] + (s2 - r2 * (s2 - s1) / (r2 - r1));
		}
		else {
			output_man[i] = (255 - s2) / (255 - r1) * img_man[i] + (255 - 255 * (255 - s2) / (255 - r1));
		}
	}
	output_file_man = fopen(output_img_man, "wb");
	fwrite(output_man, 1, size, output_file_man);
	delete[] output_man;
	fclose(output_file_man);
	delete[] img_man;
	fclose(input_file_man);

	// town
	for (int i = 0; i < size; i++) {
		if (img_town[i] <= r1) {
			output_town[i] = (s1 / r1) * img_town[i];
		}
		else if (r1 < img_town[i] && img_town[i] <= r2) {
			output_town[i] = (s2 - s1) / (r2 - r1) * img_town[i] + (s2 - r2 * (s2 - s1) / (r2 - r1));
		}
		else {
			output_town[i] = (255 - s2) / (255 - r1) * img_town[i] + (255 - 255 * (255 - s2) / (255 - r1));
		}
	}

	output_file_town = fopen(output_img_town, "wb");
	fwrite(output_town, 1, size, output_file_town);
	delete[] output_town;
	fclose(output_file_town);
	delete[] img_town;
	fclose(input_file_town);

}