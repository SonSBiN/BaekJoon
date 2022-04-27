#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	int u, v, c;
	edge(int u, int v, int c) {
		this->u = u;
		this->v = v;
		this->c = c;
	}
};

int group[10001];

int find(int x) {
	if (group[x] == x) return x;
	return group[x] = find(group[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	group[y] = x;
}

int compare_edge(const edge& a, const edge& b) {
	return a.c < b.c;
}

int kruskal(vector<edge>& edges) {
	int ans = 0;
	sort(edges.begin(), edges.end(), compare_edge);
	for (int i = 0; i < edges.size(); i++) {
		if (find(edges[i].u) == find(edges[i].v)) {
			continue;
		}
		merge(edges[i].u, edges[i].v);
		ans += edges[i].c;
	}
	return ans;
}

int main() {
	int V, E;
	scanf("%d %d", &V, &E);
	vector<edge> edges;

	for (int i = 1; i <= V; i++) {
		group[i] = i;
	}

	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges.push_back(edge(a, b, c));
		edges.push_back(edge(b, a, c));
	}

	printf("%d \n", kruskal(edges));
	return 0;
}
