#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[10001];
int count;
int N, M;

void add(int i) {
	int a = 0;
	for (int k = i; k <= N+1; k++) {
		if (a > M) return;
		if (a == M) {
			count++;
			return;
		}
		if (a < M) {
			a += arr[k];
		}
	}
	
}

int main(void) {
	
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= N; i++) {
		add(i);
	}
	printf("%d", count);
	return 0;
}