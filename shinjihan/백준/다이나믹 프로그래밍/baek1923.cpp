/*#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n;

	cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n+1];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n+1; j++) {
			if (j == 0 || j > i+1) {
				arr[i][j] = -1;
			}
			else {
				cin >> arr[i][j];
			}
		}
	}

	int** newArr = new int* [n];
	for (int i = 0; i < n; i++) {
		newArr[i] = new int[n + 1];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i == 0 || j == 0) {
				newArr[i][j] = arr[i][j];
			}
			else
			{
				newArr[i][j] = arr[i][j] + max(newArr[i - 1][j - 1], newArr[i - 1][j]);
			}
		}
	}

	int max = -10000;
	for (int i = 0; i < n+1; i++) {
		if (newArr[n-1][i] > max) {
			max = newArr[n-1][i];
		}
	}

	cout << max;

	return 0;
}*/