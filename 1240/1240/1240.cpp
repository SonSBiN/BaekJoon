#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

struct Node {
	int idx;
	int weight;
};

vector<Node>tree[1000];
vector<int>q;
int visit[1001] = { 0, };
int qidx = -1;
int answer[1001];
int aidx = 0;


void bfs(int src, int dest, int distance) {
	if (src == dest) {
		answer[aidx] = distance;
		return;
	}
	else if (visit[src] == 1) {
		return;
	}
	else {
		visit[src] = 1;
		for (int i = 0; i < int(tree[src].size()); i++) {
			if (visit[tree[src][i].idx] == 0){
				q.push_back(tree[src][i].idx);
			}
		}
		for (int i = 0; i < int(tree[src].size()); i++) {
			if (visit[tree[src][i].idx] == 0) {
				qidx++;
				bfs(q[qidx], dest, distance + tree[src][i].weight);
			}
		}
	}
}

int main(void) {
	int n;
	int m;
	int node1;
	int node2;
	int dist;
	cin >> n >> m;
	for (int i = 0; i < n-1; i++) {
		cin >> node1 >> node2 >> dist;
		tree[node1].push_back({ node2,dist });
		tree[node2].push_back({ node1,dist });
	}
	for (int i = 0; i < m; i++) {
		int src;
		int dst;
		cin >> src >> dst;
		bfs(src, dst, 0);
		q.clear(); // q 초기화
		for (int i = 0; i < n; i++) {
			visit[i] = 0;	//visit 초기화
		}
		qidx = -1;	//q 인덱스 초기화
	}
	for (int i = 0; i < m; i++) {
		cout << answer[i] << "\n";
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