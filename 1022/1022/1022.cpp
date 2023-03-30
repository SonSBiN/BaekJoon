#include<iostream>
#include<stdio.h>
using namespace std;

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, -1, 0, 1};
// 오 -> 위 -> 왼 -> 아래

int main() {
	int r1, c1, r2, c2;
	int darr[50][5] = { 0, };


	cin >> r1 >> c1 >> r2 >> c2;

	if (r2 - r1 > 49 || r2 - r1 < 0 || c2 - c1 > 4 || c2 - c1 < 0) {
		printf("입력 범위 오류");
		return -1;
	}
	int x = 0;
	int y = 0;
	int dir = 0;
	int count = 0;
	int fcount = 1;
	int num = 1;


	while (darr[r2 - r1][0] == 0 || darr[0][0] == 0 || darr[0][c2 - c1] == 0 || darr[r2 - r1][c2 - c1] == 0) {
		if (x >= c1 && x <= c2 && y >= r1 && y <= r2) {
			darr[y - r1][x - c1] = num;
		}
		count++;
		num++;

		y += dy[dir];
		x += dx[dir];

		if(count == fcount) {
			count = 0;
			dir = (dir + 1) % 4;
			if (dir == 0 || dir == 2) {
				fcount++;
			}
		}
	}

	int digit = 0;
	while (num) {
		num /= 10;
		digit++;
	}

	for (int i = 0; i <= (r2 - r1); i++) {
		for (int j = 0; j <= (c2 - c1); j++) {
			printf("%*d ", digit, darr[i][j]);
		}
		printf("\n");
	}
	return 0;
}