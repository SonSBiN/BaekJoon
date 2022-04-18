#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX_SIZE 1001
int graph[MAX_SIZE][MAX_SIZE];
int dfs_visit[MAX_SIZE];
int bfs_visit[MAX_SIZE];
int queue[MAX_SIZE];

void dfs(int v, int vertex) {
	int w;
	dfs_visit[v] = 1;
	printf("%d ", v);
	for (w = 1; w <= vertex; w++) {
		if (graph[v][w] == 1 && dfs_visit[w] == 0) {
			dfs(w, vertex);
		}
	}
}

void bfs(int v, int vertex) {
	int w;
	int front;
	int rear;
	int pop;
	front = rear = 0;
	printf("%d ", v);
	bfs_visit[v] = 1;
	queue[0] = v;
	rear++;
	while (front < rear) {
		pop = queue[front];
		front++;
		for (w = 1; w <= vertex; w++) {
			if (graph[pop][w] == 1 && bfs_visit[w] == 0) {
				printf("%d ", w);
				queue[rear] = w;
				rear++;
				bfs_visit[w] = 1;
			}
		}
	}
}

int main(void) {
	int vertex;
	int edge;
	int first_num;
	int i;
	int j;
	scanf("%d %d %d", &vertex, &edge, &first_num); // 정상적으로 입력됨
	for (int k = 0; k < vertex; k++) { // 배열 초기화
		for (int m = 0; m < vertex; m++) {
			graph[k][m] = 0;
		}
		dfs_visit[k] = 0;
		bfs_visit[k] = 0;
	}

	while (edge-- > 0) {
		scanf("%d %d", &i, &j);
		graph[i][j] = 1;
		graph[j][i] = 1;
	}
	dfs(first_num, vertex);
	printf("\n");
	bfs(first_num, vertex);
	printf("\n");

	return 0;
}