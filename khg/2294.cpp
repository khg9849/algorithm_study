#include<iostream>

using std::cin;
using std::cout;


int main() {

	int n, k;
	cin >> n >> k;

	int* dp = new int[k+1];
	int* coin = new int[n];

	for (int i = 0; i <= k; i++) {
		dp[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
		if(coin[i] <= k)
			dp[coin[i]] = 1;
	}

	for (int j = 0; j <= k; j++) {
		for (int i = 0; i < n; i++) {
			
			if (j + coin[i] <= k) {
				if (dp[j+coin[i]] == 0 && dp[j]) {
					dp[j + coin[i]] = dp[j] + dp[coin[i]];
				}
				else {
					if (dp[j + coin[i]] > dp[j] + dp[coin[i]] && dp[j])
						dp[j + coin[i]] = dp[j] + dp[coin[i]];
				}
			}
		}
	}
	if (dp[k])
		cout << dp[k];
	else
		cout << -1;
	return 0;
}