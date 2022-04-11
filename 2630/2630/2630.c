#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int blue = 0;
int white = 0;
int arr[128][128] = {0,};


void FindNumOfSquare(int x_min, int x_max, int y_min, int y_max) // 정사각형을 찾는 함수
{
	int x1 = x_min;
	int x2 = x_max;
	int y1 = y_min;
	int y2 = y_max;
	int mid_x = (x_min + x_max) / 2;
	int mid_y = (y_min + y_max) / 2;

	if (x1 == x2 && y1 == y2) {
		if (arr[x1][y1] == 1) {
			blue++;
			return;
		}
		else {
			white++;
			return;
		}
	}
	for (; y1 <= y2; y1++) {
		for (; x1 <= x2; x1++) {
			if (arr[x_min][y_min] != arr[x1][y1]) {
				FindNumOfSquare(x_min, mid_x, y_min, mid_y);
				FindNumOfSquare(x_min, mid_x, mid_y + 1, y_max);
				FindNumOfSquare(mid_x + 1, x_max, y_min, mid_y);
				FindNumOfSquare(mid_x + 1, x_max, mid_y + 1, y_max);
				return;
			}
		}
	}
	if (arr[x_min][y_min] == 1) {
		blue++;
		return;
	}
	else {
		white++;
		return;
	}
}
int main(void) {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	FindNumOfSquare(0, n-1, 0, n-1);
	printf("%d\n", white);
	printf("%d\n", blue);

	return 0;
}
