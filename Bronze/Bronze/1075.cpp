#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int n, f;

	scanf("%d\n%d", &n, &f);

	n /= 100;
	n *= 100;
	for (int i = 0; i <= 100; i++) {
		if (n % f == 0) {
			break;
		}
		else {
			n += 1;
		}
	}
	if (n % 100 < 10) {
		printf("0%d", n % 100);
	}
	else {
		printf("%d", n % 100);
	}
	return 0;
}