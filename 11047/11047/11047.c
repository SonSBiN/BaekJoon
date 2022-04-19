#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int n, k;
	int arr[10];
	int temp;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		arr[i] = temp;
	}
	int count = 0;
	int idx = n - 1;
	while (k > 0) {
		if (k >= arr[idx]) {
			k -= arr[idx];
			count++;
		}
		else
			idx--;
	}
	printf("%d\n", count);
	return 0;
}