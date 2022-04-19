#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define Max_node 20001
#define INF 987654321

int V, E;

vector<pair<int, int>> a[Max_node];

vector<int> Dijkstra(int start, int vertex)
{
    vector<int> d(vertex, INF);
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    d[start] = 0;
    while (!pq.empty()) {
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if (d[current] < distance)continue;
        for (int i = 0; i < a[current].size(); ++i) {
            int next = a[current][i].first;
            int nextDistance = a[current][i].second + distance;
            if (d[next] > nextDistance) {
                d[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
    return d;
}

int main()
{
    int start;
    cin >> V >> E >> start;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back(make_pair(v, w));
    }
    V++;
    vector<int>dist = Dijkstra(start, V);

    for (int i = 1; i < V; ++i) {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
    return 0;
}
