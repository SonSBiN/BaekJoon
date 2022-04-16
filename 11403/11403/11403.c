#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void init_array(int my_array[101][101]) {
	for (int j = 0; j <= 100; j++) {
		for (int i = 0; i <= 100; i++) {
			my_array[j][i] = 0;
		}
	}
}

void search(int graph_array[101][101], int visit[101][101], int result[101][101], int num, int m, int n) {
	for (int i = 1; i <= num; i++) {
		if (i == m) {
			visit[i][i] = 1;
		}
		else {
			if (graph_array[m][i] == 1 && visit[m][i] == 0) {
				result[n][i] = 1;
				visit[m][i] = 1;
				search(graph_array, visit, result, num, i, n);
			}
		}
	}
	return;
}

int main(void) {
	int num;
	int graph_array[101][101];
	int visit[101][101];
	int result[101][101];
	scanf("%d\n", &num);
	if (num < 0 || num > 100) {
		printf("정점의 갯수 범위 오류");
		return 0;
	}
	init_array(graph_array); // 배열 초기화
	init_array(visit);
	init_array(result);
	for (int j = 1; j <= num; j++) {
		for (int i = 1; i <= num; i++) {
			scanf("%d", &graph_array[j][i]);
		}
	}
	for (int i = 1; i <= num; i++) {
		search(graph_array, visit, result, num, i, i);
		init_array(visit);
	}


	for (int j = 1; j <= num; j++) {
		for (int i = 1; i <= num; i++) {
			printf("%d ", result[j][i]);
		}
		printf("\n");
	}
	return 0;
}