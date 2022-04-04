#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int count = 0;

int search(int num) {
	if (num == 1) {
		return 1;
	}
	else {
		if (num - 3 >= 1) {
			search(num - 3);
			search(num - 2);
			search(num - 1);
		}
	}

}

int main(void) {
	int n;
	int count_3 = 0;
	int count_2 = 0;
	int count_1 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int test;
		scanf("%d", &test);
		count_3 = test / 3;
		count_2 = (test % 3) / 2;
		count_1 = test - (count_3 * 3 + count_2 * 2);
		count++;
		printf("count_3 = %d \ncount_2 = %d \ncount_1 = %d \n", count_3, count_2, count_1);

		
	}

	return 0;
}