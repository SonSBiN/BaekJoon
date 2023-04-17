#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node {
	int idx;
	int weight;
};

vector<Node>tree[1000];	//tree 생성

bool visit[1001];	//방문 체크
int ans[1001];	//거리 저장


void bfs(int start, int end) { // bfs로 트리 탐색

	int dist = 0;
	queue<int>q;
	q.push(start);
	visit[start] = true;
	while (!q.empty()) {
		int curr = q.front();
		int currW = ans[curr];
		q.pop();

		for (int i = 0; i < (int)tree[curr].size(); i++) {
			int next = tree[curr][i].idx;
			int nextW = tree[curr][i].weight;
			if (visit[next]) {
				continue;
			}
			ans[next] = currW + nextW;
			if (end == next) {
				goto print;
			}
			visit[next] = true;
			q.push(next);
		}
	}
print:
	cout << ans[end] << "\n";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int m;
	cin >> n >> m;

	int node1;
	int node2;
	int dist;

	for (int i = 0; i < n - 1; i++) { //트리 생성

		cin >> node1 >> node2 >> dist;
		tree[node1].push_back({ node2,dist });
		tree[node2].push_back({ node1,dist });
	}

	for (int i = 0; i < m; i++) {	//케이스 별로 bfs 실행
		for (int i = 0; i <= n; i++) {
			visit[i] = false;	//visit 초기화
			ans[i] = 0;	//answer 초기화
		}
		cin >> node1 >> node2;
		bfs(node1, node2);
	}
	return 0;
}

/*
4 2
2 1 2
4 3 2
1 4 3
3 2
1 2
*/