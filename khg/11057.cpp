#include<iostream>
using std::cin;
using std::cout;

int main() {
	int N;
	cin >> N;
	int** dp = new int* [N];
	for (int i = 0; i < N; i++) {
		dp[i] = new int[10];
	}
	for (int i = 0; i < 10; i++) {
		dp[0][i] = i + 1;
	}
	if (N > 1) {
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < 10; j++) {
				dp[i][j] = 0;
				for (int k = 0; k <= j; k++) {
					dp[i][j] += dp[i - 1][k];
					dp[i][j] %= 10007;
				}
			}
		}
		cout << dp[N - 1][9];
	}
	else
		cout << 10;



	return 0;
}