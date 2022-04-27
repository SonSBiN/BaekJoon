#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define min(a,b) (a < b ? a : b);
#define MAX_SIZE 1000001

int arr[MAX_SIZE];
int n;

void solution() {
	arr[0] = arr[1] = 0;
	int temp;
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 3 == 0) {
			temp = arr[i / 3] + 1;
			arr[i] = min(arr[i], temp);
		}
		if (i % 2 == 0) {
			temp = arr[i / 2] + 1;
			arr[i] = min(arr[i], temp);
		}
	}
	printf("%d\n", arr[n]);
}

int main(void) {
	scanf("%d", &n);
	solution();
	return 0;
}