#include<iostream>
using std::cin;
using std::cout;
#define DIV 10007


int main() {
	int n;
	cin >> n;
	
	int* dp;
	if (n < 3) 
		dp = new int[3];
	else
		dp = new int[n + 1];

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++) {
		switch (i % 2) {
		case 0:
			dp[i] = dp[i - 1] * 2 + 1;
			dp[i] %= DIV;
			break;
		case 1:
			dp[i] = dp[i - 1] * 2 - 1;
			dp[i] %= DIV;
		}
	}
	cout << dp[n];

}