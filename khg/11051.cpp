#include<iostream>
using std::cin;
using std::cout;

int main() {
	int n, k;
	cin >> n >> k;
	int** dp = new int* [n+1];
	for (int i = 0; i < n+1; i++) {
		dp[i] = new int[n + 1];
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j <= i; j++) {
			if (i == j)
				dp[i][j] = 1;
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				dp[i][j] %= 10007;
			}
		}
	}

	cout << dp[n][k];
	return 0;
}