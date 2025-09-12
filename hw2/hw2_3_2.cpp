#include "Header.h"
#define width 24
#define height 24
#define start_x 1
#define start_y 12
#define end_x 1
#define end_y 12


void hw2_3_2() {
	char input_img[] = "ball24x24.raw";
	FILE* input_file;
	int size = width * height;
	unsigned char* img_ball = new unsigned char[size];

	char output_img[] = "hw2_3_2_d4.raw";
	FILE* output_file;
	unsigned char* img_d4 = new unsigned char[size];

	input_file = fopen(input_img, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_ball, 1, size, input_file);

	//題目 D4
	memcpy(img_d4, img_ball, size * sizeof(unsigned char));
	img_d4[start_x * width + start_y] = 255;
	int go = 0;
	int x = start_x; 
	int y = start_y;
	LARGE_INTEGER frequency;        // 保存时钟频率
	LARGE_INTEGER start, end;       // 保存开始时间和结束时间
	double elapsed_time;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	do {
		//printf("%d\n", go);
		if ( (img_d4[(x + 1) * width + y] == 0 || img_d4[(x + 1) * width + y] == 52) && x + 1 < height) {
			img_d4[(x + 1) * width + y] = 255;
			x = x + 1;
			go += 1;
		}
		else if ( (img_d4[x * width + (y + 1)] == 0 || img_d4[x * width + (y + 1)] == 52) && y + 1 < width) {
			img_d4[x * width + (y + 1)] = 255;
			y = y + 1;
			go += 1;
		}
		else if ( (img_d4[x * width + (y - 1)] == 0 || img_d4[x * width + (y - 1)] == 52) && y - 1 >= 0) {
			img_d4[x * width + (y - 1)] = 255;
			y = y - 1;
			go += 1;
		}
		else if ( (img_d4[(x - 1) * width + y] == 0 || img_d4[(x - 1) * width + y] == 52) && x - 1 >= 0) {
			img_d4[(x - 1) * width + y] = 255;
			x = x - 1;
			go += 1;
		}
		else {
			break;
		}
	} while (go<=50);

	do {
		//printf("%d\n", go);
		if ((img_d4[(x - 1) * width + y] == 0 || img_d4[(x - 1) * width + y] == 52) && x - 1 >= 0) {
			img_d4[(x - 1) * width + y] = 255;
			x = x - 1;
			go += 1;
		}
		else if ((img_d4[(x + 1) * width + y] == 0 || img_d4[(x + 1) * width + y] == 52) && x + 1 < height) {
			img_d4[(x + 1) * width + y] = 255;
			x = x + 1;
			go += 1;
		}
		else if ((img_d4[x * width + (y + 1)] == 0 || img_d4[x * width + (y + 1)] == 52) && y + 1 < width) {
			img_d4[x * width + (y + 1)] = 255;
			y = y + 1;
			go += 1;
		}
		else if ((img_d4[x * width + (y - 1)] == 0 || img_d4[x * width + (y - 1)] == 52) && y - 1 >= 0) {
			img_d4[x * width + (y - 1)] = 255;
			y = y - 1;
			go += 1;
		}
		else {
			break;
		}
	} while (go <= 70);
	QueryPerformanceCounter(&end);
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	printf("D4 complete in %f seconds.\n", elapsed_time);

	//Dm
	char output_img_dm[] = "hw2_3_2_dm.raw";
	FILE* output_file_dm;
	unsigned char* img_dm = new unsigned char[size];

	memcpy(img_dm, img_ball, size * sizeof(unsigned char));
	img_dm[start_x * width + start_y] = 255;
	go = 0;
	x = start_x;
	y = start_y;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	do {
		//printf("%d\n", go);
		if ((img_dm[(x + 1) * width + y] == 0 || img_dm[(x + 1) * width + y] == 52) && x + 1 < height) {
			img_dm[(x + 1) * width + y] = 255;
			x = x + 1;
			go += 1;
		}
		else if ((img_dm[x * width + (y + 1)] == 0 || img_dm[x * width + (y + 1)] == 52) && y + 1 < width) {
			img_dm[x * width + (y + 1)] = 255;
			y = y + 1;
			go += 1;
		}
		else if ((img_dm[x * width + (y - 1)] == 0 || img_dm[x * width + (y - 1)] == 52) && y - 1 >= 0) {
			img_dm[x * width + (y - 1)] = 255;
			y = y - 1;
			go += 1;
		}
		else if ((img_dm[(x - 1) * width + y] == 0 || img_dm[(x - 1) * width + y] == 52) && x - 1 >= 0) {
			img_dm[(x - 1) * width + y] = 255;
			x = x - 1;
			go += 1;
		}
		else if ((img_dm[(x - 1) * width + (y - 1)] == 0 || img_dm[(x - 1) * width + (y - 1)] == 52) && x - 1 >= 0) {
			img_dm[(x - 1) * width + (y - 1)] = 255;
			x = x - 1;
			y = y - 1;
			go += 1;
		}
		else if ((img_dm[(x + 1) * width + (y - 1)] == 0 || img_dm[(x + 1) * width + (y - 1)] == 52) && x - 1 >= 0) {
			img_dm[(x + 1) * width + (y - 1)] = 255;
			x = x + 1;
			y = y - 1;
			go += 1;
		}
		else if ((img_dm[(x + 1) * width + (y + 1)] == 0 || img_dm[(x + 1) * width + (y + 1)] == 52) && x - 1 >= 0) {
			img_dm[(x + 1) * width + (y + 1)] = 255;
			x = x + 1;
			y += 1;
			go += 1;
		}
		else if ((img_dm[(x - 1) * width + (y + 1)] == 0 || img_dm[(x - 1) * width + (y + 1)] == 52) && x - 1 >= 0) {
			img_d4[(x - 1) * width + (y + 1)] = 255;
			x = x - 1;
			y += 1;
			go += 1;
		}
		else {
			break;
		}
	} while (go <= 19);

	do {
		//printf("%d\n", go);
		if ((img_dm[x * width + (y - 1)] == 0 || img_dm[x * width + (y - 1)] == 52) && y - 1 >= 0) {
			img_dm[x * width + (y - 1)] = 255;
			y = y - 1;
			go += 1;
		}
		else if ((img_dm[(x - 1) * width + (y - 1)] == 0 || img_dm[(x - 1) * width + (y - 1)] == 52) && x - 1 >= 0) {
			img_dm[(x - 1) * width + (y - 1)] = 255;
			x = x - 1;
			y = y - 1;
			go += 1;
		}
		else if ((img_dm[(x + 1) * width + (y - 1)] == 0 || img_dm[(x + 1) * width + (y - 1)] == 52) && x - 1 >= 0) {
			img_dm[(x + 1) * width + (y - 1)] = 255;
			x = x + 1;
			y = y - 1;
			go += 1;
		}
		else if ((img_dm[(x + 1) * width + y] == 0 || img_dm[(x + 1) * width + y] == 52) && x + 1 < height) {
			img_dm[(x + 1) * width + y] = 255;
			x = x + 1;
			go += 1;
		}
		else if ((img_dm[x * width + (y + 1)] == 0 || img_dm[x * width + (y + 1)] == 52) && y + 1 < width) {
			img_dm[x * width + (y + 1)] = 255;
			y = y + 1;
			go += 1;
		}
		else if ((img_dm[(x - 1) * width + y] == 0 || img_dm[(x - 1) * width + y] == 52) && x - 1 >= 0) {
			img_dm[(x - 1) * width + y] = 255;
			x = x - 1;
			go += 1;
		}
		else if ((img_dm[(x + 1) * width + (y + 1)] == 0 || img_dm[(x + 1) * width + (y + 1)] == 52) && x - 1 >= 0) {
			img_dm[(x + 1) * width + (y + 1)] = 255;
			x = x + 1;
			y += 1;
			go += 1;
		}
		else if ((img_dm[(x - 1) * width + (y + 1)] == 0 || img_dm[(x - 1) * width + (y + 1)] == 52) && x - 1 >= 0) {
			img_d4[(x - 1) * width + (y + 1)] = 255;
			x = x - 1;
			y += 1;
			go += 1;
		}
		else {
			break;
		}
	} while (go <= 36);

	do {
		//printf("%d\n", go);
		if ((img_dm[(x - 1) * width + y] == 0 || img_dm[(x - 1) * width + y] == 52) && x - 1 >= 0) {
			img_dm[(x - 1) * width + y] = 255;
			x = x - 1;
			go += 1;
		}
		else if ((img_dm[(x + 1) * width + y] == 0 || img_dm[(x + 1) * width + y] == 52) && x + 1 < height) {
			img_dm[(x + 1) * width + y] = 255;
			x = x + 1;
			go += 1;
		}
		else if ((img_dm[x * width + (y + 1)] == 0 || img_dm[x * width + (y + 1)] == 52) && y + 1 < width) {
			img_dm[x * width + (y + 1)] = 255;
			y = y + 1;
			go += 1;
		}
		else if ((img_dm[x * width + (y - 1)] == 0 || img_dm[x * width + (y - 1)] == 52) && y - 1 >= 0) {
			img_dm[x * width + (y - 1)] = 255;
			y = y - 1;
			go += 1;
		}
		else if ((img_dm[(x - 1) * width + y] == 0 || img_dm[(x - 1) * width + y] == 52) && x - 1 >= 0) {
			img_dm[(x - 1) * width + y] = 255;
			x = x - 1;
			go += 1;
		}
		else if ((img_dm[(x - 1) * width + (y - 1)] == 0 || img_dm[(x - 1) * width + (y - 1)] == 52) && x - 1 >= 0) {
			img_dm[(x - 1) * width + (y - 1)] = 255;
			x = x - 1;
			y = y - 1;
			go += 1;
		}
		else if ((img_dm[(x + 1) * width + (y - 1)] == 0 || img_dm[(x + 1) * width + (y - 1)] == 52) && x - 1 >= 0) {
			img_dm[(x + 1) * width + (y - 1)] = 255;
			x = x + 1;
			y = y - 1;
			go += 1;
		}
		else if ((img_dm[(x + 1) * width + (y + 1)] == 0 || img_dm[(x + 1) * width + (y + 1)] == 52) && x - 1 >= 0) {
			img_dm[(x + 1) * width + (y + 1)] = 255;
			x = x + 1;
			y += 1;
			go += 1;
		}
		else if ((img_dm[(x - 1) * width + (y + 1)] == 0 || img_dm[(x - 1) * width + (y + 1)] == 52) && x - 1 >= 0) {
			img_d4[(x - 1) * width + (y + 1)] = 255;
			x = x - 1;
			y += 1;
			go += 1;
		}
		else {
			break;
		}
	} while (go <= 56);
	QueryPerformanceCounter(&end);
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	printf("Dm complete in %f seconds.\n", elapsed_time);

	output_file = fopen(output_img, "wb");
	fwrite(img_d4, 1, size, output_file);
	delete[] img_ball;
	fclose(output_file);

	delete[] img_d4;
	fclose(input_file);

	output_file_dm = fopen(output_img_dm, "wb");
	fwrite(img_dm, 1, size, output_file_dm);
	fclose(output_file_dm);
	delete[] img_dm;

}
