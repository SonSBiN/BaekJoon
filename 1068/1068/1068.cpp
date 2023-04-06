#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int n, delNode;
vector<int> tree[50];
int visited[50];
int parent;
int root = 0;
int cntLeaf = 0;
void dfs(int x) {
	if (visited[x]) 
		return;
	else {
		visited[x] = 1;
		bool isLeaf = true;
		for (int i = 0; i < tree[x].size(); i++) {
			int next = tree[x][i];
			if (!visited[next]) {
				dfs(next);
				isLeaf = false;
			}
		}
		if (isLeaf)
			cntLeaf++;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> parent;
		if (parent == -1) 
			root = i;
		else 
			tree[parent].push_back(i);
	}
	cin >> delNode;
	visited[delNode] = true;
	dfs(root);
	cout << cntLeaf;
	return 0;
}