#include "Header.h"

void hw4_1() {
	//dark
	char input_image_man[] = "600x400_dark.raw";
	FILE* input_file_dark;
	int width = 600;
	int height = 400;
	int size = width * height;
	unsigned char* img_dark = new unsigned char[size];
	char output_img_dark7[] = "hw4_1_dark7.raw";
	FILE* output_file_dark7;
	unsigned char* output_dark7 = new unsigned char[size];
	char output_img_dark15[] = "hw4_1_dark15.raw";
	FILE* output_file_dark15;
	unsigned char* output_dark15 = new unsigned char[size];

	input_file_dark = fopen(input_image_man, "rb");
	if (input_file_dark == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_dark, 1, size, input_file_dark);

	local_histo(img_dark, output_dark7, width, height, 7);
	local_histo(img_dark, output_dark15, width, height, 15);
	
	double pdf_dark[256] = { 0 };
	double pdf_dark7[256] = { 0 };
	double pdf_dark15[256] = { 0 };
	cv::Scalar color(255, 0, 0);


	for (int v = 0; v < 256; v++) {
		double count = 0.0;
		for (int i = 0; i < size; i++) {
			if (img_dark[i] == v) {
				count++;
			}
		}
		pdf_dark[v] = count / size;
	}
	cv::Mat histo_dark = cv::Mat(300, 300, CV_8UC3, cv::Scalar(255, 255, 255));

	cv::Point startPoint1(22, 290 - 0);    // 起點座標
	cv::Point endPoint1(300 - 22, 290);    // 終點座標
	cv::line(histo_dark, startPoint1, endPoint1, (0, 0, 0), 2);

	for (int i = 0; i < 256; i++) {
		cv::Point startPoint(i + 22, 290 - 0);    // 起點座標
		cv::Point endPoint(i + 22, 290 - pdf_dark[i] * 256 *10);    // 終點座標
		cv::line(histo_dark, startPoint, endPoint, color, 1);
	}
	cv::imwrite("hw#3_1_histo_dark.jpg", histo_dark);

	for (int v = 0; v < 256; v++) {
		double count = 0.0;
		for (int i = 0; i < size; i++) {
			if (output_dark7[i] == v) {
				count++;
			}
		}
		pdf_dark7[v] = count / size;
	}
	cv::Mat histo_dark7 = cv::Mat(300, 300, CV_8UC3, cv::Scalar(255, 255, 255));

	cv::Point startPoint2(22, 290 - 0);    // 起點座標
	cv::Point endPoint2(300 - 22, 290);    // 終點座標
	cv::line(histo_dark7, startPoint2, endPoint2, (0, 0, 0), 2);

	for (int i = 0; i < 256; i++) {
		cv::Point startPoint(i + 22, 290 - 0);    // 起點座標
		cv::Point endPoint(i + 22, 290 - pdf_dark7[i] * 256 * 10);    // 終點座標
		cv::line(histo_dark7, startPoint, endPoint, color, 1);
	}
	cv::imwrite("hw#3_1_histo_dark7x7.jpg", histo_dark7);

	for (int v = 0; v < 256; v++) {
		double count = 0.0;
		for (int i = 0; i < size; i++) {
			if (output_dark15[i] == v) {
				count++;
			}
		}
		pdf_dark15[v] = count / size;
	}
	cv::Mat histo_dark15 = cv::Mat(300, 300, CV_8UC3, cv::Scalar(255, 255, 255));
	cv::Point startPoint3(22, 290 - 0);    // 起點座標
	cv::Point endPoint3(300 - 22, 290);    // 終點座標
	cv::line(histo_dark15, startPoint3, endPoint3, (0, 0, 0), 2);

	for (int i = 0; i < 256; i++) {
		cv::Point startPoint(i + 22, 290 - 0);    // 起點座標
		cv::Point endPoint(i + 22, 290 - pdf_dark15[i] * 256 * 10);    // 終點座標
		cv::line(histo_dark15, startPoint, endPoint, color, 1);
	}
	cv::imwrite("hw#3_1_histo_dark15x15.jpg", histo_dark15);

	output_file_dark7 = fopen(output_img_dark7, "wb");
	fwrite(output_dark7, 1, size, output_file_dark7);
	delete[] output_dark7;
	fclose(output_file_dark7);
	output_file_dark15 = fopen(output_img_dark15, "wb");
	fwrite(output_dark15, 1, size, output_file_dark15);
	delete[] output_dark15;
	fclose(output_file_dark15);
	delete[] img_dark;
	fclose(input_file_dark);

	//light
	char input_image_light[] = "600x400_light.raw";
	FILE* input_file_light;
	unsigned char* img_light = new unsigned char[size];
	char output_img_light7[] = "hw4_1_light7.raw";
	FILE* output_file_light7;
	unsigned char* output_light7 = new unsigned char[size];
	char output_img_light15[] = "hw4_1_light15.raw";
	FILE* output_file_light15;
	unsigned char* output_light15 = new unsigned char[size];

	input_file_light = fopen(input_image_light, "rb");
	if (input_file_light == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_light, 1, size, input_file_light);

	local_histo(img_light, output_light7, width, height, 7);
	local_histo(img_light, output_light15, width, height, 15);

	//畫直方圖
	double pdf_light[256] = { 0 };
	double pdf_light7[256] = { 0 };
	double pdf_light15[256] = { 0 };

	for (int v = 0; v < 256; v++) {
		double count = 0.0;
		for (int i = 0; i < size; i++) {
			if (img_light[i] == v) {
				count++;
			}
		}
		pdf_light[v] = count / size;
	}
	cv::Mat histo_light = cv::Mat(300, 300, CV_8UC3, cv::Scalar(255, 255, 255));

	cv::Point startPoint4(22, 290 - 0);    // 起點座標
	cv::Point endPoint4(300 - 22, 290);    // 終點座標
	cv::line(histo_light, startPoint4, endPoint4, (0, 0, 0), 2);

	for (int i = 0; i < 256; i++) {
		cv::Point startPoint(i + 22, 290 - 0);    // 起點座標
		cv::Point endPoint(i + 22, 290 - pdf_light[i] * 256 * 10);    // 終點座標
		cv::line(histo_light, startPoint, endPoint, color, 1);
	}
	cv::imwrite("hw#3_1_histo_light.jpg", histo_light);

	for (int v = 0; v < 256; v++) {
		double count = 0.0;
		for (int i = 0; i < size; i++) {
			if (output_light7[i] == v) {
				count++;
			}
		}
		pdf_light7[v] = count / size;
	}
	cv::Mat histo_light7 = cv::Mat(300, 300, CV_8UC3, cv::Scalar(255, 255, 255));

	cv::Point startPoint5(22, 290 - 0);    // 起點座標
	cv::Point endPoint5(300 - 22, 290);    // 終點座標
	cv::line(histo_light7, startPoint5, endPoint5, (0, 0, 0), 2);

	for (int i = 0; i < 256; i++) {
		cv::Point startPoint(i + 22, 290 - 0);    // 起點座標
		cv::Point endPoint(i + 22, 290 - pdf_light7[i] * 256 * 10);    // 終點座標
		cv::line(histo_light7, startPoint, endPoint, color, 1);
	}
	cv::imwrite("hw#3_1_histo_light7x7.jpg", histo_light7);

	for (int v = 0; v < 256; v++) {
		double count = 0.0;
		for (int i = 0; i < size; i++) {
			if (output_light15[i] == v) {
				count++;
			}
		}
		pdf_light15[v] = count / size;
	}
	cv::Mat histo_light15 = cv::Mat(300, 300, CV_8UC3, cv::Scalar(255, 255, 255));

	cv::Point startPoint6(22, 290 - 0);    // 起點座標
	cv::Point endPoint6(300 - 22, 290);    // 終點座標
	cv::line(histo_light15, startPoint6, endPoint6, (0, 0, 0), 2);

	for (int i = 0; i < 256; i++) {
		cv::Point startPoint(i + 22, 290 - 0);    // 起點座標
		cv::Point endPoint(i + 22, 290 - pdf_light15[i] * 256 * 10);    // 終點座標
		cv::line(histo_light15, startPoint, endPoint, color, 1);
	}
	cv::imwrite("hw#3_1_histo_light15x15.jpg", histo_light15);

	output_file_light7 = fopen(output_img_light7, "wb");
	fwrite(output_light7, 1, size, output_file_light7);
	delete[] output_light7;
	fclose(output_file_light7);
	output_file_light15 = fopen(output_img_light15, "wb");
	fwrite(output_light15, 1, size, output_file_light15);
	delete[] output_light15;
	fclose(output_file_light15);
	delete[] img_light;
	fclose(input_file_light);
}