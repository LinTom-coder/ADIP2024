#include "Header.h"

void hw6_2() {
	//whitetree450x600
	char  input_img450x600[] = "whitetree450x600.raw";
	FILE* file450x600;
	int width450 = 450;
	int height600 = 600;
	int size1 = width450 * height600;
	unsigned char* img_whitetree450x600 = new unsigned char[size1];

	file450x600 = fopen(input_img450x600, "rb");
	if (file450x600 == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_whitetree450x600, 1, size1, file450x600);

	char output_img_binary450x600[] = "hw6_2_whitetree450x600.raw";
	FILE* output_file_binary450x600;
	unsigned char* output_binary_450x600 = new unsigned char[size1];
	memset(output_binary_450x600, 0, width450 * height600 * sizeof(unsigned char));

	binary_thinning(img_whitetree450x600, output_binary_450x600, width450, height600);

	output_file_binary450x600 = fopen(output_img_binary450x600, "wb");
	fwrite(output_binary_450x600, 1, height600 * width450, output_file_binary450x600);
	delete[] output_binary_450x600;
	fclose(output_file_binary450x600);

	delete[] img_whitetree450x600;
	fclose(file450x600);

	//whitetree600x600
	char  input_img600x600[] = "whitetree600x600.raw";
	FILE* file600x600;
	int width600 = 600;
	int size2 = width600 * height600;
	unsigned char* img_whitetree600x600 = new unsigned char[size2];

	file600x600 = fopen(input_img600x600, "rb");
	if (file600x600 == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_whitetree600x600, 1, size2, file600x600);

	char output_img_binary600x600[] = "hw6_2_whitetree600x600.raw";
	FILE* output_file_binary600x600;
	unsigned char* output_binary_600x600 = new unsigned char[size2];
	memset(output_binary_600x600, 0, width600 * height600 * sizeof(unsigned char));

	binary_thinning(img_whitetree600x600, output_binary_600x600, width600, height600);

	output_file_binary600x600 = fopen(output_img_binary600x600, "wb");
	fwrite(output_binary_600x600, 1, height600 * width600, output_file_binary600x600);
	delete[] output_binary_600x600;
	fclose(output_file_binary600x600);

	delete[] img_whitetree600x600;
	fclose(file600x600);
}