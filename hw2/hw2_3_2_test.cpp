#include "Header.h"
#define width 24
#define height 24
#define start_x 1
#define start_y 12
#define end_x 1
#define end_y 12

typedef struct {
	int x, y;
} Pair;

int path_length1 = 0;
//Pair path[width * height]; //保存路徑
Pair* path1 = (Pair*)malloc(path_length1 * sizeof(Pair));
int shortest_length1 = width * height;
Pair* shortest_path1 = (Pair*)malloc(shortest_length1 * sizeof(Pair)); //保存最短路徑
int dx1[] = { 0, 1, 0, -1 };
int dy1[] = { 1, 0, -1, 0 };
int visited1[width * height] = { 0 };

void D4(unsigned char* img, int steps, int x, int y) {

	//printf("new:(%d,%d)\n", x, y);
	//visited1[start_x * width + start_y] = 1;
	for (int i = 0; i < 4; i++) {
		int new_x = x + dx1[i];
		int new_y = y + dy1[i];
		if (new_x >= 0 && new_x < height && new_y >= 0 && new_y < width && (img[new_x * width + new_y] == 0 || img[new_x * width + new_y] == 52) &&
			!visited1[new_x * width + new_y]) {
			//img[new_x * width + new_y] = 255;
			visited1[new_x * width + new_y] = 1;
			Pair p = { new_x, new_y };
			path1[path_length1++] = p;

			if (new_x == end_x && new_y == end_y && steps <
				shortest_length1 && steps > 1) {
				shortest_length1 = steps;
				//printf("%d\n", shortest_length1);
				for (int j = 0; j < shortest_length1; j++) {
					shortest_path1[j] = path1[j]; // 保存最短路徑
				}
				Pair p = { end_x, end_y };
				shortest_path1[steps] = p; // 加入終點
				shortest_length1++;
				/*for (int j = 0; j < shortest_length1; j++) {
					Pair p = shortest_path1[j];
					printf("(%d, %d)", p.x, p.y);
				}
				printf("\n");*/
				return;
			}

			D4(img, steps + 1, new_x, new_y);
			//img[new_x * width + new_y] = (img[new_x * width + new_y] == 255) ? 0 : 52; // 還原顏色
			//printf("old:(%d,%d)\n", new_x, new_y);
			visited1[new_x * width + new_y] = 0;
			path_length1--;
		}
	}
}


void hw2_3_2_test() {
	char input_img[] = "ball24x24.raw";
	FILE* input_file;
	int size = width * height;
	unsigned char* img_ball = new unsigned char[size];

	char output_img1[] = "hw2_3_2_test.raw";
	FILE* output_file_test;
	unsigned char* img_d4 = new unsigned char[size];
	unsigned char* img_d = new unsigned char[size];

	input_file = fopen(input_img, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_ball, 1, size, input_file);

	//題目
	memcpy(img_d4, img_ball, size * sizeof(unsigned char));
	memcpy(img_d, img_ball, size * sizeof(unsigned char));

	//img_d4[start_x * width + start_y] = 255;

	D4(img_d4, 0, start_x, start_y);
	memcpy(img_d, img_ball, size * sizeof(unsigned char));


	for (int i = 0; i < shortest_length1; i++) {
		Pair p = shortest_path1[i];
		printf("(%d, %d)", p.x, p.y);
		img_d[p.x * width + p.y] = 255;
	}

	output_file_test = fopen(output_img1, "wb");
	fwrite(img_d, 1, size, output_file_test);
	delete[] img_ball;
	fclose(output_file_test);

	delete[] img_d4;
	fclose(input_file);

}