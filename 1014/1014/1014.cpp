#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t, n, m;
char seat[11][11];
int dp[11][1 << 10][1 << 10];

// 좌우 상하 대각선을 검사하여 이전 행의 상태에 따라 현재 행의 상태를 결정
int check(int row, int prev, int cur, int next) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (seat[row][i] == 'x') continue;
        if (cur & (1 << i)) continue; // 이미 앉은 학생은 제외
        if (prev & (1 << i)) continue; // 이전 행에서 좌상/우상 대각선 방향에 앉은 경우
        if (next & (1 << i)) continue; // 다음 행에서 좌하/우하 대각선 방향에 앉을 경우
        cnt++; // 앉을 수 있는 자리
    }
    return cnt;
}

int solve(int row, int prev, int cur) {
    // 마지막 행까지 검사한 경우
    if (row == n) return 0;

    // 이미 계산한 값이 있는 경우
    if (dp[row][prev][cur] != -1) return dp[row][prev][cur];

    int ans = 0;
    // 다음 행의 상태를 구한다.
    for (int next = 0; next < (1 << m); next++) {
        // 현재 행의 상태에 따라 다음 행의 상태를 결정
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

        // 첫 행에서 다음 행의 상태는 모두 0으로 초기화
        int ans = 0;
        for (int i = 0; i < (1 << m); i++)
            ans = max(ans, check(0, 0, i, dp[0][0][i] = solve(0, 0, i)));
        cout << ans << "\n";
    }
    return 0;
}
