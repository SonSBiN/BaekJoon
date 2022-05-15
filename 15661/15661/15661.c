#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int arr[20][20];
int min = 100;
int visit[20];
int N;

int abs(int a) {
	return a > 0 ? a : -1 * a;
}

void C(int cur, int n) {
	if (n == N / 2) {
		int team_1 = 0;
		int team_2 = 0;
		int team_bal = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i] == 1 && visit[j] == 1) {
					team_1 += arr[i][j];
				}
				else if (visit[i] == 0 && visit[j] == 0) {
					team_2 += arr[i][j];
				}
			}
		}
		team_bal = abs(team_1 - team_2);
		if (min > team_bal)
			min = team_bal;
		return;
	}
	for (int i = cur + 1; i < N; i++) {
		visit[i] = 1;
		C(i, n + 1);
		visit[i] = 0;
	}
	return;
}

int main(void) {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		visit[i] = 1;
		C(i, 1);
		visit[i] = 0;
	}

	printf("%d\n", min);

	return 0;
}