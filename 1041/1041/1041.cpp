#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	long long  n;
	long long ans = 0;
	cin >> n;
	int dice[6];
	int max_num = 0;
	for (int i = 0; i < 6; i++) {
		cin >> dice[i];
		max_num = max(max_num, dice[i]);
	}
	//n이 1인 경우 주어진 주사위의 가장 큰 값을 제외한 모든 값을 더한다.
	if (n == 1) {
		for (int i = 0; i < 6; i++) {
			ans += dice[i];
		}
		cout << ans - max_num;
	}
	//n이 2 이상인 경우
	// 1면만 보이는것: (n-1)(n-2)x4 + (n-2)(n-2)
	// 2면만 보이는것: (n-1)x4 + (n-2)x4
	// 3면만 보이는것: 4
	else {
		ans = 0;
		dice[0] = min(dice[0], dice[5]);
		dice[1] = min(dice[1], dice[4]);
		dice[2] = min(dice[2], dice[3]);
		sort(dice, dice + 3);
		int sum1 = dice[0];
		int sum2 = sum1 + dice[1];
		int sum3 = sum2 + dice[2];


		ans += sum3 * 4;
		ans += sum2 * (4 * (n - 2) + 4 * (n - 1));
		ans += sum1 * (4 * (n - 1) * (n - 2) + (n - 2) * (n - 2));

		cout << ans;
	}
	return 0;
}