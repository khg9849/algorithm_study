#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	int n;
	int* dp;


	cin >> n;

	if (n % 2 == 0)
		dp = new int[n/2+1];
	else {
		cout << 0 << endl;
		exit(0);
	}
	dp[0] = 0;
	dp[1] = 3;
	for (int i = 2; i <= n / 2; i++) {
		dp[i] = 2;
		for (int j = 1; j < i; j++) {
			
			if (j == i - 1) {
				dp[i] += dp[j] * 3;
			}
			else
				dp[i] += dp[j] * 2;
		}
	}
	cout << dp[n/2];
	return 0;
}