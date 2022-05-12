#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int N, M;
int arr[8];
int nums[8];

int dfs(int prev, int depth) {
	depth++;
	if (depth < M) {
		for (int i = prev + 1; i < N - (M - depth); i++) {
			arr[depth - 1] = nums[i];
			dfs(i, depth);
		}
	}
	else {
		for (int i = prev + 1; i < N; i++) {
			arr[depth - 1] = nums[i];
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
	int temp;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
	}

	//Á¤·Ä
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}

	if (M == 1) {
		for (int i = 0; i < N; i++) {
			printf("%d\n", nums[i]);
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			arr[0] = nums[i];
			dfs(i, depth);
		}
	}

	return 0;
}