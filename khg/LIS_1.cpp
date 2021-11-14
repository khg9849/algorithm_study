#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {

	int N;

	cin >> N;

	int* A = new int[N+1];
	int* dp = new int[N+1];
	int max = 0;
	int min = 0;
	A[0] = 0;
	dp[0] = 1;

	for (int i = 1; i <= N; i++) {

		cin >> A[i];
		dp[i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i+1; j <= N; j++) {
			if (A[j] > A[i]) {
				if (dp[j] < dp[i] + 1) {
					dp[j] = dp[i] + 1;
					if (dp[j] > dp[max])
						max = j;
				}
			}
		}
	}
	min = max;
	for (int i = 1; i < max; i++) {
		if (A[min] > A[i])
			min = i;
	}


	cout << dp[max] << endl;
	for (int i = min; i <= max; i++) {
		cout << A[i] << " ";
	}
}