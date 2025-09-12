#include "Header.h"

int main() {
	printf("1: 1 anwser\n");
	printf("2: 2.1 anwser\n");
	printf("3: 2.2 anwser\n");
	printf("4: 3.1 anwser\n");
	printf("5: 3.2 anwser\n");
	printf("6: 3.3 anwser\n");
	printf("7: 3.4 anwser\n");
	char num;
	printf("Enter the question number to select output result:");
	scanf("%c", &num);
	switch (num)
	{
	case '1': hw4_1();
		break;
	case '2': hw4_2_1();
		break;
	case '3': hw4_2_2();
		break;
	case '4': hw4_3_1();
		break;
	case '5': hw4_3_2();
		break;
	case '6': hw4_3_3();
		break;
	case '7': hw4_3_4();
		break;
	default: printf("wrong number");
	}
}