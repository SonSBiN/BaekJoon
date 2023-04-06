#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

struct Node {
	int idx;
	int dist;
};
int V;
int maxDist;
int lastNode;
int visit[100000] = {0, };
vector<Node> tree[100000];

void dfs(int node, int dist) {
	if (visit[node]) {
		return;
	}
	if (maxDist < dist) {
		maxDist = dist;
		lastNode = node;
	}
	visit[node] = 1;
	for (int i = 0; i < int(tree[node].size()); i++) {
		int nextIdx = tree[node][i].idx;
		int nextDist = tree[node][i].dist;
		dfs(nextIdx, nextDist + dist);
	}
	return;
}

int main(void) {

	cin >> V;

	int node1;
	int node2;
	int dist;
	for (int i = 1; i <= V; i++) {
		cin >> node1;
		while (true) {
			cin >> node2;
			if (node2 == -1)
				break;
			cin >> dist;
			tree[node1].push_back({ node2,dist });
			tree[node2].push_back({ node1,dist });
		}
	}
	dfs(1, 0);
	for (int i = 0; i < 100000; i++) {
		visit[i] = 0;
	}
	maxDist = 0;
	dfs(lastNode, 0);
	cout << maxDist;

	return 0;
}