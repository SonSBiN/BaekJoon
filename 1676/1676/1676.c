#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {

	int N;
	int num = 0;
	int num2 = 0;
	int num3 = 0;
	int result;
	scanf("%d", &N);
	num = N / 5;
	num2 = N / 25;
	num3 = N / 125;
	result = num + num2 + num3;
	printf("%d", result);

	return 0;
}