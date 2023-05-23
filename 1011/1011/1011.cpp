#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int X, Y;
        cin >> X >> Y;

        int dist = Y - X;
        int n = sqrt(dist);

        if (dist == n * n) {
            cout << 2 * n - 1 << endl;
        }
        else if (n * n < dist && dist <= n * n + n) {
            cout << 2 * n << endl;
        }
        else {
            cout << 2 * n + 1 << endl;
        }
    }

    return 0;
}