#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main() {

	int n;
	cin >> n;

	int* a_arr = new int[n];
	int* b_arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> a_arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b_arr[i];
	}

	sort(a_arr, a_arr + n);
	sort(b_arr, b_arr + n, desc);

	int result = 0;
	for (int i = 0; i < n; i++) {
		result += a_arr[i] * b_arr[i];
	}

	cout << result;

	return 0;
}