#include "Header.h"

void hw5_2_2() {
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

	//BLPF dm=10
	char img_BLPF101[] = "hw5_2_2_BLPF101.raw";
	FILE* file_BLPF101;
	unsigned char* lena_BLPF101 = new unsigned char[size];
	char img_BLPF_spectrum101[] = "hw5_2_2_BLPF_spectrum101.raw";
	FILE* file_BLPF_spectrum101;
	unsigned char* lena_BLPF_spectrum101 = new unsigned char[size];

	char img_BLPF102[] = "hw5_2_2_BLPF102.raw";
	FILE* file_BLPF102;
	unsigned char* lena_BLPF102 = new unsigned char[size];
	char img_BLPF_spectrum102[] = "hw5_2_2_BLPF_spectrum102.raw";
	FILE* file_BLPF_spectrum102;
	unsigned char* lena_BLPF_spectrum102 = new unsigned char[size];

	BLPF(img_lena, lena_BLPF101, lena_BLPF_spectrum101, width, height, 10, 1);
	BLPF(img_lena, lena_BLPF102, lena_BLPF_spectrum102, width, height, 10, 2);

	file_BLPF101 = fopen(img_BLPF101, "wb");
	fwrite(lena_BLPF101, 1, height * width, file_BLPF101);
	delete[] lena_BLPF101;
	fclose(file_BLPF101);
	file_BLPF_spectrum101 = fopen(img_BLPF_spectrum101, "wb");
	fwrite(lena_BLPF_spectrum101, 1, height * width, file_BLPF_spectrum101);
	delete[] lena_BLPF_spectrum101;
	fclose(file_BLPF_spectrum101);

	file_BLPF102 = fopen(img_BLPF102, "wb");
	fwrite(lena_BLPF102, 1, height * width, file_BLPF102);
	delete[] lena_BLPF102;
	fclose(file_BLPF102);
	file_BLPF_spectrum102 = fopen(img_BLPF_spectrum102, "wb");
	fwrite(lena_BLPF_spectrum102, 1, height * width, file_BLPF_spectrum102);
	delete[] lena_BLPF_spectrum102;
	fclose(file_BLPF_spectrum102);

	//BLPF dm=20
	char img_BLPF201[] = "hw5_2_2_BLPF201.raw";
	FILE* file_BLPF201;
	unsigned char* lena_BLPF201 = new unsigned char[size];
	char img_BLPF_spectrum201[] = "hw5_2_2_BLPF_spectrum201.raw";
	FILE* file_BLPF_spectrum201;
	unsigned char* lena_BLPF_spectrum201 = new unsigned char[size];

	char img_BLPF202[] = "hw5_2_2_BLPF202.raw";
	FILE* file_BLPF202;
	unsigned char* lena_BLPF202 = new unsigned char[size];
	char img_BLPF_spectrum202[] = "hw5_2_2_BLPF_spectrum202.raw";
	FILE* file_BLPF_spectrum202;
	unsigned char* lena_BLPF_spectrum202 = new unsigned char[size];

	BLPF(img_lena, lena_BLPF201, lena_BLPF_spectrum201, width, height, 20, 1);
	BLPF(img_lena, lena_BLPF202, lena_BLPF_spectrum202, width, height, 20, 2);

	file_BLPF201 = fopen(img_BLPF201, "wb");
	fwrite(lena_BLPF201, 1, height * width, file_BLPF201);
	delete[] lena_BLPF201;
	fclose(file_BLPF201);
	file_BLPF_spectrum201 = fopen(img_BLPF_spectrum201, "wb");
	fwrite(lena_BLPF_spectrum201, 1, height * width, file_BLPF_spectrum201);
	delete[] lena_BLPF_spectrum201;
	fclose(file_BLPF_spectrum201);

	file_BLPF202 = fopen(img_BLPF202, "wb");
	fwrite(lena_BLPF202, 1, height * width, file_BLPF202);
	delete[] lena_BLPF202;
	fclose(file_BLPF202);
	file_BLPF_spectrum202 = fopen(img_BLPF_spectrum202, "wb");
	fwrite(lena_BLPF_spectrum202, 1, height * width, file_BLPF_spectrum202);
	delete[] lena_BLPF_spectrum202;
	fclose(file_BLPF_spectrum202);

	//BLPF dm=50
	char img_BLPF501[] = "hw5_2_2_BLPF501.raw";
	FILE* file_BLPF501;
	unsigned char* lena_BLPF501 = new unsigned char[size];
	char img_BLPF_spectrum501[] = "hw5_2_2_BLPF_spectrum501.raw";
	FILE* file_BLPF_spectrum501;
	unsigned char* lena_BLPF_spectrum501 = new unsigned char[size];

	char img_BLPF502[] = "hw5_2_2_BLPF502.raw";
	FILE* file_BLPF502;
	unsigned char* lena_BLPF502 = new unsigned char[size];
	char img_BLPF_spectrum502[] = "hw5_2_2_BLPF_spectrum502.raw";
	FILE* file_BLPF_spectrum502;
	unsigned char* lena_BLPF_spectrum502 = new unsigned char[size];

	BLPF(img_lena, lena_BLPF501, lena_BLPF_spectrum501, width, height, 50, 1);
	BLPF(img_lena, lena_BLPF502, lena_BLPF_spectrum502, width, height, 50, 2);

	file_BLPF501 = fopen(img_BLPF501, "wb");
	fwrite(lena_BLPF501, 1, height * width, file_BLPF501);
	delete[] lena_BLPF501;
	fclose(file_BLPF501);
	file_BLPF_spectrum501 = fopen(img_BLPF_spectrum501, "wb");
	fwrite(lena_BLPF_spectrum501, 1, height * width, file_BLPF_spectrum501);
	delete[] lena_BLPF_spectrum501;
	fclose(file_BLPF_spectrum501);

	file_BLPF502 = fopen(img_BLPF502, "wb");
	fwrite(lena_BLPF502, 1, height * width, file_BLPF502);
	delete[] lena_BLPF502;
	fclose(file_BLPF502);
	file_BLPF_spectrum502 = fopen(img_BLPF_spectrum502, "wb");
	fwrite(lena_BLPF_spectrum502, 1, height * width, file_BLPF_spectrum502);
	delete[] lena_BLPF_spectrum502;
	fclose(file_BLPF_spectrum502);


	//BHPF dm=10
	char img_BHPF101[] = "hw5_2_2_BHPF101.raw";
	FILE* file_BHPF101;
	unsigned char* lena_BHPF101 = new unsigned char[size];
	char img_BHPF_spectrum101[] = "hw5_2_2_BHPF_spectrum101.raw";
	FILE* file_BHPF_spectrum101;
	unsigned char* lena_BHPF_spectrum101 = new unsigned char[size];

	char img_BHPF102[] = "hw5_2_2_BHPF102.raw";
	FILE* file_BHPF102;
	unsigned char* lena_BHPF102 = new unsigned char[size];
	char img_BHPF_spectrum102[] = "hw5_2_2_BHPF_spectrum102.raw";
	FILE* file_BHPF_spectrum102;
	unsigned char* lena_BHPF_spectrum102 = new unsigned char[size];

	BHPF(img_lena, lena_BHPF101, lena_BHPF_spectrum101, width, height, 10, 1);
	BHPF(img_lena, lena_BHPF102, lena_BHPF_spectrum102, width, height, 10, 2);

	file_BHPF101 = fopen(img_BHPF101, "wb");
	fwrite(lena_BHPF101, 1, height* width, file_BHPF101);
	delete[] lena_BHPF101;
	fclose(file_BHPF101);
	file_BHPF_spectrum101 = fopen(img_BHPF_spectrum101, "wb");
	fwrite(lena_BHPF_spectrum101, 1, height* width, file_BHPF_spectrum101);
	delete[] lena_BHPF_spectrum101;
	fclose(file_BHPF_spectrum101);

	file_BHPF102 = fopen(img_BHPF102, "wb");
	fwrite(lena_BHPF102, 1, height* width, file_BHPF102);
	delete[] lena_BHPF102;
	fclose(file_BHPF102);
	file_BHPF_spectrum102 = fopen(img_BHPF_spectrum102, "wb");
	fwrite(lena_BHPF_spectrum102, 1, height* width, file_BHPF_spectrum102);
	delete[] lena_BHPF_spectrum102;
	fclose(file_BHPF_spectrum102);

	//BHPF dm=20
	char img_BHPF201[] = "hw5_2_2_BHPF201.raw";
	FILE* file_BHPF201;
	unsigned char* lena_BHPF201 = new unsigned char[size];
	char img_BHPF_spectrum201[] = "hw5_2_2_BHPF_spectrum201.raw";
	FILE* file_BHPF_spectrum201;
	unsigned char* lena_BHPF_spectrum201 = new unsigned char[size];

	char img_BHPF202[] = "hw5_2_2_BHPF202.raw";
	FILE* file_BHPF202;
	unsigned char* lena_BHPF202 = new unsigned char[size];
	char img_BHPF_spectrum202[] = "hw5_2_2_BHPF_spectrum202.raw";
	FILE* file_BHPF_spectrum202;
	unsigned char* lena_BHPF_spectrum202 = new unsigned char[size];

	BHPF(img_lena, lena_BHPF201, lena_BHPF_spectrum201, width, height, 20, 1);
	BHPF(img_lena, lena_BHPF202, lena_BHPF_spectrum202, width, height, 20, 2);

	file_BHPF201 = fopen(img_BHPF201, "wb");
	fwrite(lena_BHPF201, 1, height* width, file_BHPF201);
	delete[] lena_BHPF201;
	fclose(file_BHPF201);
	file_BHPF_spectrum201 = fopen(img_BHPF_spectrum201, "wb");
	fwrite(lena_BHPF_spectrum201, 1, height* width, file_BHPF_spectrum201);
	delete[] lena_BHPF_spectrum201;
	fclose(file_BHPF_spectrum201);

	file_BHPF202 = fopen(img_BHPF202, "wb");
	fwrite(lena_BHPF202, 1, height* width, file_BHPF202);
	delete[] lena_BHPF202;
	fclose(file_BHPF202);
	file_BHPF_spectrum202 = fopen(img_BHPF_spectrum202, "wb");
	fwrite(lena_BHPF_spectrum202, 1, height* width, file_BHPF_spectrum202);
	delete[] lena_BHPF_spectrum202;
	fclose(file_BHPF_spectrum202);

	//BHPF dm=50
	char img_BHPF501[] = "hw5_2_2_BHPF501.raw";
	FILE* file_BHPF501;
	unsigned char* lena_BHPF501 = new unsigned char[size];
	char img_BHPF_spectrum501[] = "hw5_2_2_BHPF_spectrum501.raw";
	FILE* file_BHPF_spectrum501;
	unsigned char* lena_BHPF_spectrum501 = new unsigned char[size];

	char img_BHPF502[] = "hw5_2_2_BHPF502.raw";
	FILE* file_BHPF502;
	unsigned char* lena_BHPF502 = new unsigned char[size];
	char img_BHPF_spectrum502[] = "hw5_2_2_BHPF_spectrum502.raw";
	FILE* file_BHPF_spectrum502;
	unsigned char* lena_BHPF_spectrum502 = new unsigned char[size];

	BHPF(img_lena, lena_BHPF501, lena_BHPF_spectrum501, width, height, 50, 1);
	BHPF(img_lena, lena_BHPF502, lena_BHPF_spectrum502, width, height, 50, 2);

	file_BHPF501 = fopen(img_BHPF501, "wb");
	fwrite(lena_BHPF501, 1, height* width, file_BHPF501);
	delete[] lena_BHPF501;
	fclose(file_BHPF501);
	file_BHPF_spectrum501 = fopen(img_BHPF_spectrum501, "wb");
	fwrite(lena_BHPF_spectrum501, 1, height* width, file_BHPF_spectrum501);
	delete[] lena_BHPF_spectrum501;
	fclose(file_BHPF_spectrum501);

	file_BHPF502 = fopen(img_BHPF502, "wb");
	fwrite(lena_BHPF502, 1, height* width, file_BHPF502);
	delete[] lena_BHPF502;
	fclose(file_BHPF502);
	file_BHPF_spectrum502 = fopen(img_BHPF_spectrum502, "wb");
	fwrite(lena_BHPF_spectrum502, 1, height* width, file_BHPF_spectrum502);
	delete[] lena_BHPF_spectrum502;
	fclose(file_BHPF_spectrum502);
}