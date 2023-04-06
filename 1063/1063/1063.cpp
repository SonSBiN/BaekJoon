#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>


using namespace std;
vector<string> queue;


int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
//			  R  L  B  T  RT  LT  RB  LB
int main(void) {

	char ckx, crx;	//문자열로 받을 킹과 돌의 x좌표 변수
	int kx, ky, rx, ry;	//체스판에 넣을 킹, 돌의 좌표 변수
	int N;

	scanf("%c%d %c%d %d", &ckx, &ky, &crx, &ry, &N);

	kx = ckx - 'A';
	rx = crx - 'A';
	for (int i = 0; i < N; i++) {
		string order;
		cin >> order;
		queue.push_back(order);
	}

	for (int i = 0; i < N; i++) {
		string order = queue[i];
		int j;
		if (order == "R") {
			j = 0;
		}
		else if(order == "L") {
			j = 1;
		}
		else if (order == "B") {
			j = 2;
		}
		else if (order == "T") {
			j = 3;
		}
		else if (order == "RT") {
			j = 4;
		}
		else if (order == "LT") {
			j = 5;
		}
		else if (order == "RB") {
			j = 6;
		}
		else if (order == "LB") {
			j = 7;
		}
		else {
			printf("명령 입력 오류");
		}

		int mx = kx + dx[i];
		int my = ky + dy[i];

		if(mx < 0 || mx > 7 || my < 0 || my > 7) {
			continue;
		}
		if (mx == rx && my == ry) {
			int mrx = rx + dx[i];
			int mry = ry + dy[i];
			if (mrx < 0 || mrx > 7 || mry < 0 || mry > 7) {
				continue;
			}
			else {
				rx = mrx;
				ry = mry;
			}
		}
		kx = mx;
		ky = my;
	}
	printf("%c%d\n", 'A' + ky, kx);
	printf("%c%d", 'A' + ry, rx);

	return 0;
}