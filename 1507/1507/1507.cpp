#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20;
const int INF = 1e9;

int adj[MAX][MAX]; // 인접 행렬
int dist[MAX][MAX]; // 최단 거리
bool removed[MAX][MAX]; // 제거된 간선

int main() {
    int n;
    cin >> n;

    // 인접 행렬 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
            dist[i][j] = adj[i][j];
        }
    }

    // 플로이드 와샬 알고리즘 적용
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    cout << -1 << endl; // 최단 경로가 존재하지 않는 경우
                    return 0;
                }
                if (dist[i][j] == dist[i][k] + dist[k][j] && i != k && j != k) {
                    removed[i][j] = true; // 최단 경로를 지나는 간선 표시
                }
            }
        }
    }

    // 지나치는 간선의 비용 합산
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!removed[i][j]) {
                ans += dist[i][j];
            }
        }
    }
    cout << ans << endl;

    return 0;
}
