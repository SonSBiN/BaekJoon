#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int M, N, H;
int count = 0;

int V_X[6] = { 0,0,1,-1,0,0 };
int V_Y[6] = { 1,-1,0,0,0,0 };
int V_Z[6] = { 0,0,0,0,1,-1 };

struct node {
	int x;
	int y;
	int z;
};

int map[100][100][100] = {0};

struct node queue[1000000];
int head = 0;
int tail = 0;

struct node deque() {
	struct node temp = queue[head];
	head += 1;
	return temp;
}

void enque(int x2, int y2,int z2) {
	struct node temp;
	temp.x = x2;
	temp.y = y2;
	temp.z = z2;
	queue[tail] = temp;
	tail += 1;
}

int isQueEmpty() {
	return ((tail == head) ? 1 : 0);
}

int BFS() {
	int N_X;
	int N_Y;
	int N_Z;
	struct node temp;


	while (isQueEmpty() == 0) {
		temp = deque();
		for (int i = 0; i < 6; i++) {
			N_X = temp.x + V_X[i];
			N_Y = temp.y + V_Y[i];
			N_Z = temp.z + V_Z[i];
			if (N_X >= 0 && N_Y >= 0 && N_Z >= 0 && N_X < M && N_Y < N && N_Z < H) {
				if (map[N_X][N_Y][N_Z] == 0) {
					map[N_X][N_Y][N_Z] = map[temp.x][temp.y][temp.z] + 1;
					enque(N_X, N_Y, N_Z);
					count--;
				}
			}
		}
	}
	if (count == 0) {
		return map[temp.x][temp.y][temp.z] - 1;
	}
	return -1;
}

int main(void)
{

	scanf("%d %d %d",&M,&N,&H);

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				scanf("%d", &map[k][j][i]);
				if (map[k][j][i] == 1) {
					enque(k, j, i);
				}
				else if (map[k][j][i] == 0) {
					count++;
				}
			}
		}

	}
	printf("%d\n", BFS());

	return 0;
}