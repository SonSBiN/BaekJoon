#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[51];  // 인접 리스트
int dp[51];  // 각 사람의 하위 직원들이 소요하는 최소 시간을 저장하는 DP 테이블
int n;  // 사람 수

// dfs 탐색을 통해 각 사람의 하위 직원들이 소요하는 최소 시간을 계산한다.
void dfs(int v) {
    vector<int> costs;  // 각 하위 직원의 소요 시간을 담을 벡터
    for (int i = 0; i < adj[v].size(); i++) {
        int u = adj[v][i];
        dfs(u);
        costs.push_back(dp[u]);
    }
    sort(costs.begin(), costs.end(), greater<int>());  // 내림차순으로 정렬
    int max_time = 0;
    for (int i = 0; i < costs.size(); i++) {
        max_time = max(max_time, costs[i] + i + 1);  // 소요 시간 계산
    }
    dp[v] = max_time;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p != -1) {  // 부모가 있다면 인접 리스트에 추가
            adj[p].push_back(i);
        }
    }
    dfs(0);  // 0번 사람이 최상위 직원이므로 0부터 시작
    cout << dp[0] << endl;  // 최상위 직원의 소요 시간을 출력
    return 0;
}
