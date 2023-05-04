#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[51];  // ���� ����Ʈ
int dp[51];  // �� ����� ���� �������� �ҿ��ϴ� �ּ� �ð��� �����ϴ� DP ���̺�
int n;  // ��� ��

// dfs Ž���� ���� �� ����� ���� �������� �ҿ��ϴ� �ּ� �ð��� ����Ѵ�.
void dfs(int v) {
    vector<int> costs;  // �� ���� ������ �ҿ� �ð��� ���� ����
    for (int i = 0; i < adj[v].size(); i++) {
        int u = adj[v][i];
        dfs(u);
        costs.push_back(dp[u]);
    }
    sort(costs.begin(), costs.end(), greater<int>());  // ������������ ����
    int max_time = 0;
    for (int i = 0; i < costs.size(); i++) {
        max_time = max(max_time, costs[i] + i + 1);  // �ҿ� �ð� ���
    }
    dp[v] = max_time;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p != -1) {  // �θ� �ִٸ� ���� ����Ʈ�� �߰�
            adj[p].push_back(i);
        }
    }
    dfs(0);  // 0�� ����� �ֻ��� �����̹Ƿ� 0���� ����
    cout << dp[0] << endl;  // �ֻ��� ������ �ҿ� �ð��� ���
    return 0;
}
