#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[5][5];
int count;

int main(void)
{
/*
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 2 1
1 1 1 1 1
*/
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	printf("%d\n", count);
	return 0;
}