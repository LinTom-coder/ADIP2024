#include "Header.h"

void D4(unsigned char* img_d4, int width, int height, int* v, int v_size, int x, int y) {
	int go = 0;
	do {
		//printf("(%d, %d)\n", x, y);
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
	} while (x != 1 || y != 12);
}