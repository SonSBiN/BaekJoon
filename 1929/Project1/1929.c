#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int m, n;
	scanf("%d %d", &m, &n);
	int arr[100000];
	for (int i = 0; i <= n; i++) {
		arr[i] = 1;
	}
	for (int i = m-1; i <= n; i++) {
		for (int k = 2; k <= i/2; k++) {
			if (i % k == 0) {
				arr[i] = 0;
			}
		}
	}
	for (int i = m + 1; i <= n; i++) {
		if (arr[i] == 1) {
			printf("%d\n", i);
		}
	}
	return 0;
}