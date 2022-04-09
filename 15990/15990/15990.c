#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>


int count;
int sub[] = {1,2,3};

void dfs(int a,int n) {

	n -= a;
	for (int i = 0; i < 3; i++)
	{
		if (n - sub[i] >= 0 && a != sub[i])
		{
			if (n - sub[i] == 0) {
				count++;
				return;
			}
			dfs(sub[i],n);
		}
	}
}



int main(void)
{
	int t;
	int n;
	scanf("%d", &t);
	/*
	3
	4
	7
	10
	*/
	for (int i = 0; i < t; i++)
	{
		count = 0;
		scanf("%d", &n);
		for (int j = 0; j < 3; j++)
		{
			dfs(sub[j],n);
		}
		printf("%d\n", count);
	}

	return 0;
}