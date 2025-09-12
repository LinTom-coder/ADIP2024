#include "Header.h"

void BHPF(unsigned char* input_img, unsigned char* output_img, unsigned char* spectrum_img, int width, int height, int r, int nn) {
	/*********************img - processing - DFT*********************/
	int size = width * height;
	Mat mat_input(height, width, CV_8UC1, input_img);
	mat_input.convertTo(mat_input, CV_32F);
	Mat img_processing;
	dft(mat_input, img_processing);

	//centrelize
	vector<float> spectrum;
	spectrum.assign((float*)img_processing.datastart, (float*)img_processing.dataend);
	centrelize(spectrum, width, height);

	//HPF
	vector<float> filter(width * height);
	for (int x = 0; x < height; ++x) {
		for (int y = 0; y < width; ++y) {
			// 計算 D(u, v)
			float D_uv = sqrt(pow(x - height / 2, 2) + pow(y - width / 2, 2));

			// 套用 Butterworth 高通濾波器公式
			filter[x * width + y] = 1.0 / (1.0 + pow(r / (D_uv + 1e-6), 2 * nn));
		}
	}
	vector<float> filteredspectrum(width * height);
	for (int x = 0; x < height; ++x) {
		for (int y = 0; y < width; ++y) {
			filteredspectrum[x * width + y] = filter[x * width + y] * spectrum[x * width + y];
		}
	}

	//un-centrelize
	centrelize(filteredspectrum, width, height);
	Mat super_spectrum(height, width, CV_32F, filteredspectrum.data());

	//IDFT
	Mat mat_output;
	idft(super_spectrum, mat_output, cv::DFT_REAL_OUTPUT | cv::DFT_SCALE);
	mat_output.convertTo(mat_output, CV_8UC1); // 轉換為 8 位無符號整數類型
	memcpy(output_img, mat_output.data, width * height);

	/*********************spectrum - DFT*********************/
	Mat padded;
	int m = getOptimalDFTSize(mat_input.rows);
	int n = getOptimalDFTSize(mat_input.cols);
	copyMakeBorder(mat_input, padded, 0, m - mat_input.rows, 0, n - mat_input.cols, BORDER_CONSTANT, Scalar::all(0));
	Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
	Mat complexImage;
	merge(planes, 2, complexImage);

	dft(complexImage, complexImage);
	//Mat plane;
	split(complexImage, planes); // 分離實部和虛部
	magnitude(planes[0], planes[1], planes[0]); // 計算幅度 (√(Re² + Im²))
	Mat magnitudeImage = planes[0];

	//centrelize
	vector<float> spectrum0;
	spectrum0.assign((float*)magnitudeImage.datastart, (float*)magnitudeImage.dataend);
	centrelize(spectrum0, width, height);

	//spectrum
	vector<float> spectrum_abj(width * height);
	double max = 0;
	for (int i = 0; i < size; ++i) {
		if (spectrum[i] > max) {
			max = spectrum0[i];
		}
	}
	//printf("%f\n", max);
	double c_log = 255 / log10(max);
	for (int x = 0; x < height; ++x) {
		for (int y = 0; y < width; ++y) {
			spectrum_abj[x * width + y] = abs(spectrum0[x * width + y]);
			spectrum_abj[x * width + y] = c_log * log(spectrum_abj[x * width + y] + 1);
			spectrum_abj[x * width + y] = spectrum_abj[x * width + y] * 255 / (c_log * log(max + 1));
		}
	}

	//filter
	for (int x = 0; x < height; ++x) {
		for (int y = 0; y < width; ++y) {
			spectrum_img[x * width + y] = spectrum_abj[x * width + y] * filter[x * width + y];
		}
	}

}