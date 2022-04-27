#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int arr[1001];

int main(void) {
	int n;
	scanf("%d", &n);

	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}
	printf("%d\n", arr[n]);

	return 0;
}