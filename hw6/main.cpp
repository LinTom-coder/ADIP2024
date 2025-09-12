#include "Header.h"

int main() {
	printf("1: 1   anwser\n");
	printf("2: 2   anwser\n");
	//printf("3: 2.2 anwser\n");
	//printf("4: 3.1 anwser\n");
	//printf("5: 3.2 anwser\n");
	//printf("6: 3.3 anwser\n");
	//printf("7: 3.4 anwser\n");
	char num;
	printf("Enter the question number to select output result:");
	scanf("%c", &num);
	switch (num)
	{
	case '1': hw6_1();
		break;
	case '2': hw6_2();
		break;
	default: printf("wrong number\n");
	}
}