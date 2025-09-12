#include "Header.h"

void hw1_1_2_c() {
	char  input_img[] = "lena256.raw";    
	char output_img1_2_c[] = "1_2_c_out.raw";
	FILE* input_file;
	FILE* output_file;
	int width = 256;
	int height = 256;
	int size = width * height;
	unsigned char* img_lena = new unsigned char[size]; // array for image data
	unsigned char* ad_img = new unsigned char[size];

	input_file = fopen(input_img, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_lena, 1, size, input_file);

	for (int x = 0; x < 64; x++) {
		for (int y = 0; y < 64; y++) {
			ad_img[(x + 192) * 256 + (y + 192)] = img_lena[x * 256 + y];
		}
	}
	for (int x = 0; x < 64; x++) {
		for (int y = 64; y < 128; y++) {
			ad_img[(x + 192) * 256 + (y + 64)] = img_lena[x * 256 + y];
		}
	}
	for (int x = 0; x < 64; x++) {
		for (int y = 128; y < 192; y++) {
			ad_img[((191 - y) + 192) * 256 + (x + 64)] = img_lena[x * 256 + y];
		}
	}
	for (int x = 0; x < 64; x++) {
		for (int y = 192; y < 256; y++) {
			ad_img[(x + 192) * 256 + (y - 192)] = img_lena[x * 256 + y];
		}
	}
	for (int x = 64; x < 128; x++) {
		for (int y = 0; y < 64; y++) {
			ad_img[(191 - y) * 256 + (x + 128)] = img_lena[x * 256 + y];
		}
	}
	for (int x = 64; x < 128; x++) {
		for (int y = 64; y < 128; y++) {
			ad_img[(x + 64) * 256 + (y + 64)] = img_lena[x * 256 + y];
		}
	}
	for (int x = 64; x < 128; x++) {
		for (int y = 128; y < 192; y++) {
			ad_img[(y) * 256 + (191 - x)] = img_lena[x * 256 + y];
		}
	}
	for (int x = 64; x < 128; x++) {
		for (int y = 192; y < 256; y++) {
			ad_img[(384 - y) * 256 + (x - 320)] = img_lena[x * 256 + y];
		}
	}
	for (int x = 128; x < 192; x++) {
		for (int y = 0; y < 64; y++) {
			ad_img[(255 - y - 64 - 64) * 256 + (x + 192 - 128)] = img_lena[x * 256 + y];
		}
	}
	for (int x = 128; x < 192; x++) {
		for (int y = 64; y < 128; y++) {
			ad_img[(x - 64) * 256 + (y + 64)] = img_lena[x * 256 + y];
		}
	}
	for (int x = 128; x < 192; x++) {
		for (int y = 128; y < 192; y++) {
			ad_img[(255 - y - 64 + 64) * 256 + (x - 64)] = img_lena[x * 256 + y];
		}
	}
	for (int x = 128; x < 192; x++) {
		for (int y = 192; y < 256; y++) {
			ad_img[(y - 64 - 64) * 256 + (255 - x + 128 - 192)] = img_lena[x * 256 + y];
		}
	}
	for (int x = 192; x < 256; x++) {
		for (int y = 0; y < 64; y++) {
			ad_img[(y - 192 + 192) * 256 + (255 - x + 192)] = img_lena[x * 256 + y];
		}
	}
	for (int x = 192; x < 256; x++) {
		for (int y = 64; y < 128; y++) {
			ad_img[(x - 192) * 256 + (y + 64)] = img_lena[x * 256 + y];
		}
	}
	for (int x = 192; x < 256; x++) {
		for (int y = 128; y < 192; y++) {
			ad_img[(255 - y + 128 - 192) * 256 + (x - 64 - 64)] = img_lena[x * 256 + y];
		}
	}
	for (int x = 192; x < 256; x++) {
		for (int y = 192; y < 256; y++) {
			ad_img[(y - 192) * 256 + (255 - x + 192 - 192)] = img_lena[x * 256 + y];
		}
	}

	output_file = fopen(output_img1_2_c, "wb");
	fwrite(ad_img, 1, size, output_file);
	delete[] ad_img;
	delete[] img_lena;
	fclose(input_file);
	fclose(output_file);
}