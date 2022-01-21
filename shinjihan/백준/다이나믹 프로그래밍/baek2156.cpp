/*#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n;

	cin >> n;
	int* arr = new int[n+1];
	int* result = new int[n+1];

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	result[1] = arr[1];
	result[2] = result[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		result[i] = max(arr[i] + result[i - 2], arr[i] + arr[i - 1] + result[i - 3]);
		result[i] = max(result[i], result[i - 1]);
	}

	cout << result[n];

	return 0;
}*/