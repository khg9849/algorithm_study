/*#include <iostream>

using namespace std;

int main() {

	long long int arr[101][10];

	for (int i = 1; i < 101; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 1) {
				if (j == 0) {
					arr[i][j] = 0;
				}
				else
				{
					arr[i][j] = 1;
				}
			}
			else if (j == 0) {
				arr[i][j] = arr[i - 1][j + 1];
			}
			else if (j == 9) {
				arr[i][j] = arr[i - 1][j - 1];
			}
			else
			{
				arr[i][j] = arr[i - 1][j - 1] % 1000000000 + arr[i - 1][j + 1] % 1000000000;
			}
		}
	}

	int n;
	cin >> n;
	
	
	long long int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += arr[n][i];
		sum %= 1000000000;
	}

	cout << sum;

	return 0;
}*/