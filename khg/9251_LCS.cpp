#include<iostream>
#include<algorithm>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main() {

	string Array_A;
	string Array_B;
	cin >> Array_A >> Array_B;
	
	int m = Array_A.length();
	int n = Array_B.length();

	int** dp = new int* [m];
	for (int i = 0; i < m; i++) {
		dp[i] = new int[n+1];
		dp[i][0] = 0;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (Array_A[i] != Array_B[j]) {
				if (i == 0) {
					dp[i][j + 1] = dp[i][j];
				}
				else {
					if (dp[i][j] < dp[i - 1][j + 1]) {
						dp[i][j + 1] = dp[i - 1][j + 1];
					}
					else
						dp[i][j + 1] = dp[i][j];
				}
			}
			else {
				if (i == 0) {
					dp[i][j + 1] = 1;
				}
				else {
					dp[i][j + 1] = dp[i - 1][j] + 1;
				}
			}
		}
	}


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (Array_A[i] != Array_B[j]) {
				if (i == 0) {
					dp[i][j + 1] = dp[i][j];
				}
				else {
					if (dp[i][j] < dp[i - 1][j + 1]) {
						dp[i][j + 1] = dp[i - 1][j + 1];
					}
					else
						dp[i][j + 1] = dp[i][j];
				}
			}
			else {
				if (i == 0) {
					dp[i][j + 1] = 1;
				}
				else {
					dp[i][j + 1] = dp[i - 1][j] + 1;
				}
			}
		}
	}

	
	cout << dp[m - 1][n];

	return 0;
}