#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

int arr[5][5];
int count = 0;
int num;
bool check[1000000];


int dfs(int n,int num,int x, int y) {
	if (n == 5) 
	{
		if (check[num] == false) {
			check[num] = true;
			count++;
		}
		return;
	}
	if (x-1 >= 0)
		dfs(n + 1, num * 10 + arr[x - 1][y], x - 1, y);
	if (y-1 >= 0)
		dfs(n + 1, num * 10 + arr[x][y - 1], x, y - 1);
	if (y+1 < 5)
		dfs(n + 1, num * 10 + arr[x][y + 1], x, y + 1);
	if (x+1 < 5)
		dfs(n + 1, num * 10 + arr[x + 1][y], x + 1, y);
	return;
	
}


int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 5; j++)
		{
			dfs(0, arr[i][j], i, j);
		}
	}
	printf("%d\n", count);
	return 0;
}