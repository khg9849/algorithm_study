#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {

	string A;
	string B;
	vector<char> result;
	cin >> A >> B;
	
	int m = A.length();
	int n = B.length();

	int** dp = new int* [m];
	for (int i = 0; i < m; i++) {
		dp[i] = new int[n+1];
		dp[i][0] = 0;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i] != B[j]) {
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
	
	cout << dp[m - 1][n] << endl;
	if (dp[m - 1][n] != 0) {
		int count = dp[m - 1][n];
		int i = m - 1;
		int j = n-1;
		while (count) {
			if (A[i] == B[j]) {
				result.push_back(A[i]);
				i--;
				j--;
				count--;
			}
			else {
				if (i && dp[i][j+1] == dp[i-1][j+1])
					i--;
				else
					j--;
			}
		}
		string ans(result.begin(), result.end());
		std::reverse(ans.begin(), ans.end());
		cout << ans;
	}


	return 0;
}