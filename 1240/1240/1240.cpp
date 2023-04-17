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

vector<Node>tree[1000];	//tree ����

bool visit[1001];	//�湮 üũ
int ans[1001];	//�Ÿ� ����


void bfs(int start, int end) { // bfs�� Ʈ�� Ž��

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

	for (int i = 0; i < n - 1; i++) { //Ʈ�� ����

		cin >> node1 >> node2 >> dist;
		tree[node1].push_back({ node2,dist });
		tree[node2].push_back({ node1,dist });
	}

	for (int i = 0; i < m; i++) {	//���̽� ���� bfs ����
		for (int i = 0; i <= n; i++) {
			visit[i] = false;	//visit �ʱ�ȭ
			ans[i] = 0;	//answer �ʱ�ȭ
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