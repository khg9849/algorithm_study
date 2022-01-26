//½ºÆ¼Ä¿
#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int** arr;
	int** dp;

	while (n--) {
		int col;
		cin >> col;

		arr = new int* [2];
		dp = new int* [2];
		for (int i = 0; i < 2; i++) {
			arr[i] = new int[col];
			dp[i] = new int[col];
		}
		
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < col; j++) {
				cin >> arr[i][j];
				dp[i][j] = 0;
			}
		}

		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[0][0] + arr[1][1];
		for (int i = 2; i < col; i++) {
			dp[0][i] = arr[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = arr[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}

		cout << max(dp[0][col-1], dp[1][col-1]) << endl;
		
	}

	return 0;
}