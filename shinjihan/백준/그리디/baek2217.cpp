#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main() {

	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, desc);

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] * (i + 1) > max) {
			max = arr[i] * (i + 1);
		}
	}

	cout << max;

	return 0;
}