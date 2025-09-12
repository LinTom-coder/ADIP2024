#include "Header.h"


void hw5_1() {
	//setting input
	char  input_img[] = "lena256.raw";                 
	FILE* input_file;
	int width = 256;
	int height = 256;
	int target_width = 512;
	int target_height = 512;
	int size = width * height;
	unsigned char* img_lena = new unsigned char[size]; 

	char output_img[] = "hw5_1.raw";
	FILE* output_file;
	unsigned char* super_lena = new unsigned char[target_height * target_width];

	input_file = fopen(input_img, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_lena, 1, size, input_file);

	//DFT
	Mat mat_lena(height, width, CV_8UC1, img_lena);
	
	mat_lena.convertTo(mat_lena, CV_32F);
	//Mat planes[] = { Mat_<float>(mat_lena), Mat::zeros(mat_lena.size(), CV_32F) };
	Mat complexImage;
	//merge(planes, 2, complexImage);

	dft(mat_lena, complexImage);

	//centrelize
	/*vector<float> spectrum_temp;
	spectrum_temp.assign((float*)complexImage.datastart, (float*)complexImage.dataend);
	vector<float> spectrum = spectrum_temp;
	centrelize(spectrum, width, height);*/
	vector<float> spectrum;
	spectrum.assign((float*)complexImage.datastart, (float*)complexImage.dataend);
	centrelize(spectrum, width, height);
	
	//zero padding
	vector<float> paddedSpectrum(target_width * target_height);
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			paddedSpectrum[(i + height / 2) * target_width + (j + width / 2)] = spectrum[i * width + j];
		}
	}

	//un-centrelize
	centrelize(paddedSpectrum, target_width, target_height);
	Mat super_spectrum(target_width, target_height, CV_32F, paddedSpectrum.data());

	//IDFT
	Mat super_lena_mat;
	idft(super_spectrum, super_lena_mat, cv::DFT_REAL_OUTPUT | cv::DFT_SCALE);
	Mat normalizedMat;
	normalize(super_lena_mat, normalizedMat, 0, 255, NORM_MINMAX);
	normalizedMat.convertTo(normalizedMat, CV_8UC1); // 轉換為 8 位無符號整數類型
	memcpy(super_lena, normalizedMat.data, target_width * target_height);

	//MSE PSNR
	char  input_img_512[] = "lena512.raw";
	FILE* input_file_512;
	unsigned char* img_lena_512 = new unsigned char[target_width * target_height];
	input_file_512 = fopen(input_img_512, "rb");
	if (input_file_512 == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_lena_512, 1, target_width * target_height, input_file_512);

	double mse = MSE(super_lena,img_lena_512, target_width, target_height);
	double psnr= PSNR(mse, super_lena, target_height, target_width);
	printf("mse:%f\n", mse);
	printf("psnr:%f\n", psnr);

	//output
	output_file = fopen(output_img, "wb");
	fwrite(super_lena, 1, target_height*target_width, output_file);
	delete[] img_lena;
	delete[] super_lena;
	fclose(input_file);
	fclose(output_file);

}

void centrelize(vector<float>& spectrum, int width, int height) {
	vector<float> temp = spectrum;

	for (int x = 0; x < height / 2; ++x) {
		for (int y = 0; y < width / 2; ++y) {
			spectrum[x * width + y] = temp[(x + height / 2) * width + (y + width / 2)];
			spectrum[(x + height / 2) * width + (y + width / 2)] = temp[x * width + y];
			spectrum[x * width + (y + width / 2)] = temp[(x + height / 2) * width + y];
			spectrum[(x + height / 2) * width + y] = temp[x * width + (y + width / 2)];
		}
	}
}