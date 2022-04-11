#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX_SIZE 1003
int graph[MAX_SIZE][MAX_SIZE] = { -1 };
int visit[MAX_SIZE][MAX_SIZE] = { 0 };
int day[MAX_SIZE][MAX_SIZE];
int q[1001000][2]; // q[][0] == 세로, q[][1] == 가로 값
int head = 0;
int tail = 0;
int x, y;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void) {
	int m, n; // m : 가로 n : 세로

	scanf("%d %d\n", &m, &n);

	for (int i = 1; i <= n; i++) { // 그래프, 큐에 값 넣기
		for (int j = 1; j <= m; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 1) {
				q[tail][0] = i;
				q[tail][1] = j;
				tail++;
			}
		}
	}

	while (head < tail) {
		x = q[head][0];
		y = q[head][1];
		head++;
		for (int i = 0; i < 4; i++) {
			if (x + dx[i] <= n && y + dy[i] <= m && x + dx[i] >= 1 && y + dy[i] >= 1 && graph[x + dx[i]][y + dy[i]] == 0) {
				graph[x + dx[i]][y + dy[i]] = 1;
				visit[x + dx[i]][y + dy[i]] = visit[x][y] + 1;
				q[tail][0] = x + dx[i];
				q[tail][1] = y + dy[i];
				tail++;
			}
		}
	}
	int days = 0, count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (days < visit[i][j]) {
				days = visit[i][j];
			}
			if (graph[i][j] == 0)
				count = 1;
		}
	}
	if (count == 1)
		printf("-1\n");
	else
		printf("%d\n", days);
	return 0;
}