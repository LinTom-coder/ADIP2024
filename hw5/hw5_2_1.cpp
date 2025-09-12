#include "Header.h"

void hw5_2_1() {
	char  input_img[] = "taipei800x600.raw";
	FILE* input_file;
	int width = 800;
	int height = 600;
	int size = width * height;
	unsigned char* img_lena = new unsigned char[size];

	input_file = fopen(input_img, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_lena, 1, size, input_file);

	//LPF dm=10
	char img_LPF10[] = "hw5_2_1_LPF10.raw";
	FILE* file_LPF10;
	unsigned char* lena_LPF10 = new unsigned char[size];
	char img_spectrum10[] = "hw5_2_1_spectrum10.raw";
	FILE* file_spectrum10;
	unsigned char* lena_spectrum10 = new unsigned char[size];

	LPF(img_lena, lena_LPF10, lena_spectrum10, width, height, 10);

	file_LPF10 = fopen(img_LPF10, "wb");
	fwrite(lena_LPF10, 1, height * width, file_LPF10);
	delete[] lena_LPF10;
	fclose(file_LPF10);
	file_spectrum10 = fopen(img_spectrum10, "wb");
	fwrite(lena_spectrum10, 1, height * width, file_spectrum10);
	delete[] lena_spectrum10;
	fclose(file_spectrum10);

	//LPF dm=20
	char img_LPF20[] = "hw5_2_1_LPF20.raw";
	FILE* file_LPF20;
	unsigned char* lena_LPF20 = new unsigned char[size];
	char img_spectrum20[] = "hw5_2_1_spectrum20.raw";
	FILE* file_spectrum20;
	unsigned char* lena_spectrum20 = new unsigned char[size];

	LPF(img_lena, lena_LPF20, lena_spectrum20, width, height, 20);

	file_LPF20 = fopen(img_LPF20, "wb");
	fwrite(lena_LPF20, 1, height * width, file_LPF20);
	delete[] lena_LPF20;
	fclose(file_LPF20);
	file_spectrum20 = fopen(img_spectrum20, "wb");
	fwrite(lena_spectrum20, 1, height * width, file_spectrum20);
	delete[] lena_spectrum20;
	fclose(file_spectrum20);

	//LPF dm=50
	char img_LPF50[] = "hw5_2_1_LPF50.raw";
	FILE* file_LPF50;
	unsigned char* lena_LPF50 = new unsigned char[size];
	char img_spectrum50[] = "hw5_2_1_spectrum50.raw";
	FILE* file_spectrum50;
	unsigned char* lena_spectrum50 = new unsigned char[size];

	LPF(img_lena, lena_LPF50, lena_spectrum50, width, height, 50);

	file_LPF50 = fopen(img_LPF50, "wb");
	fwrite(lena_LPF50, 1, height * width, file_LPF50);
	delete[] lena_LPF50;
	fclose(file_LPF50);
	file_spectrum50 = fopen(img_spectrum50, "wb");
	fwrite(lena_spectrum50, 1, height * width, file_spectrum50);
	delete[] lena_spectrum50;
	fclose(file_spectrum50);

	//HPF dm=10
	char img_HPF10[] = "hw5_2_1_HPF10.raw";
	FILE* file_HPF10;
	unsigned char* lena_HPF10 = new unsigned char[size];
	char img_HPF_spectrum10[] = "hw5_2_1_HPF_spectrum10.raw";
	FILE* file_HPF_spectrum10;
	unsigned char* lena_HPF_spectrum10 = new unsigned char[size];

	HPF(img_lena, lena_HPF10, lena_HPF_spectrum10, width, height, 10);

	file_HPF10 = fopen(img_HPF10, "wb");
	fwrite(lena_HPF10, 1, height * width, file_HPF10);
	delete[] lena_HPF10;
	fclose(file_HPF10);
	file_HPF_spectrum10 = fopen(img_HPF_spectrum10, "wb");
	fwrite(lena_HPF_spectrum10, 1, height * width, file_HPF_spectrum10);
	delete[] lena_HPF_spectrum10;
	fclose(file_HPF_spectrum10);

	//HPF dm=20
	char img_HPF20[] = "hw5_2_1_HPF20.raw";
	FILE* file_HPF20;
	unsigned char* lena_HPF20 = new unsigned char[size];
	char img_HPF_spectrum20[] = "hw5_2_1_HPF_spectrum20.raw";
	FILE* file_HPF_spectrum20;
	unsigned char* lena_HPF_spectrum20 = new unsigned char[size];

	HPF(img_lena, lena_HPF20, lena_HPF_spectrum20, width, height, 20);

	file_HPF20 = fopen(img_HPF20, "wb");
	fwrite(lena_HPF20, 1, height * width, file_HPF20);
	delete[] lena_HPF20;
	fclose(file_HPF20);
	file_HPF_spectrum20 = fopen(img_HPF_spectrum20, "wb");
	fwrite(lena_HPF_spectrum20, 1, height * width, file_HPF_spectrum20);
	delete[] lena_HPF_spectrum20;
	fclose(file_HPF_spectrum20);

	//HPF dm=50
	char img_HPF50[] = "hw5_2_1_HPF50.raw";
	FILE* file_HPF50;
	unsigned char* lena_HPF50 = new unsigned char[size];
	char img_HPF_spectrum50[] = "hw5_2_1_HPF_spectrum50.raw";
	FILE* file_HPF_spectrum50;
	unsigned char* lena_HPF_spectrum50 = new unsigned char[size];

	HPF(img_lena, lena_HPF50, lena_HPF_spectrum50, width, height, 50);

	file_HPF50 = fopen(img_HPF50, "wb");
	fwrite(lena_HPF50, 1, height* width, file_HPF50);
	delete[] lena_HPF50;
	fclose(file_HPF50);
	file_HPF_spectrum50 = fopen(img_HPF_spectrum50, "wb");
	fwrite(lena_HPF_spectrum50, 1, height* width, file_HPF_spectrum50);
	delete[] lena_HPF_spectrum50;
	fclose(file_HPF_spectrum50);

	delete[] img_lena;
	fclose(input_file);
}