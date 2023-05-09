#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20;
const int INF = 1e9;

int adj[MAX][MAX]; // ���� ���
int dist[MAX][MAX]; // �ִ� �Ÿ�
bool removed[MAX][MAX]; // ���ŵ� ����

int main() {
    int n;
    cin >> n;

    // ���� ��� �Է� �ޱ�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
            dist[i][j] = adj[i][j];
        }
    }

    // �÷��̵� �ͼ� �˰��� ����
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    cout << -1 << endl; // �ִ� ��ΰ� �������� �ʴ� ���
                    return 0;
                }
                if (dist[i][j] == dist[i][k] + dist[k][j] && i != k && j != k) {
                    removed[i][j] = true; // �ִ� ��θ� ������ ���� ǥ��
                }
            }
        }
    }

    // ����ġ�� ������ ��� �ջ�
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
