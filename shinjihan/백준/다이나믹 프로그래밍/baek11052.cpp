//카드 구매하기
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n, check;
	cin >> n;

	int* p = new int[n+1];
	int* dp = new int[n+1];

	for (int i = 1; i < n+1; i++) {
		cin >> p[i];
	}

	/*
	* dp[1] = p[1]
	* dp[2] = max( p[2], p[1]+dp[1] )
	* dp[3] = max( p[3], p[2]+dp[1], p[1]+dp[2] )
	* dp[4] = max( p[4], p[3]+dp[1], p[2]+dp[2], p[1]+dp[3]);
	*/

	int maxValue;
	dp[0] = 0;
	for (int i = 1; i < n+1; i++) {
		maxValue = p[i];
		for (int j = 1; j < i; j++) {
			maxValue = max(maxValue, p[i - j] + dp[j]);
		}
		dp[i] = maxValue;
	}

	cout << dp[n];

	return 0;
}