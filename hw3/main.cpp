#include "Header.h"

int main() {
	printf("1: 1.1 anwser\n");
	printf("2: 1.2 anwser\n");
	printf("3: 2.1 anwser\n");
	printf("4: 2.2 anwser\n");
	printf("5: 3.1 anwser\n");
	printf("6: 3.2 anwser\n");
	//printf("7: 2.3.2.test anwser\n");
	char num;
	printf("Enter the question number to select output result:");
	scanf("%c", &num);
	switch (num)
	{
	case '1': hw3_1_1();
		break;
	case '2': hw3_1_2();
		break;
	case '3': hw3_2_1();
		break;
	case '4': hw3_2_2();
		break;
	case '5': hw3_3_1();
		break;
	case '6': hw3_3_2();
		break;
	default: printf("wrong number");
	}
}