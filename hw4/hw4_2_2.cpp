#include "Header.h"

void hw4_2_2() {
	char input_image_gaussian[] = "noisy_gaussian.raw";
	FILE* input_file_gaussian;
	int width = 500;
	int height = 500;
	int size = width * height;
	unsigned char* img_gaussian = new unsigned char[size];
	char input_image_salt_pepper[] = "noisy_salt_pepper.raw";
	FILE* input_file_salt_pepper;
	unsigned char* img_salt = new unsigned char[size];

	input_file_gaussian = fopen(input_image_gaussian, "rb");
	if (input_file_gaussian == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_gaussian, 1, size, input_file_gaussian);

	input_file_salt_pepper = fopen(input_image_salt_pepper, "rb");
	if (input_file_salt_pepper == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_salt, 1, size, input_file_salt_pepper);

	char output_img_gaussian08[] = "noisy_gaussian_filtered_0.8.raw";
	FILE* output_file_gaussian08;
	unsigned char* gaussian08 = new unsigned char[size];
	char output_img_gaussian13[] = "noisy_gaussian_filtered_1.3.raw";
	FILE* output_file_gaussian13;
	unsigned char* gaussian13 = new unsigned char[size];
	char output_img_gaussian20[] = "noisy_gaussian_filtered_2.0.raw";
	FILE* output_file_gaussian20;
	unsigned char* gaussian20 = new unsigned char[size];

	char output_img_salt_pepper08[] = "noisy_salt_pepper_filtered_0.8.raw";
	FILE* output_file_salt_pepper08;
	unsigned char* salt08 = new unsigned char[size];
	char output_img_salt_pepper13[] = "noisy_salt_pepper_filtered_1.3.raw";
	FILE* output_file_salt_pepper13;
	unsigned char* salt13 = new unsigned char[size];
	char output_img_salt_pepper20[] = "noisy_salt_pepper_filtered_2.0.raw";
	FILE* output_file_salt_pepper20;
	unsigned char* salt20 = new unsigned char[size];

	//0.8
	gaussion(img_gaussian, gaussian08, width, height, 0.8);
	output_file_gaussian08 = fopen(output_img_gaussian08, "wb");
	fwrite(gaussian08, 1, size, output_file_gaussian08);
	delete[] gaussian08;
	fclose(output_file_gaussian08);

	gaussion(img_salt, salt08, width, height, 0.8);
	output_file_salt_pepper08 = fopen(output_img_salt_pepper08, "wb");
	fwrite(salt08, 1, size, output_file_salt_pepper08);
	delete[] salt08;
	fclose(output_file_salt_pepper08);

	//1.3
	gaussion(img_gaussian, gaussian13, width, height, 1.3);
	output_file_gaussian13 = fopen(output_img_gaussian13, "wb");
	fwrite(gaussian13, 1, size, output_file_gaussian13);
	delete[] gaussian13;
	fclose(output_file_gaussian13);

	gaussion(img_salt, salt13, width, height, 1.3);
	output_file_salt_pepper13 = fopen(output_img_salt_pepper13, "wb");
	fwrite(salt13, 1, size, output_file_salt_pepper13);
	delete[] salt13;
	fclose(output_file_salt_pepper13);

	//2.0
	gaussion(img_gaussian, gaussian20, width, height, 2.0);
	output_file_gaussian20 = fopen(output_img_gaussian20, "wb");
	fwrite(gaussian20, 1, size, output_file_gaussian20);
	delete[] gaussian20;
	fclose(output_file_gaussian20);

	gaussion(img_salt, salt20, width, height, 2.0);
	output_file_salt_pepper20 = fopen(output_img_salt_pepper20, "wb");
	fwrite(salt20, 1, size, output_file_salt_pepper20);
	delete[] salt20;
	fclose(output_file_salt_pepper20);


	delete[] img_gaussian;
	fclose(input_file_gaussian);
	delete[] img_salt;
	fclose(input_file_salt_pepper);
}


	//	8, 5, 4, 5, 8,
	//	5, 2, 1, 2, 5,
	//	4, 1, 0, 1, 4,
	//	5, 2, 1, 2, 5,
	//	8, 5, 4, 5, 8
