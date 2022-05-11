#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int E ,S ,M;
	scanf("%d %d %d", &E, &S, &M);
	int e = 1;
	int s = 1;
	int m = 1;
	int year = 1;
	while (1) {
		if (E == e && S == s && M == m) {
			break;
		}
		e++; s++; m++;
		year++;
		if (e == 16)
			e = 1;
		if (s == 29)
			s = 1;
		if (m == 20)
			m = 1;
	}
	printf("%d\n", year);


	return 0;
}