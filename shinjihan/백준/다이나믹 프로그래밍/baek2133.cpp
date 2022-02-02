//타일 채우기
/*#include <iostream>

using namespace std;

int dp_sum(int* dp, int n) {

	int sum = 0;
	for (int i = 4; i <= n; i+=2) {
		sum += dp[n - i];
	}

	return sum;
}

int main() {

	int n;
	cin >> n;

	int* dp = new int[n+1];

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		if (i % 2 == 1) {
			dp[i] = 0;
		}
		else
		{
			dp[i] = 3 * dp[i - 2] + 2 * dp_sum(dp, i);
		}
	}

	cout << dp[n];

	return 0;
}*/