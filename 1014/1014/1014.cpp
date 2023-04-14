#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t, n, m;
char seat[11][11];
int dp[11][1 << 10][1 << 10];

// �¿� ���� �밢���� �˻��Ͽ� ���� ���� ���¿� ���� ���� ���� ���¸� ����
int check(int row, int prev, int cur, int next) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (seat[row][i] == 'x') continue;
        if (cur & (1 << i)) continue; // �̹� ���� �л��� ����
        if (prev & (1 << i)) continue; // ���� �࿡�� �»�/��� �밢�� ���⿡ ���� ���
        if (next & (1 << i)) continue; // ���� �࿡�� ����/���� �밢�� ���⿡ ���� ���
        cnt++; // ���� �� �ִ� �ڸ�
    }
    return cnt;
}

int solve(int row, int prev, int cur) {
    // ������ ����� �˻��� ���
    if (row == n) return 0;

    // �̹� ����� ���� �ִ� ���
    if (dp[row][prev][cur] != -1) return dp[row][prev][cur];

    int ans = 0;
    // ���� ���� ���¸� ���Ѵ�.
    for (int next = 0; next < (1 << m); next++) {
        // ���� ���� ���¿� ���� ���� ���� ���¸� ����
        int cnt = check(row + 1, cur, next, row < n - 1 ? dp[row + 1][cur][next] : 0);
        ans = max(ans, cnt + solve(row + 1, cur, next));
    }
    return dp[row][prev][cur] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> seat[i][j];

        // ù �࿡�� ���� ���� ���´� ��� 0���� �ʱ�ȭ
        int ans = 0;
        for (int i = 0; i < (1 << m); i++)
            ans = max(ans, check(0, 0, i, dp[0][0][i] = solve(0, 0, i)));
        cout << ans << "\n";
    }
    return 0;
}
