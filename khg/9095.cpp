#include<iostream>

using std::cin;
using std::cout;
using std::endl;


int main() {
	int n;
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> n;
		int* dp = new int[n + 1];
		for (int j = 0; j < n + 1; j++)
			dp[j] = 0;
		if (n < 3)
			cout << n << endl;
		else {
			dp[0] = 1;
			dp[1] = 1;
			dp[2] = 2;
			dp[3] = 4;
			
			for (int j = 4; j < n + 1; j++) {
				dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
			}
			cout << dp[n] << endl;
		}
		
		delete[] dp;
	}
	

	return 0;
}