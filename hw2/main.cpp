#include "Header.h"

int main()
{
	printf("1: 1.1.nearest anwser\n");
	printf("2: 1.1.bilinear anwser\n");
	printf("3: 1.2 anwser\n");
	printf("4: 2 anwser\n");
	printf("5: 2.3.1 anwser\n");
	printf("6: 2.3.2 anwser\n");
	printf("7: 2.3.2.test anwser\n");
	char num;
	printf("Enter the question number to select output result:");
	scanf("%c", &num);
	switch (num)
	{
	case '1': hw2_1_1_nearest();
		break;
	case '2': hw2_1_1_bilinear();
		break;
	case '3': hw2_1_2();
		break;
	case '4': hw2_2();
		break;
	case '5': hw2_3_1();
		break;
	case '6': hw2_3_2();
		break;
	case '7': hw2_3_2_test();
		break;
	default: printf("wrong number");
	}
}

