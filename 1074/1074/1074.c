#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int count = 0;

void count_arr(int n, int c, int r) {

	//1. degenerate case
	if (n < 1) {
		printf("%d\n", count);
		return;
	}

	//2. divide % conquer
	//   ���� �� ���̽�
	if (c < pow(2,n-1) && r < pow(2,n-1)) {
		count_arr(n - 1, c, r);
	}
	//   ������ �� ���̽�
	else if (c < (pow(2, n - 1)) && r >= pow(2, n - 1)) {
		count += pow(4, n - 1);
		count_arr(n - 1, c, r - pow(2, n - 1));
	}
	//    ���� �Ʒ� ���̽�
	else if (c >= pow(2, n - 1) && r < pow(2, n - 1)) {
		count += 2 * pow(4, n - 1);
		count_arr(n - 1, c - pow(2, n - 1), r);
	}
	//    ������ �Ʒ� ���̽�
	else if (c >= pow(2, n - 1) && r >= pow(2, n - 1)) {
		count += 3 * pow(4, n - 1);
		count_arr(n - 1, c - pow(2, n - 1), r - pow(2, n - 1));
	}
	return;
}
int main(void)
{
	int n;
	int r;
	int c;
	scanf("%d %d %d", &n, &r, &c);
	count_arr(n, r, c);
	return 0;
}