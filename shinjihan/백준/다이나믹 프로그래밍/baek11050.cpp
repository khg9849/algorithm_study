//이항계수1
/*#include <iostream>

using namespace std;

int main() {

	int n, k;

	cin >> n >> k;

	int** arr;

	arr = new int* [n+1];
	for (int i = 0; i < n+1; i++) {
		arr[i] = new int[k + 1];
	}

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < k + 1; j++) {
			if (i - j < 0) {
				arr[i][j] = 0;
			}
			else if (j == 0)	{
				arr[i][j] = 1;
			}
			else if (i - j == 0) {
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i-1][j] + arr[i - 1][j - 1];
			}
		}
	}

	return 0;
}*/