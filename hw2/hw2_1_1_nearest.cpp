#include "Header.h"

void hw2_1_1_nearest() {
	char input_image[] = "lena512.raw";
	char output_image[] = "hw2_1_1_nearest.raw";
	FILE* input_file;
	FILE* output_file;
	int width = 512;
	int height = 512;
	int size = width * height;
	unsigned char* img_lena = new unsigned char[size]; // array for image data

	float ratio = 0.6;
	int target_width = (int)(width*ratio);
	int target_height = (int)(height*ratio);
	int target_size = target_width * target_height;
	unsigned char* img_1_1 = new unsigned char[target_size];

	input_file = fopen(input_image, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_lena, 1, size, input_file);

	char input_image_blur[] = "lena512_blur.raw";
	char output_image_blur[] = "hw2_1_1_nearest_blur.raw";
	FILE* input_file_blur;
	FILE* output_file_blur;
	unsigned char* img_lena_blur = new unsigned char[size]; // array for image data
	unsigned char* img_1_1_blur = new unsigned char[target_size];

	input_file_blur = fopen(input_image_blur, "rb");
	if (input_file_blur == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_lena_blur, 1, size, input_file_blur);

	//ÃD¥Ø nearest
	nearest(img_lena, img_1_1, width, height, target_width, target_height, ratio);
	nearest(img_lena_blur, img_1_1_blur, width, height, target_width, target_height, ratio);
	
	//double x, y;
	//for (x = 0; x < target_height; x++) {
	//	for (y = 0; y < target_width; y++) {
	//		int old_x = (int)(x / ratio);
	//		int old_y = (int)(y / ratio);
	//		int new_x = (int)x;
	//		int new_y = (int)y;
	//		//printf("%d, %d, %d, %d\n", old_x, old_y, new_x, new_y);
	//		img_1_1[(new_x * target_width) + new_y] = img_lena[old_x * width + old_y];
	//	}
	//}

	output_file = fopen(output_image, "wb");
	fwrite(img_1_1, 1, target_size, output_file);
	delete[] img_1_1;
	delete[] img_lena;
	fclose(input_file);
	fclose(output_file);

	output_file_blur = fopen(output_image_blur, "wb");
	fwrite(img_1_1_blur, 1, target_size, output_file_blur);
	delete[] img_1_1_blur;
	delete[] img_lena_blur;
	fclose(input_file_blur);
	fclose(output_file_blur);
}	