#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX_SIZE 10001
#define Max(a,b) (a > b)?a:b

int price[MAX_SIZE];
int dp[MAX_SIZE];

void buy(int n) {
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = Max(dp[i], dp[i - j] + price[j]);
		}
	}
	printf("%d\n", dp[n]);
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &price[i]);
	}
	buy(n);

	return 0;
}