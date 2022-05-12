#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int N, M;
int arr[8];
int nums[8];

int dfs(int visit[], int depth) {
	depth++;
	if (depth == M) {
		for (int i = 0; i < N; i++) {
			if (visit[i] == 0) {
				arr[depth - 1] = nums[i];
				for (int j = 0; j < M; j++) {
					printf("%d ", arr[j]);
				}
				printf("\n");
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			int temp[8] = { 0, };
			for (int i = 0; i < N; i++) {
				temp[i] = visit[i];
			}
			if (temp[i] == 0) {
				temp[i] = 1;
				arr[depth - 1] = nums[i];
				dfs(temp, depth);
			}
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
			int visit[8] = { 0, };
			arr[0] = nums[i];
			visit[i] = 1;
			dfs(visit,depth);
		}
	}

	return 0;
}