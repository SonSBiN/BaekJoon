#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[2][15];
int N;
int max = 0;



void dfs(int day, int benefit) {
	if (day > N) {
		return;
	}
	if (benefit > max)
		max = benefit;
	if (day == N)
		return;
	dfs(day + arr[0][day], benefit + arr[1][day]);
	dfs(day + 1, benefit);
}

int main(void) {
	int day = 0;
	int benefit = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arr[0][i], &arr[1][i]);
	}
	dfs(day, benefit);

	printf("%d", max);

	return 0;
}