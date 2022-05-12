#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int N, M;
int arr[8];

int dfs(int prev, int depth) {
	depth++;
	if (depth < M) {
		for (int i = prev + 1; i <= N-(M-depth); i++) {
			arr[depth - 1] = i;
			dfs(i, depth);
		}
	}
	else {
		for (int i = prev + 1; i <= N; i++) {
			arr[depth - 1] = i;
			for (int j = 0; j < M; j++) {
				printf("%d ", arr[j]);
			}
			printf("\n");
		}

	}
}

int main(void) {
	int depth = 1;
	int num = 0;

	scanf("%d %d", &N, &M);
	if (M == 1) {
		for (int i = 1; i <= N; i++) {
			printf("%d\n", i);
		}
	}
	else {
		for (int i = 1; i <= N-M+1; i++) {
			arr[0] = i;
			dfs(i, depth);
		}
	}

	return 0;
}