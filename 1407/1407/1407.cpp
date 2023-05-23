#include<iostream>

using namespace std;

long long f(long long x)
{
	long long ans = 0;
	long long y = 0;
	for (long long i = 1; x > 0; x -= y, i *= 2) {
		if (x % 2 == 1) {
			y = x / 2 + 1;
		}
		else 
			y = x / 2;
		ans += y * i;
	}
	return ans;
}

int main()
{
	long long a, b;
	cin >> a >> b;

	cout << f(b) - f(a - 1);
	return 0;
}
