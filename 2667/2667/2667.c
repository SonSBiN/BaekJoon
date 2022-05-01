#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[25][25];
int visit[25][25] = { 0, };
int count = 0;
int N;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

void bfs(int y, int x) {
	visit[y][x] = 1;
	for (int k = 0; k < 4; k++) {
		if (y + dy[k] >= 0 || x + dx[k] >= 0 || y+dy[k] < N || x+dx[k] < N) {
			
		}
		
	}
	
}

int main() {

	scanf("%d", &N);
	printf("N = %d\n", N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	bfs(0,0);

	return 0;
}