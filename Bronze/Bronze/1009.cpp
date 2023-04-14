#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int answer = a;
		if (b % 4 == 0) b = 4;
		else b %= 4;
		answer = pow(a, b);
		if (answer % 10 == 0) {
			printf("10\n");
		}
		else {
			printf("%d\n", answer % 10);
		}
	}
	return 0;
}