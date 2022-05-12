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
	int P_M; // + 혹은 -로만 채널을 옮길때의 횟수
	int count;	// 버튼 누르는 횟수
	int N_count; // N의 자릿수
	int N_num; // 앞자리가 1인 N자릿수 ex)4자리 -> 1000
	int buffer;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int temp;
		scanf("%d", &temp);
		Broken[temp] = 1;
	}
	P_M = N - 100; // + - 로만 했을때 경우
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