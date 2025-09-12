#include "Header.h"

int main()
{
	printf("1: 1.2.a(1) anwser\n");
	printf("2: 1.2.a(2) anwser\n");
	printf("3: 1.2.b anwser\n");
	printf("4: 1.2.c anwser\n");
	printf("5: 1.3.a anwser\n");
	printf("6: 1.3.b anwser\n");
	printf("7: 2.b anwser\n");
	char num;
	printf("Enter the question number to select output result:");
	scanf("%c", &num);
	switch (num)
	{
	case '1' : hw1_1_2_a_1();
		break;
	case '2': hw1_1_2_a_2();
		break;
	case '3': hw1_1_2_b();
		break;
	case '4': hw1_1_2_c();
		break;
	case '5': hw1_1_3_a();
		break;
	case '6': hw1_1_3_b();
		break;
	case '7': hw1_2_b();
		break;
	default: printf("wrong number");
	}
}

