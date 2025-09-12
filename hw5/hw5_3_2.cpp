#include "Header.h"

void hw5_3_2() {
	//setting input
	char  input_img[] = "lena256.raw";
	FILE* input_file;
	int width = 256;
	int height = 256;
	int size = width * height;
	unsigned char* img_lena = new unsigned char[size];

	input_file = fopen(input_img, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_lena, 1, size, input_file);

	char output_img[] = "hw5_3_2.raw";
	FILE* output_file;
	unsigned char* output_lena = new unsigned char[height * width];
	unsigned char* temp_8x8 = new unsigned char[8 * 8];
	unsigned char* temp = new unsigned char[8 * 8];
	vector<float> lumin_std = { 16.0, 11.0, 10.0, 16.0, 24.0, 40.0, 51.0, 61.0,
							   12.0, 12.0, 14.0, 19.0, 26.0, 58.0, 60.0, 55.0,
							   14.0, 13.0, 16.0, 24.0, 40.0, 57.0, 69.0, 56.0,
							   14.0, 17.0, 22.0, 29.0, 51.0, 87.0, 80.0, 62.0,
							   18.0, 22.0, 37.0, 56.0, 68.0,109.0,103.0, 77.0,
							   24.0, 35.0, 55.0, 64.0, 81.0,104.0,113.0, 92.0,
							   49.0, 64.0, 78.0, 87.0,103.0,121.0,120.0,101.0,
							   72.0, 92.0, 95.0, 98.0,112.0,100.0,103.0, 99.0 };

	clock_t start, end;
	start = clock();

	for (int x = 0; x < height; x += 8) {
		for (int y = 0; y < width; y += 8) {
			for (int i = 0; i < 8; ++i) {
				for (int j = 0; j < 8; ++j) {
					temp_8x8[i * 8 + j] = img_lena[(x + i) * width + (y + j)];
				}
			}

			Mat mat_input(8, 8, CV_8UC1, temp_8x8);
			mat_input.convertTo(mat_input, CV_32F);
			Mat img_processing;
			dct(mat_input, img_processing, DFT_COMPLEX_OUTPUT | DFT_SCALE);
			vector<float> spectrum;
			spectrum.assign((float*)img_processing.datastart, (float*)img_processing.dataend);

			for (int i = 0; i < 8; ++i) {
				for (int j = 0; j < 8; ++j) {
					spectrum[i * 8 + j] = round(1 * spectrum[i * 8 + j] / lumin_std[i * 8 + j]);
				}
			}

			for (int i = 0; i < 8; ++i) {
				for (int j = 0; j < 8; ++j) {
					spectrum[i * 8 + j] = round(spectrum[i * 8 + j] / 1 * lumin_std[i * 8 + j]);
				}
			}

			Mat super_spectrum(8, 8, CV_32F, spectrum.data());
			Mat mat_output;
			idct(super_spectrum, mat_output);
			mat_output.convertTo(mat_output, CV_8UC1);
			/*Mat normalizedMat;
			normalize(mat_output, normalizedMat, 0, 255, NORM_MINMAX);
			normalizedMat.convertTo(normalizedMat, CV_8UC1);*/
			memcpy(temp, mat_output.data, 8 * 8);

			for (int i = 0; i < 8; ++i) {
				for (int j = 0; j < 8; ++j) {
					output_lena[(x + i) * width + (y + j)] = temp[i * 8 + j];
				}
			}
		}
	}

	end = clock();
	double exe_time = double(end - start) / CLOCKS_PER_SEC;
	printf("execution time:%f\n", exe_time);

	//MSE PSNR
	double mse = MSE(output_lena, img_lena, width, height);
	double psnr = PSNR(mse, output_lena, height, width);
	printf("mse:%f\n", mse);
	printf("psnr:%f\n", psnr);

	//output
	output_file = fopen(output_img, "wb");
	fwrite(output_lena, 1, height * width, output_file);
	delete[] output_lena;
	fclose(output_file);

	delete[] img_lena;
	fclose(input_file);
}