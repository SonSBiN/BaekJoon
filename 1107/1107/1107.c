#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int Broken[10];
int buf[6];

int check(int num) {
	if (Broken[num] == 1)
		return -1;
	return 1;
}

int main(void) {
	int N, M;
	int P_M; // + Ȥ�� -�θ� ä���� �ű涧�� Ƚ��
	int count;	// ��ư ������ Ƚ��
	int N_count; // N�� �ڸ���
	int N_num; // ���ڸ��� 1�� N�ڸ��� ex)4�ڸ� -> 1000
	int buffer;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int temp;
		scanf("%d", &temp);
		Broken[temp] = 1;
	}
	P_M = N - 100; // + - �θ� ������ ���
	buffer = N;
	while ( buffer != 0) {
		buffer /= 10;
		N_count++;
	}
	N_num = pow(10, N_count);
	for (int i = 0; i < N_count; i++) {
		if (check(N / N_num)) {
			buf[i] = N/N_num;
		}
	}
	for (int i = 0; i < N_count; i++) {
		if (buf[i] )
	}

	return 0;
}