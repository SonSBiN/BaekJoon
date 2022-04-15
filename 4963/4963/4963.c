#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int count;
int visit[51][51] = {0,};
int map[51][51] = {0,};
int w, h;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

void Count_i(int y, int x) {
	for (int i = 0; i < 8; i++) {
		if (x + dx[i] > 0 && x + dx[i] <= w && y + dy[i] > 0 && y + dy[i] <= h) {
			if (visit[y + dy[i]][x + dx[i]] == 0) {
				visit[y + dy[i]][x + dx[i]] = 1;
				if (map[y + dy[i]][x + dx[i]] == 1) {
					Count_i(y + dy[i], x + dx[i]);
				}
			}
		}
	}
}

void Find_i() {
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				visit[i][j] = 1;
				count++;
				Count_i(i, j);
			}
		}
	}
	return;
}



int main(void) {


	do{
		count = 0;
		scanf("%d %d", &w, &h);
		if (w != 0 || h != 0) {
			for (int i = 1; i <= w; i++) {
				for (int j = 1; j <= h; j++) {
					scanf("%d", &map[i][j]);
				}
			}
			Find_i();
			printf("count = %d\n", count);
			for (int i = 1; i <= w; i++) {
				for (int j = 1; j <= h; j++) {
					map[i][j] = 0;
					visit[i][j] = 0;
				}
			}
		}
		
	} while (w != 0 || h != 0);
	return 0;
}