#include "Header.h"

void hw2_1_2() {
	char input_image[] = "lena512.raw";
	char output_image[] = "hw2_1_2.raw";
	FILE* input_file;
	FILE* output_file;
	int width = 512;
	int height = 512;
	int size = width * height;
	unsigned char* img_lena = new unsigned char[size]; // array for image data

	int ratio = 2;
	int target_width = width * ratio;
	int target_height = height * ratio;
	int target_size = target_width * target_height;
	unsigned char* img_1_2 = new unsigned char[target_size];
	//unsigned char* img_lena = new unsigned char[target_size];

	char org_image[] = "lena1024.raw";
	FILE* org_file;
	unsigned char* img_org = new unsigned char[target_size];
	org_file = fopen(org_image, "rb");
	if (org_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_org, 1, target_size, org_file);

	input_file = fopen(input_image, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_lena, 1, size, input_file);

	//ÃD¥Ø nearest
	//nearest(img_lena, img_1_2, width, height, target_width, target_height, ratio);
	//bilinear(img_lena, img_1_2, width, height, target_width, target_height, ratio);

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			unsigned char value = img_lena[x * width + y];
			for (int dx = 0; dx < ratio; dx++) {
				for (int dy = 0; dy < ratio; dy++) {
					int new_x = x * ratio + dx;
					int new_y = y * ratio + dy;
					img_1_2[new_x * target_width + new_y] = value;
				}
			}
		}
	}
	printf("%d\n", img_1_2[1023 * target_width + 1023]);
	printf("%d\n", img_org[1023 * target_width + 1023]);

	double mse = MSE(img_1_2, img_org, target_width, target_height);
	printf("SHOW MSE:%f\n", mse);
	double psnr = PSNR(mse, img_1_2, target_height, target_width);
	printf("SHOW PSNR:%f\n", psnr);

	output_file = fopen(output_image, "wb");
	fwrite(img_1_2, 1, target_size, output_file);
	delete[] img_1_2;
	delete[] img_lena;
	delete[] img_org;
	fclose(input_file);
	fclose(output_file);
	fclose(org_file);
}