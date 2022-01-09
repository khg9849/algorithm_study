#include<iostream>
#define INT_MAX 210000
using std::cin;
using std::cout;


int main() {

	int N;
	cin >> N;
	int* dp = new int[N+1];
	dp[0] = 0;
	for (int i = 1; i*i < N+1; i++) {
		for (int j = i*i; j < (i+1) * (i+1); j++) {
			if (j > N)
				break;
			dp[j] = INT_MAX;
			for (int k = 1; k <= i; k++) {
				if (dp[j] > dp[j - (k * k)] + 1)
					dp[j] = dp[j - (k * k)] + 1;
			}

		}
	}
	cout << dp[N];
	return 0;
}