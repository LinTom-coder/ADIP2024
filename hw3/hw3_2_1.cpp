#include "Header.h"

void hw3_2_1() {
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

	char input_image2[] = "2_b.raw";
	FILE* input_file2;
	int width1 = 512;
	int height1 = 512;
	int size1 = width1 * height1;
	unsigned char* img_2_b = new unsigned char[size1];
	unsigned char* img = new unsigned char[size];
	unsigned char* img_temp = new unsigned char[size];

	input_file2 = fopen(input_image2, "rb");
	if (input_file2 == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_2_b, 1, size1, input_file2);
	nearest(img_2_b, img, width1, height1, width, height, 0.5);


	//bit = 0
	char output_bit0[] = "lena_emblem_bit0.raw";
	FILE* output_file_bit0;
	unsigned char* lena_bit0 = new unsigned char[size];
	char output_extract_bit0[] = "extract_bit0.raw";
	FILE* output_file_extract_bit0;
	unsigned char* extract_bit0 = new unsigned char[size];

	for (int i = 0; i < size; i++) {
		lena_bit0[i] = img_lena[i] & 254;
		img_temp[i] = img[i] > 0 ? 1 : 0;
		lena_bit0[i] = lena_bit0[i] | img_temp[i];
	}
	for (int j = 0; j < size; j++) {
		extract_bit0[j] = lena_bit0[j] & 1;
		extract_bit0[j] = extract_bit0[j] > 0 ? 255 : 0;
	}

	output_file_bit0 = fopen(output_bit0, "wb");
	fwrite(lena_bit0, 1, size, output_file_bit0);
	delete[] lena_bit0;
	fclose(output_file_bit0);
	output_file_extract_bit0 = fopen(output_extract_bit0, "wb");
	fwrite(extract_bit0, 1, size, output_file_extract_bit0);
	delete[] extract_bit0;
	fclose(output_file_extract_bit0);


	//bit = 4
	char output_bit4[] = "lena_emblem_bit4.raw";
	FILE* output_file_bit4;
	unsigned char* lena_bit4 = new unsigned char[size];
	char output_extract_bit4[] = "extract_bit4.raw";
	FILE* output_file_extract_bit4;
	unsigned char* extract_bit4 = new unsigned char[size];

	for (int i = 0; i < size; i++) {
		lena_bit4[i] = img_lena[i] & 239;
		img_temp[i] = img[i] > 0 ? 1 : 0;
		img_temp[i] = img_temp[i] << 4;
		lena_bit4[i] = lena_bit4[i] | img_temp[i];
	}
	for (int j = 0; j < size; j++) {
		extract_bit4[j] = lena_bit4[j] & 16;
		extract_bit4[j] = extract_bit4[j] > 0 ? 255 : 0;
	}

	output_file_bit4 = fopen(output_bit4, "wb");
	fwrite(lena_bit4, 1, size, output_file_bit4);
	delete[] lena_bit4;
	fclose(output_file_bit4);
	output_file_extract_bit4 = fopen(output_extract_bit4, "wb");
	fwrite(extract_bit4, 1, size, output_file_extract_bit4);
	delete[] extract_bit4;
	fclose(output_file_extract_bit4);


	//bit = 7
	char output_bit7[] = "lena_emblem_bit7.raw";
	FILE* output_file_bit7;
	unsigned char* lena_bit7 = new unsigned char[size];
	char output_extract_bit7[] = "extract_bit7.raw";
	FILE* output_file_extract_bit7;
	unsigned char* extract_bit7 = new unsigned char[size];

	for (int i = 0; i < size; i++) {
		lena_bit7[i] = img_lena[i] & 127;
		img_temp[i] = img[i] > 0 ? 1 : 0;
		img_temp[i] = img_temp[i] << 7;
		lena_bit7[i] = lena_bit7[i] | img_temp[i];
	}
	for (int j = 0; j < size; j++) {
		extract_bit7[j] = lena_bit7[j] & 128;
		extract_bit7[j] = extract_bit7[j] > 0 ? 255 : 0;
	}

	output_file_bit7 = fopen(output_bit7, "wb");
	fwrite(lena_bit7, 1, size, output_file_bit7);
	delete[] lena_bit7;
	fclose(output_file_bit7);
	output_file_extract_bit7 = fopen(output_extract_bit7, "wb");
	fwrite(extract_bit7, 1, size, output_file_extract_bit7);
	delete[] extract_bit7;
	fclose(output_file_extract_bit7);


	delete[] img_lena;
	fclose(input_file);
	delete[] img;
	fclose(input_file2);
	delete[] img_temp;
	delete[] img_2_b;
}