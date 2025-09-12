#include "Header.h"

void hw2_3_1() {
	char input_img[] = "ball24x24.raw";
	FILE* input_file;
	int width = 24;
	int height = 24;
	int size = width * height;
	unsigned char* img_ball = new unsigned char[size];

	char output_img[] = "hw2_3_1.raw";
	FILE* output_file;
	unsigned char* img_d4 = new unsigned char[size];

	input_file = fopen(input_img, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_ball, 1, size, input_file);

	//題目
	int x = 1;
	int y = 12;
	int v[] = { 0 };
	int v_size = sizeof(v) / sizeof(v[0]);
	//int go = 0;
	memcpy(img_d4, img_ball, size * sizeof(unsigned char));
	
	LARGE_INTEGER frequency;        // 保存时钟频率
	LARGE_INTEGER start, end;       // 保存开始时间和结束时间
	double elapsed_time;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);

	D4(img_d4, width, height, v, v_size, x, y);
	
	QueryPerformanceCounter(&end);
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	printf("D4 complete in %f seconds.\n", elapsed_time);

	/*do {
		printf("(%d, %d)\n", x, y);
		img_d4[x * width + y] = 255;
		int go = 0;
		for (int i = 0; i < v_size; i++) {
			if (img_d4[x * width + (y + 1)] == v[i] && y + 1 < width) {
				img_d4[x * width + (y + 1)] = 255;
				y = y + 1;
				go += 1;
			}
			else if (img_d4[(x + 1) * width + y] == v[i] && x + 1 < height) {
				img_d4[(x + 1) * width + y] = 255;
				x = x + 1;
				go += 1;
			}
			else if (img_d4[x * width + (y - 1)] == v[i] && y - 1 >= 0) {
				img_d4[x * width + (y - 1)] = 255;
				y = y - 1;
				go += 1;
			}
			else if (img_d4[(x - 1) * width + y] == v[i] && x - 1 >= 0) {
				img_d4[(x - 1) * width + y] = 255;
				x = x - 1;
				go += 1;
			}
			else {
				break;
			}
		}
		if (go == 0) {
			break;
		}
	} while (x != 1 || y != 12);*/

	output_file = fopen(output_img, "wb");
	fwrite(img_d4, 1, size, output_file);
	delete[] img_ball;
	fclose(output_file);
	
	delete[] img_d4;
	fclose(input_file);

}