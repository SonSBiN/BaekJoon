#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[2][15];
int N;
int max = 0;

int check(int benefit) {
	if (max >= benefit)
		return max;
	else
		return benefit;
}

void dfs(int day, int benefit) {
	if (day > N) {
		max = check(benefit);
		return;
	}
	benefit += arr[1][day];
	for (int i = 0; i < N - day; i++) {
		dfs(day + arr[0][day], benefit);
	}
}

int main(void) {
	int day = 0;
	int benefit = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arr[0][i], &arr[1][i]);
	}
	for (int i = 0; i < N; i++) {
		dfs(day, benefit);
	}
	printf("%d", max);

	return 0;
}