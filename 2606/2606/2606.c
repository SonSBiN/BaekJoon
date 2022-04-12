#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int vertex;
int edge;
int visit[101] = { 0, };
int graph_matrix[101][101] = { 0, };
int count = 0;

void Find_Virus(int line) {
	for (int i = 1; i <= vertex; i++) {
		if (line == i)
			i++;
		if (graph_matrix[line][i] == 1) {
			if (visit[i] == 0) {
				visit[i] = 1;
				count++;
				Find_Virus(i);
			}
		}
	}
	return;
}

int main(void) {

	scanf("%d\n%d", &vertex, &edge); // 범위 초과시 리턴

	for (int i = 1; i <= edge; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph_matrix[a][b] = 1;
		graph_matrix[b][a] = 1;
	}
	visit[1] = 1;
	Find_Virus(1);

	printf("%d\n", count);

	return 0;
}