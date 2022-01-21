#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n;
	int* arr;

	cin >> n;
	arr = new int[n+1];

	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0)	arr[i] = min(arr[i], arr[i / 2] + 1);
		if (i % 3 == 0)	arr[i] = min(arr[i], arr[i / 3] + 1);
	}

	cout << arr[n];

	return 0;
}