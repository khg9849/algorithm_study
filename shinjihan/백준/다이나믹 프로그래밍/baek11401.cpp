/*#include <iostream>
#define mod 10007

using namespace std;

int main() {

	int n, k;

	cin >> n >> k;

	long long int** arr;

	arr = new long long int* [n + 1];
	for (int i = 0; i < n + 1; i++) {
		arr[i] = new long long int[k + 1];
	}

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < k + 1; j++) {
			if (i - j < 0) {
				arr[i][j] = 0;
			}
			else if (j == 0) {
				arr[i][j] = 1;
			}
			else if (i - j == 0) {
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1])%mod;
			}
		}
	}

	cout << arr[n][k];

	return 0;
}*/