#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int arr[20][20];
int min = 100;

int abs(int a) {
	return a < 0 ? -1 * a : a;
}

int main(void) {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	
	
	return 0;
}